#include "ArvoreGenerica.h"

int main(){
	Arv * A = cria_arvore(1);
	Arv * B = cria_arvore(2);
	Arv * C = cria_arvore(3);
	Arv * D = cria_arvore(4);
	Arv * E = cria_arvore(5);
	Arv * F = cria_arvore(6);
	Arv * G = cria_arvore(7);
	Arv * H = cria_arvore(8);
	Arv * I = cria_arvore(9);

	insere_como_filha(F,I);
	insere_como_filha(F,H);
	insere_como_filha(C,F);
	insere_como_filha(C,E);
	insere_como_filha(D,G);
	insere_como_filha(A,D);
	insere_como_filha(A,C);
	insere_como_filha(A,B);

	puts("---------------ARVORE---------------");
	exibe_arvore(A);

	puts("\nPreorder");
	exibe_preorder(A);

	puts("\nPostorder");
	exibe_postorder(A);
	

	// exibe_percorre_nivel(A);

	printf("\nfolhas: %d\n", nro_folha(A));



	return 0;
}