#ifndef ARVOREGENERICA_H_INCLUDED
#define ARVOREGENERICA_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>

struct no{
	int info;
	struct no *esq; //a esquerda são filhos
	struct no *dir; //a direita são irmãos
};

typedef struct no Arv;

Arv * cria_arvore(int elem);
int arvore_vazia(Arv * a);
int insere_como_filha(Arv * mae, Arv * filha);
int existe_elem(Arv * a, int elem);
void libera_arvore(Arv * a);

void exibe_arvore(Arv * a);
void exibe_preorder(Arv * a);
void exibe_postorder(Arv * a); 

int altura(Arv * a);
int nro_folha(Arv * a); 
int grau_arv(Arv * a);

Arv * busca_arv_do_elem(Arv * a, int elem);
int altura_no(Arv * a, int elem);

int grau_no(Arv * a);
int qtde_nos(Arv *a, int grau);

void exibe_percorre_nivel(Arv * a); 

void menu();

#endif