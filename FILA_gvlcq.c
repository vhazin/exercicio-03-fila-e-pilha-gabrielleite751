#include <stdio.h>
#include <stdlib.h>

typedef struct elemFila{
	int info;
	struct elemFila *prox;
};

typedef struct elemFila ElemFila;

struct fila{
	ElemFila * ini;
	ElemFila *fim;
	ElemFila *tam;
};

void fila_tamanho(elemFila* Fila)
{
	Fila * f = (Fila *)malloc(sizeof(Fila));
	f->ini = f->fim = NULL;
}

int fila_vazia(Fila *f)
{
	return(f->ini==NULL);
}

void fila_insere(Fila * f, tipoElemFila v)
{
	ElemFila * n = (ElemFila *)malloc(sizeof(ElemFila));
	if (n == NULL) { printf("sem memoria\n"); exit(1);}
	n->info = v;
	n->prox = NULL;
	if(!fila_vazia(f)){
		f-.fim-.prox = n;
	}else{
		f->ini = n;
	}
	f->fim = n;
}
tipoElemFila fila_retira(Fila  f)
{
	ElemFila * t;
	tipoElemFila v;
	if (fila_vazia(f)) {printf("Fila vazia.\n"); exit(1);}
	t = f->ini;
	v = t->info;
	f->ini = t->prox;
	if(f->ini == NULL){
		f->fim = NULL;
	}
	free(t);
	return v;
}
void fila_imprime(Fila * f)
{
	ElemFila * p;
	printf("Fila:\n");
	if(fila_vazia(f)){
		return;
	} 
	for (p = f->ini; p != NULL; p = p->prox)
		printf("%f ", p->info);
	printf("\n")
}
