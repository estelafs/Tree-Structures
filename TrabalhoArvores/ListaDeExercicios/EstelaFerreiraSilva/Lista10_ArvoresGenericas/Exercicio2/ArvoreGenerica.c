#include "ArvoreGenerica.h"

Arv * cria_arvore(int elem) {
	Arv * nova = (Arv*) malloc(sizeof(Arv));

	if(nova == NULL) 
		return NULL;

	nova->info = elem;
	nova->esq = NULL;
	nova->dir = NULL;

	return nova;
}

int arvore_vazia(Arv * a) {
	if(a == NULL)
		return 1;
	else
		return 0;
}

int insere_como_filha(Arv * mae, Arv * filha) {
	if(arvore_vazia(mae) || arvore_vazia(filha))
		return 0;

	filha->dir = mae->esq; //passa a ser irmão dos filhos da arvore mãe
	mae->esq = filha; //torna a arvore mae como nó raiz da arvore filha

	return 1;	
}

void exibe_arvore(Arv * a) {
	if(arvore_vazia(a))
		return;
		

	else if(a != NULL){
		printf("<%d", a->info);
		exibe_arvore(a->esq);
		printf(">");
		exibe_arvore(a->dir);
	}

}

int busca_elem(Arv * a, int elem) {
	if(arvore_vazia(a))
		return 0;

	if(a->info == elem)
		return 1;

	busca_elem(a->esq,elem);
	busca_elem(a->dir,elem);
}

void libera_arvore(Arv * a) {
	if(arvore_vazia(a))
		return;

	if(a != NULL) {
		free(a->esq);
		free(a->dir);
		free(a);
	}

	a = NULL;
}

int altura(Arv * a, int cont) {
	if(arvore_vazia(a))
		return 0;	

	if(a->esq != NULL){
		return altura(a->esq,(cont+1));
	}

	if(a->dir != NULL){
		return altura(a->dir,cont);
	}

	return cont;
}