#ifndef ABB_H_INCLUDED
#define ABB_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct registro{
	int idade;
	char nome[100];
	char curso[100];
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

void exibe_arvore(Arv * a);
void exibe_arvore_ordenado(Arv * a);
void exibe_registro(reg * elem);

reg* cria_elem(int i, char n[], char cur[]);
void reg_cpy(reg *a, reg *b);

Arv * cria_arvore(Arv * esq, Arv * dir, reg *elem);

void insere_ordenado(Arv *pai, Arv * a,  reg *elem, int n);
int remove_ordenado(Arv * a, int elem);

Arv * busca_bin(Arv * a, reg * elem);

int soma_nos(Arv * a);
int de_maior(Arv * a);
int qtde_alunos(Arv * a, int ini, int fim);
int um_filho(Arv * a);
int completa(Arv * a);
int altura_arv(Arv * a);
reg * maior(Arv * a);
Arv * juntar(Arv * a1, Arv * a2);

void menu();
#endif