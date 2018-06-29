#include "ABB.h"

int main(){

	reg * elem6 = cria_elem(-1,"Hana",2,"Fisica");
	reg * elem5 = cria_elem(2,"Gab",87,"Quimica");
	reg * elem4 = cria_elem(4,"Jao",58,"Quimica");
	reg * elem3 = cria_elem(5,"Cris",12,"Comp");
	reg * elem2 = cria_elem(3,"Criss",65,"Comp");
	reg * elem1 = cria_elem(1,"Ana",21,"Fisica");
	reg * elem0 = cria_elem(0,"Fernando",65,"Comp");


	Arv * a3 = cria_arvore(NULL,NULL,elem2);

	Arv * a2 = cria_arvore(NULL,NULL,elem1);

	Arv * a1 = cria_arvore(a2,a3,elem0);
	
	insere_ordenado(a1,a1,elem3,0);

	insere_ordenado(a1,a1,elem4,0);


	insere_ordenado(a1,a1,elem5,0);
	insere_ordenado(a1,a1,elem6,0);

	exibe_arvore(a1);
	puts("\n-----------------------");

	remove_ordenado(a1,(1));
	exibe_arvore_ordenado(a1);


	puts("\n>>>>>>>>>>FOOi");
}