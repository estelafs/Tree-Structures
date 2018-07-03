#include "Lista.h"

struct celula{
	int conteudo;
	struct celula *prox;
	struct celula *anterior;
};

struct lista{
	Celula *primeira;
	Celula *ultima;
};

Lista* criar_lista(){
	Lista *l = malloc(sizeof(Lista));
	l->primeira = NULL;
	l->ultima = NULL;
	return l;
}

void lista_inicia(Lista *l){
    l->primeira= NULL;
    l->ultima = NULL;
}

void inserir_no_inicio_lista(Lista * l, int i){
	Celula *c = malloc(sizeof(Celula));
	c->conteudo = i;
	c->prox = l->primeira;
	if (tamanho_lista(l) == 0)
    	l->ultima = c;
	else
    	l->primeira->anterior = c;
	l->primeira = c;
	c->anterior = NULL;
}

void inserir_no_final_lista(Lista *l, int i){
	Celula *c = malloc(sizeof(Celula));
	c->conteudo = i;
	c->prox = NULL;
	if (tamanho_lista(l) != 0){
    	c->anterior = l->ultima;
    	l->ultima->prox = c;
	}
	l->ultima = c;
	if (tamanho_lista(l) == 0){
    	l->primeira = c;
    	c->anterior = NULL;
	}
}

int tamanho_lista(Lista *l){
	Lista *resto;
	int tam;
	if (l->primeira == NULL){
    	return 0;
	}
	else{
    	resto = (Lista *) malloc(sizeof(Lista));
    	resto->primeira = l->primeira->prox;
    	tam = tamanho_lista(resto);
    	free(resto);
    	return 1 + tam;
	}
}

void remove_primeiro(Lista *l){
    if(tamanho_lista(l) == 0){
        puts("Lista vazia!\n");
        return;
    }
    else if(tamanho_lista(l)  == 1){
        Celula *aux = l->primeira;
        lista_inicia(l);
        free(aux);
    }
    else{
        Celula *aux = l->primeira;
        l->primeira->conteudo = l->primeira->prox->conteudo;
        l->primeira = l->primeira->prox;
        free(aux);
    }
}

void imprime_lista(Lista *l){
    Celula *aux = l->primeira;
    printf("\nFILA: ");
    while(aux != NULL){
        printf("%d\t", aux->conteudo);
        aux = aux->prox;
    }
}

int primeira_lista(Lista *l) {
    return l->primeira->conteudo;
}