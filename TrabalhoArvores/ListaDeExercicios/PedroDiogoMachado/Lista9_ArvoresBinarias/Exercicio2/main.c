#include "ArvoreBinaria.h"

int main(){
	Arv * a2 = cria_arvore(2,NULL,NULL);

	Arv * a3 = cria_vazia();
	a3 = cria_arvore(3,NULL,NULL);

	Arv * a1 = cria_arvore(1,a2,a3);

	printf("Altura a1: %d\n",  altura(a1));
	printf("Existe 2: %d\n",  busca_elem(a1,2));
	
	mostra_arvore(a1);

	libera_arvore(a1);

	return 0;

}

