#include "ABB.h"

struct registro{
	int chave;
	char nome[100];
	int idade;
	double salario;
};

struct no{
	reg info;
	struct no *sae;
	struct no *sad;
};

Arv * cria_arvore(){
	return NULL;
}

int arvore_vazia(Arv a){
	if(a == NULL)
		return 1;
	else 
		return 0;
}

void libera_arvore(Arv * a){
	if(arvore_vazia(*a)){
		return;
	}

	if(a != NULL){
		libera_arvore(&(*a)->sae);
		libera_arvore(&(*a)->sad);
		free(a);
	}

	a = NULL;
}

void exibe_arvore(Arv * a){ 
	if(arvore_vazia(*a))
		printf("<>\n");

	else if(a != NULL){
		printf("<%d \t", (*a)->info.chave);
		exibe_arvore(&(*a)->sae);
		exibe_arvore(&(*a)->sad);
		printf(">\n");
	}
}


//ANTES DISSO TUDO FUNCIONA

void exibe_ordenado(Arv * a){
	if(arvore_vazia(*a))
		printf("<>\n");

	else if(a != NULL){
		printf("<%d \t", (*a)->info.chave);
		exibe_ordenado(&(*a)->sae);
		printf(">\n");
		exibe_ordenado(&(*a)->sad);
	}	
}

int insere_ord(Arv * a, reg elem){  ///NAO FUNCIONA
	if(a == NULL)
		return 0;

	if(arvore_vazia(*a)){
		Arv * nova = (Arv*) malloc(sizeof(Arv));
		if(nova == NULL)
			return 0;
		(*nova)->info = elem;
		(*nova)->sad = NULL;
		(*nova)->sae = NULL;
		a = nova;
		return 1;

	}

	if((elem.chave) > ((*a)->info.chave))
		insere_ord(&(*a)->sad,elem);
	else
		insere_ord(&(*a)->sae,elem);
}
