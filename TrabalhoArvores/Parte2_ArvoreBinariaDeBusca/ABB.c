#include "ABB.h"

Arv * cria_arvore_vazia(){
	return NULL;
}

int arvore_vazia(Arv * a){
	if(a == NULL)
		return 1;
	else 
		return 0;
}

void libera_arvore(Arv * a){
	if(arvore_vazia(a)){
		return;
	}

	if(a != NULL){
		libera_arvore(a->sae);
		libera_arvore(a->sad);
		free(a);
	}

	a = NULL;
}

void exibe_arvore(Arv * a){
	if(arvore_vazia(a))
		printf("<>");

	else if(a != NULL){
		printf("<%d", a->info.chave);
		exibe_arvore(a->sae);
		exibe_arvore(a->sad);
		printf(">");
	}

}

void exibe_arvore_ordenado(Arv * a){
	if(arvore_vazia(a))
		printf("");

	else if(a != NULL){
		exibe_arvore_ordenado(a->sae);
		printf("%d ", a->info.chave);
		exibe_arvore_ordenado(a->sad);
	}	
}

reg* cria_elem(int c, char n[], int i, char cur[]) {
	reg* elem = (reg*) malloc(sizeof(reg));

	if(elem == NULL)
		return NULL;

	elem->chave = c;
	strcpy(elem->nome,n);

	elem->idade = i;
	strcpy(elem->curso,cur);
	
	return elem;
}

void exibe_registro(reg * elem) {
	printf("Chave: %d \t Nome: ", elem->chave);

	printf("%s", elem->nome);

	printf("\tIdade: %d \t Curso: %s\n ", elem->idade, elem->curso);

}


void reg_cpy(reg *a, reg *b) { 
	
	a->chave = b->chave;
	strcpy(a->nome, b->nome);	
	a->idade = b->idade;
	strcpy(a->curso, b->curso);
}


Arv * cria_arvore(Arv * esq, Arv * dir, reg *elem) {
	Arv * nova = (Arv*) malloc(sizeof(Arv));

	if(nova == NULL)
		return;

	reg_cpy(&(*nova).info,elem);

	nova->sad = dir;
	nova->sae = esq;

	return nova;

}

void insere_ordenado(Arv *pai, Arv * a, reg *elem, int n) {
	if(arvore_vazia(a)){
		Arv * raiz = cria_arvore(NULL,NULL,elem);
		if(n == 1)
			pai->sad = raiz;
		else if(n == 2)
			pai->sae = raiz;
	}

	else if((elem->chave) >= (a->info.chave)){
		insere_ordenado(a, a->sad,elem,1);
	}
	else	
		insere_ordenado(a, a->sae,elem,2);

}

//----------------------------------------------------------------------------------

int remove_ordenado(Arv * a, int elem) { //NAO FUNCIONA


	if(arvore_vazia(a))
		return 0;

	else if((a->info.chave != elem) && (a->info.chave >= elem)){
		remove_ordenado(a->sad,elem);
	}

	else if((a->info.chave != elem) && (a->info.chave < elem)){
		remove_ordenado(a->sae,elem);
	}

	else{
		if(a->sae == NULL && a->sad == NULL){
			libera_arvore(a);
			a = NULL;
		}
		else if(a->sae != NULL && a->sad == NULL){
			Arv * aux = a;
			a = a->sae;
			free(aux); 
			aux = NULL;
		}
		else if(a->sae == NULL && a->sad != NULL){
			Arv * aux = a;
			a = a->sad;
			free(aux); 
			aux = NULL;
		}
		return 1;
	}

}
