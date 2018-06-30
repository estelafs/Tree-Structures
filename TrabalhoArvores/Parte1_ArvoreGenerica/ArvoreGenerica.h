#ifndef ARVOREGENERICA_H_INCLUDED
#define ARVOREGENERICA_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>

typedef struct celula Celula;
typedef struct lista Lista;

struct no{
	int info;
	struct no *esq; //a esquerda são filhos
	struct no *dir; //a direita são irmãos
};

typedef struct no Arv;

//Lista -----------------------------------------------------
Lista* criar_lista();
void lista_inicia(Lista *l);
void inserir_no_inicio_lista(Lista * l, int i);
void inserir_no_final_lista(Lista *l, int i);
void remove_primeiro(Lista *l);
int tamanho_lista(Lista *l);

void imprime_lista(Lista *l);


//Arvore -----------------------------------------------------
Arv * cria_arvore(int elem);
int arvore_vazia(Arv * a);

int insere_como_filha(Arv * mae, Arv * filha);

int busca_elem(Arv * a, int elem);

void libera_arvore(Arv * a);

int altura(Arv * a, int cont);

//--------------------- FUNCIONAM
void exibe_arvore(Arv * a);
void exibe_preorder(Arv * a);
void exibe_postorder(Arv * a); 






//--------------------- BARRINHA DA VERGONHA
void exibe_percorre_nivel(Arv * a); //TA DANDO ERRADO 

int nro_folha(Arv * a); //CONFERIR

#endif