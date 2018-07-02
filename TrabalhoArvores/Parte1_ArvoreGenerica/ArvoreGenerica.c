#include "ArvoreGenerica.h"
#define max(a,b) (a>b ? a : b)

//Lista -----------------------------------------------------
struct celula{
	int conteudo;
	struct celula *prox;
	struct celula *anterior;
};

struct lista{
	Celula *primeira;
	Celula *ultima;
};

Lista* criar_lista(){
	Lista *l = malloc(sizeof(Lista));
	l->primeira = NULL;
	l->ultima = NULL;
	return l;
}

void lista_inicia(Lista *l){
    l->primeira= NULL;
    l->ultima = NULL;
}

void inserir_no_inicio_lista(Lista * l, int i){
	Celula *c = malloc(sizeof(Celula));
	c->conteudo = i;
	c->prox = l->primeira;
	if (tamanho_lista(l) == 0)
    	l->ultima = c;
	else
    	l->primeira->anterior = c;
	l->primeira = c;
	c->anterior = NULL;
}

void inserir_no_final_lista(Lista *l, int i){
	Celula *c = malloc(sizeof(Celula));
	c->conteudo = i;
	c->prox = NULL;
	if (tamanho_lista(l) != 0){
    	c->anterior = l->ultima;
    	l->ultima->prox = c;
	}
	l->ultima = c;
	if (tamanho_lista(l) == 0){
    	l->primeira = c;
    	c->anterior = NULL;
	}
}

int tamanho_lista(Lista *l){
	Lista *resto;
	int tam;
	if (l->primeira == NULL){
    	return 0;
	}
	else{
    	resto = (Lista *) malloc(sizeof(Lista));
    	resto->primeira = l->primeira->prox;
    	tam = tamanho_lista(resto);
    	free(resto);
    	return 1 + tam;
	}
}

void remove_primeiro(Lista *l){
    if(tamanho_lista(l) == 0){
        puts("Lista vazia!\n");
        return;
    }
    else if(tamanho_lista(l)  == 1){
        Celula *aux = l->primeira;
        lista_inicia(l);
        free(aux);
    }
    else{
        Celula *aux = l->primeira;
        l->primeira->conteudo = l->primeira->prox->conteudo;
        l->primeira = l->primeira->prox;
        free(aux);
    }
}

void imprime_lista(Lista *l){
    Celula *aux = l->primeira;
    printf("\nFILA: ");
    while(aux != NULL){
        printf("%d\t", aux->conteudo);
        aux = aux->prox;
    }
}
//Arvore -----------------------------------------------------

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
//---------------------------------------------------- DÃO ERRADO

Arv* busca_arv_do_elem(Arv * a, int elem) {
	if(arvore_vazia(a))
		return NULL;
	printf("<%d>  ", a->info);
	if(a->info == elem)
		return a;

	Arv * aux = a->esq;
	while(aux){
		printf(" %d", aux->info);
		aux = aux->dir;	
	}
puts("");
	aux = a->esq;
	while(aux) {

		if(busca_arv_do_elem(aux,elem))
			return aux;
		aux = aux->dir;
	}

	return NULL;
		
	// if(a->dir != NULL) 
	// 	return busca_arv_do_elem(a->dir,elem);
	// else if(a->esq != NULL)
	// 	return busca_arv_do_elem(a->esq,elem);
}

int altura_no(Arv * a, int elem) {

	if(! existe_elem(a,elem)) 
		return -1;
	
	// puts("\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>");
	// exibe_arvore(busca_arv_do_elem(a,elem));
	// puts("\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>");

//////////////////
	return altura(busca_arv_do_elem(a,elem));
}



//------------------------------------ 

void exibe_percorre_nivel(Arv * a) { //DA MUITO ERRADO
	if(arvore_vazia(a))
		return;

	Lista *lista = criar_lista();

	inserir_no_final_lista(lista,a->info);

	Arv * aux = a;
	Arv * aux1 = a;

	while(tamanho_lista(lista) != 0){
		printf("%d ", lista->primeira->conteudo);


		remove_primeiro(lista);

		if(aux->dir != NULL){
			while(aux != NULL){
				inserir_no_final_lista(lista,aux->dir->info);
				aux = aux->dir;
			}
		}

		else if(aux1->esq != NULL){
			while(aux1 != NULL){
				printf(" ooi \n");
				inserir_no_final_lista(lista,aux1->esq->info);
				aux1 = aux1->esq;
			}
		}
		
		
	}


	
}






int grau_arv(Arv * a) {
	if(arvore_vazia(a))
		return -1;

	if(! a->esq) 
		return 0;

	Arv * aux = a->esq;
	int resp = 1;	

	while(aux){
		resp = grau_arv(aux) + 1;
		aux = aux->dir;
	}

	return resp;
}