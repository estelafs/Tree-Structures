#include "ArvoreBinaria.h"
#define max(a,b) ((a>b) ? a : b)

Arv * cria_vazia(){
	return NULL;
}

Arv * cria_arvore(int elem, Arv * esq, Arv * dir){
	Arv * nova = (Arv*) malloc(sizeof(Arv));
	
	if(nova == NULL){
		puts("Erro ou criar a arvore!");
		return NULL;
	}

	nova->info = elem;
	nova->sae = esq;
	nova->sad = dir;

	return nova;
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

int busca_elem(Arv * a, int elem){
	if(arvore_vazia(a)){
		return 0;
	}

	else if(a->info == elem){
		return 1;
	}

	busca_elem(a->sae,elem);
	busca_elem(a->sad,elem);

}

Arv * busca_pai(Arv * a, int elem){
	if(a->sae == NULL && a->sad == NULL)
		return NULL;
	else if(a->sae->info == elem || a->sad->info == elem)
		return a;
	else {
		busca_pai(a->sae,elem);
		busca_pai(a->sad,elem);
	}

}


void mostra_arvore(Arv * a){ 
	if(arvore_vazia(a))
		printf("<>");

	else if(a != NULL){
		printf("<%d", a->info);
		mostra_arvore(a->sae);
		mostra_arvore(a->sad);
		printf(">");
	}

}

int altura(Arv *a){
	if(arvore_vazia(a))
		return -1;
	return (max(altura(a->sae),altura(a->sad)) + 1); 
}
