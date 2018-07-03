#include "ArvoreGenerica.h"
#include "Lista.h"
#define max(a,b) (a>b ? a : b)

Arv * cria_arvore(int elem) {
	Arv * nova = (Arv*) malloc(sizeof(Arv));

	if(nova == NULL) 
		return NULL;

	nova->info = elem;
	nova->esq = NULL;
	nova->dir = NULL;

	return nova;
}

int arvore_vazia(Arv * a) {
	if(a == NULL)
		return 1;
	else
		return 0;
}

int insere_como_filha(Arv * mae, Arv * filha) {
	if(arvore_vazia(mae) || arvore_vazia(filha))
		return 0;

	filha->dir = mae->esq; //passa a ser irmão dos filhos da arvore mãe
	mae->esq = filha; //torna a arvore mae como nó raiz da arvore filha

	return 1;	
}

int existe_elem(Arv * a, int elem) {
	if(arvore_vazia(a))
		return 0;

	if(a->info == elem)
		return 1;

	if(existe_elem(a->esq,elem)) 
		return 1;
	else
		return existe_elem(a->dir,elem);
}

void libera_arvore(Arv * a) {
	if(arvore_vazia(a))
		return;

	if(a != NULL) {
		free(a->esq);
		free(a->dir);
		free(a);
	}

	a = NULL;
}

void exibe_arvore(Arv * a) {
	if(arvore_vazia(a))
		return;	

	else if(a != NULL){
		printf("<%d", a->info);
		exibe_arvore(a->esq);
		printf(">");
		exibe_arvore(a->dir);
	}
}

void exibe_preorder(Arv * a) {
	if(arvore_vazia(a))
		printf("");

	else if(a != NULL){
		printf("%d ", a->info);
		exibe_preorder(a->esq);
		exibe_preorder(a->dir);
	}
}

void exibe_postorder(Arv * a) {
	if(arvore_vazia(a))
		printf("");

	else if(a != NULL){
		exibe_postorder(a->esq);
		printf("%d ", a->info);
		exibe_postorder(a->dir);
	}
}

int altura(Arv * a) {
	if(arvore_vazia(a))
		return -1;	
	
	int resp = 0;
	
	if(a->esq != NULL){

		Arv * aux = a->esq;

		while(aux != NULL){
			resp = max(resp,altura(aux)+1);
			aux = aux->dir;
		}
		
	}
	return resp;
}

int nro_folha(Arv * a) { //funciona
	if(arvore_vazia(a))
		return -1;

	if(! a->esq) 
		return 1;

	Arv * aux = a->esq;
	int resp = 0;

	while(aux){
		resp += nro_folha(aux);
		aux = aux->dir;
	}

	return resp;
}

int grau_arv(Arv * a) {
	if(arvore_vazia(a))
		return -1;

	if(! a->esq) 
		return 0;

	Arv * aux = a->esq;
	int resp = 0, x=0;	

	while(aux){
		resp = max(resp,grau_arv(aux));
		aux = aux->dir;
		x++;
	}
	resp = max(resp, x);

	return resp;
}

Arv* busca_arv_do_elem(Arv * a, int elem) {
	if(arvore_vazia(a))
		return NULL;

	if(a->info == elem)
		return a;

	Arv * aux = a->esq, * aux2;

	while(aux){
		aux2 = busca_arv_do_elem(aux,elem);

		if(aux2)
			return aux2;

		aux = aux->dir;	

	}

	return aux;
}

int altura_no(Arv * a, int elem) {

	if(! existe_elem(a,elem)) 
		return -1;

	Arv * aux = busca_arv_do_elem(a,elem);
	aux = aux->esq;
	int resp = 0;

	while(aux){
		resp++;
		aux = aux->dir;

	}
	
	return resp;
}

int grau_no(Arv * a) {
	if(arvore_vazia(a))
		return -1;

	Arv * aux = a->esq;
	int resp = 0;

	while(aux){
		resp ++;
		aux = aux->dir;
	}

	return resp;
}

int qtde_nos(Arv *a, int grau) {
	if(arvore_vazia(a))
		return 0;

	Arv * aux = a->esq;
	int resp = (grau_no(a) == grau);

	while(aux){
		resp += qtde_nos(aux,grau);
		aux = aux->dir;
	}
	return resp;
}

void exibe_percorre_nivel(Arv * a) { //DA MUITO ERRADO
	Lista * l = criar_lista();
	inserir_no_final_lista(l,a->info);

	Arv *aux;

	while(tamanho_lista(l)){
		aux = busca_arv_do_elem(a,primeira_lista(l));
		remove_primeiro(l);

		printf("%d ", aux->info);

		aux = aux->esq;
		while(aux){
			inserir_no_final_lista(l,aux->info);
			aux = aux->dir;
		}
	}
}

//-------------------MENU------------------------//
void menu() {
	int n, op, elem;
	puts("Bem-vindo!\n Insira um inteiro para ser o no raiz da sua arvore inicial para comecar: ");
	scanf("%d", &n);

	Arv * A = cria_arvore(n);
	Arv *filha, *mae;

	puts("Agora vamos comecar...");
	while(1){
		puts("\n----------------MENU----------------");
		puts("1 - Inserir um no como filho na arvore");
		puts("2 - Verificar se existe elemento na arvore");
		puts("3 - Exibir arvore (em pre-order)");
		puts("4 - Exibir arvore (em post-order)");
		puts("5 - Exibir arvore (em largura/por nivel)");
		puts("6 - Ver a altura da arvore");
		puts("7 - Saber o numero de folhas da arvore");
		puts("8 - Saber o grau da arvore");
		puts("9 - Saber altura de um no");
		puts("10 - Saber o grau de um no");
		puts("11- Saber a quantidade de nos da arvore que possui o grau dado como entrada");
		puts("12 - Sair");
		scanf("%d", &op);
		puts("\n------------------------------------\n");


		if(op == 1){
			puts("Vamos primeiro criar uma arvore para inserir como filha.\nInsira o int que sera o no dela: ");
			scanf("%d", &elem);
			filha = cria_arvore(elem);
			puts("Insira o int do elem da arvore que sera mae dela:");
			scanf("%d", &elem);
			mae = busca_arv_do_elem(A,elem);
			printf("A arvore foi (1 para inserida com sucesso e 0 para fracasso): %d\n", insere_como_filha(mae,filha));
		}

		else if(op == 2){
			puts("Insira o int do elem que deseja ver se existe:");
			scanf("%d", &elem);
			printf("O elemento %d (1 para existe e 0 para nao existe): %d\n", elem, existe_elem(A,elem));
		}

		else if(op == 3) {
			puts("---------------ARVORE PREORDER---------------");
			exibe_preorder(A);
			puts("---------------------------------------------");
			puts("");
		}

		else if(op == 4) {
			puts("---------------ARVORE POSTORDER---------------");
			exibe_postorder(A);
			puts("\n----------------------------------------------");	
			puts("");
		}

		else if(op == 5) {
			puts("---------------ARVORE POR NIVEL---------------");
			exibe_percorre_nivel(A);
			puts("\n----------------------------------------------");
			puts("");
		}

		else if(op == 6) {
			printf("A altura da arvore principal eh: %d\n", altura(A));
		}

		else if(op == 7) {
			puts("Insira o int do elem da arvore que deseja saber o numero de folhas:");
			scanf("%d", &elem);
			printf("O de folhas eh: %d\n", nro_folha(busca_arv_do_elem(A,elem)));
		}

		else if(op == 8) {
			puts("Insira o int do elem da arvore que deseja saber o grau:");
			scanf("%d", &elem);
			printf("O grau da arvore eh: %d\n", grau_arv(busca_arv_do_elem(A,elem)));
		}
		else if(op == 9) {
			puts("Insira o int do elem do no que deseja saber a altura:");
			scanf("%d", &elem);
			printf("A altura do no %d eh: %d\n", elem, altura_no(A,elem));
		}


		else if(op == 10) {
			puts("Insira o int do elem do no que deseja saber o grau:");
			scanf("%d", &elem);
			printf("O grau do no %d eh: %d\n", elem, grau_no(busca_arv_do_elem(A,elem)));
		}

		else if(op == 11) {
			puts("Insira o int correspondente ao grau:");
			scanf("%d", &elem);
			printf("O numero de nos com grau %d eh: %d\n", elem, qtde_nos(A,elem));
		}

		else if(op == 12){
			libera_arvore(A);
			break;
		}

		else
			puts("Opcao nao reconhecida... Digite uma valida!");
	}
}