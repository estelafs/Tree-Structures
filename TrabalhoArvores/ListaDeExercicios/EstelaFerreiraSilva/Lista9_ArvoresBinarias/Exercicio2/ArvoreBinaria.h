#ifndef ARVOREBINARIA_H_INCLUDED
#define ARVOREBINARIA_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>

struct no {
	int info;
	struct  no * sae;
	struct  no * sad;

};

typedef struct no Arv;

Arv * cria_vazia();
Arv * cria_arvore(int elem, Arv * esq, Arv * dir);
int arvore_vazia(Arv * a); 
void libera_arvore(Arv * a);
int busca_elem(Arv * a, int elem);
Arv * busca_pai(Arv * a, int elem);
int altura(Arv *a);
void mostra_arvore(Arv * a);

#endif