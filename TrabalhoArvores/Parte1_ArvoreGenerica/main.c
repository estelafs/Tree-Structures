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
	

	puts("\n---------------grau_arv---------------");
	printf("Arv 1: %d\n", grau_arv(A));
	printf("Arv 2: %d\n", grau_arv(B));
	printf("Arv 3: %d\n", grau_arv(C));
	printf("Arv 4: %d\n", grau_arv(D));
	printf("Arv 5: %d\n", grau_arv(E));
	printf("Arv 6: %d\n", grau_arv(F));
	printf("Arv 7: %d\n", grau_arv(G));
	printf("Arv 8: %d\n", grau_arv(H));
	printf("Arv 9: %d\n", grau_arv(I));

	// printf("Grau 1: %d\n", grau_arv(A));



	return 0;
}