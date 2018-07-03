#ifndef ABB_H_INCLUDED
#define ABB_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct registro{
	int chave;
	char nome[100];
	int idade;
	double salario;
};

typedef struct registro reg;

struct no{
	struct registro info;
	struct no *sae;
	struct no *sad;
};

typedef struct no Arv;

Arv * cria_arvore_vazia();
int arvore_vazia(Arv * a);
void libera_arvore(Arv * a);

void exibe_arvore(Arv * a); //pré-ordem
void exibe_arvore_ordenado(Arv * a); //in order
void exibe_registro(reg * elem);

reg* cria_elem(int c, char n[], int i, double s);
void reg_cpy(reg *a, reg *b); //copia o conteudo de b pra a

Arv * cria_arvore(Arv * esq, Arv * dir, reg *elem);

void insere_ordenado(Arv *pai, Arv * a,  reg *elem, int n); //NAO TENHO CERTEZA SE FUNCIONA
int remove_ordenado(Arv * a, int elem);
Arv * busca_bin(Arv * a, reg * elem);

#endif