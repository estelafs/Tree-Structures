#ifndef ABB_H_INCLUDED
#define ABB_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct registro reg;
typedef struct no * Arv;

Arv * cria_arvore();
int arvore_vazia(Arv a);
void libera_arvore(Arv * a);
void exibe_arvore(Arv * a);
void exibe_ordenado(Arv * a);
int insere_ord(Arv * a, reg elem);



//Até a funçãõ exiibir árvore é igual as implementações de arvore binaria
/*Novas operações:
	exibir_ordenado
	insere_ord

	*/

#endif