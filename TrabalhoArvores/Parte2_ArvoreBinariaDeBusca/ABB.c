#include "ABB.h"

Arv * cria_arvore_vazia(){
	return NULL;
}

int arvore_vazia(Arv * a){
	if(a == NULL)
		return 1;
	else 
		return 0;
}

void libera_arvore(Arv * a){
	if(arvore_vazia(a)){
		return;
	}

	if(a != NULL){
		libera_arvore(a->sae);
		libera_arvore(a->sad);
		free(a);
	}
	a = NULL;
}

void exibe_arvore(Arv * a){
	if(arvore_vazia(a))
		printf(" <> ");

	else if(a != NULL){
		printf("<%d ", a->info.idade);
		exibe_arvore(a->sae);
		exibe_arvore(a->sad);
		printf(">");
	}
}

void exibe_arvore_ordenado(Arv * a){
	if(arvore_vazia(a))
		printf("");

	else if(a != NULL){
		exibe_arvore_ordenado(a->sae);
		printf("%d ", a->info.idade);
		exibe_arvore_ordenado(a->sad);
	}	
}

reg* cria_elem(int i, char n[], char cur[]) {
	reg* elem = (reg*) malloc(sizeof(reg));

	if(elem == NULL)
		return NULL;

	elem->idade = i;
	strcpy(elem->nome,n);
	strcpy(elem->curso,cur);
	
	return elem;
}

void exibe_registro(reg * elem) {
	printf("Idade: %d \t Nome: ", elem->idade);

	printf("%s", elem->nome);

	printf("\tCurso: %s\n ", elem->curso);
}


void reg_cpy(reg *a, reg *b) { 
	a->idade = b->idade;	
	strcpy(a->nome, b->nome);	
	strcpy(a->curso, b->curso);
}


Arv * cria_arvore(Arv * esq, Arv * dir, reg *elem) {
	Arv * nova = (Arv*) malloc(sizeof(Arv));

	if(nova == NULL)
		return;

	reg_cpy(&(*nova).info,elem);

	nova->sad = dir;
	nova->sae = esq;

	return nova;

}

void insere_ordenado(Arv *pai, Arv * a, reg *elem, int n) {
	if(arvore_vazia(a)){
		Arv * raiz = cria_arvore(NULL,NULL,elem);
		if(n == 1)
			pai->sad = raiz;
		else if(n == 2)
			pai->sae = raiz;
	}

	else if((elem->idade) >= (a->info.idade)){
		insere_ordenado(a, a->sad,elem,1);
	}
	else	
		insere_ordenado(a, a->sae,elem,2);

}

int remove_ordenado(Arv * a, int elem) {
	if(arvore_vazia(a))
		return 0;

	else if((a->info.idade != elem) && (a->info.idade >= elem)){
		remove_ordenado(a->sad,elem);
	}

	else if((a->info.idade != elem) && (a->info.idade < elem)){
		remove_ordenado(a->sae,elem);
	}

	else{
		if(a->sae == NULL && a->sad == NULL){
			libera_arvore(a);
			a = NULL;
		}
		else if(a->sae != NULL && a->sad == NULL){
			Arv * aux = a;
			a = a->sae;
			free(aux); 
			aux = NULL;
		}
		else if(a->sae == NULL && a->sad != NULL){
			Arv * aux = a;
			a = a->sad;
			free(aux); 
			aux = NULL;
		}
		return 1;
	}
}

Arv * busca_bin(Arv * a, reg * elem) {
	if(arvore_vazia(a)) 
		return NULL;

	if(a->info.idade == elem->idade) 
		return a;

	else if(a->info.idade > elem->idade) 
		return busca_bin(a->sad,elem);

	else 
		busca_bin(a->sae,elem);
}

int soma_nos(Arv * a) {
		if(arvore_vazia(a->sae) && arvore_vazia(a->sad)) 
			return 1;
		int ne = 0, nd = 0;

		if(!arvore_vazia(a->sae)) 
			ne = soma_nos(a->sae);

		if(!arvore_vazia(a->sad)) 
			nd = soma_nos(a->sad);

		return (ne + nd + 1);
}

int de_maior(Arv * a) {
	if(arvore_vazia(a)) 
		return 0;

	if(a->info.idade >= 18) 
		return de_maior(a->sae) + soma_nos(a->sad)+1;

	return de_maior(a->sad);
}

int qtde_alunos(Arv * a, int ini, int fim) {
	if(arvore_vazia(a)) 
		return 0;

	int p1 = 0, p2 = 0;

	if(a->info.idade >= ini) 
		p1 = qtde_alunos(a->sae, ini, fim);

	if(a->info.idade <= fim) 
		p2 = qtde_alunos(a->sad, ini, fim);

	return (ini <= a->info.idade && a->info.idade <= fim) + p1 + p2;
}

int um_filho(Arv * a) {
	if(arvore_vazia(a))
		return 0;

	int x = (!arvore_vazia(a->sae) && arvore_vazia(a->sad));

	int y = (arvore_vazia(a->sae) && !arvore_vazia(a->sad));
	
	return um_filho(a->sae) + um_filho(a->sad) + (x||y); 
}

int completa(Arv * a) {
	if(arvore_vazia(a)) 
		return 1;

	if(arvore_vazia(a->sae) && arvore_vazia(a->sad)) 
		return 1;

	if(abs(altura_arv(a->sae) - altura_arv(a->sad)) > 2) 
		return 0;
	
	return completa(a->sae) & completa(a->sad);
}

int altura_arv(Arv * a) {
	if(arvore_vazia(a)) 
		return -1;

	int ne = altura_arv(a->sae);
	int nd = altura_arv(a->sad);
	
	if(ne < nd) 
		return nd+1;
	
	else 
		return ne+1;
}



reg * maior(Arv * a) {
	if(arvore_vazia(a)) 
		return NULL;

	reg *x = a->info, *y;

	y = maior(a->sad);

	if(y && y->idade > x->idade) 
		x = y; 
	
	return x;
}


Arv * juntar(Arv * a1, Arv * a2) {
	if(arvoreB_vazia(a2->sae) && arvoreB_vazia(a2->sad)) 
		insere_ordenado(a1,a2->info);

	if(!arvoreB_vazia(a2->sae)) 
		juntar(a1,a->sae);

	if(!arvoreB_vazia(a2->sad)) 
		juntar(a1,a->sad);
}

//-------------------MENU------------------------//
void menu() {
	int i, n[100], c[100];
	puts("Bem-vindo!\nVamos comecar criando um registro para ser o pertencente ao no raiz: ");
	puts("Insira a idade:");
	scanf("%d", &i);
	puts("Insira o nome:");
	scanf("%s", n[]);
	puts("Insira o curso:")
	scanf("%s", c[]);

	reg * elem0 = cria_elem(i,n,c);
	Arv * a0 = cria_arvore(NULL,NULL,elem0);

	Arv *aux;
	reg *elem;

	int a, b, op;

	puts("Agora vamos comecar...");
	while(1){
		puts("\n----------------MENU----------------");
		puts("1 - Inserir um no na arvore");
		puts("2 - Remover um no da arvore");
		puts("3 - Realizar busca binaria");
		puts("4 - Exibir arvore");
		puts("5 - Ver qual o aluno mais velho");
		puts("6 - Ver quantos alunos sao maior de idade");
		puts("7 - Saber quanto alunos ha num intervalo de idade");
		puts("8 - Saber quantos nos da arvore possuem apenas um  filho");
		puts("9 - Verificar se a arvore eh completa");
		puts("10 - Saber a altura da arvore");
		puts("11- Juntar duas arvores");
		puts("12 - Sair");
		scanf("%d", &op);
		puts("\n------------------------------------\n");


		if(op == 1){
			puts("Vamos primeiro criar uma arvore para inserir como filha.\nVamos comecar criando o registro...");
			puts("Insira a idade:");
			scanf("%d", &i);
			puts("Insira o nome:");
			scanf("%s", n[]);
			puts("Insira o curso:")
			scanf("%s", c[]);

			elem = cria_elem(i,n,c);

			insere_ordenado(a0,NULL,elem);
		}

		else if(op == 2){
			puts("Removendo no da arvore...");
			remove_ordenado(a0,elem0);
		}

		else if(op == 3) {
			puts("Realizando uma busca binaria no elem %d\n",  elem0->idade);
			busca_bin(a0,elem0);
		}

		else if(op == 4) {
			puts("---------------ARVORE---------------");
			exibe_arvore(A);
			puts("\n----------------------------------");	
			puts("");
		}

		else if(op == 5) { //parei aqui
			puts("Procurando o aluno mais velho...");
			maior(a0);
		}

		else if(op == 6) {
			printf("O numero d e alunos maior de idade eh: %d\n", de_maior(a0));
		}

		else if(op == 7) {
			puts("Insira o int do inicio do intervalo:");
			scanf("%d", &a);
			puts("Insira o int do final do intervalo:");
			scanf("%d", &b);

			printf("A quantidade de alunos entre essas idades eh: %d\n", qtde_alunos(a0,a,b));
		}

		else if(op == 8) {
			printf("O numero de nos na arvore que possuem apenas um filho eh: %d\n", um_filho(a0));
		}

		else if(op == 9) {
			printf("A arvore eh completa? Resposta: %d\n", completa(a0));
		}

		else if(op == 10) {
			printf("A altura da arvore eh: %d\n", altura(a0));	
		}

		else if(op == 11) {
			puts("Juntando arvores...");
			juntar(a0,NULL);
		}

		else if(op == 12){
			libera_arvore(A);
			break;
		}

		else
			puts("Opcao nao reconhecida... Digite uma valida!");
	}
}