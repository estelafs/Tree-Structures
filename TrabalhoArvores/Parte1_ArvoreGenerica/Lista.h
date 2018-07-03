#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>

typedef struct celula Celula;
typedef struct lista Lista;

Lista* criar_lista();
void lista_inicia(Lista *l);
void inserir_no_inicio_lista(Lista * l, int i);
void inserir_no_final_lista(Lista *l, int i);
void remove_primeiro(Lista *l);
int tamanho_lista(Lista *l);
void imprime_lista(Lista *l);
int primeira_lista(Lista *l);

#endif