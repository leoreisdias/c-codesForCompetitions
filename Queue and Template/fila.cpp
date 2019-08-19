#include "fila.h"

void create (fila *s){
    s->inicio=NULL;
    s->fim=NULL;
}

int inserts(fila *s,int d){
    struct no *aux;
    aux = (struct no *) malloc(sizeof(struct no));
    if(aux==NULL) return false;
    aux->dado=d;
    aux->prox=NULL;
    if(s->inicio==NULL) s->inicio=aux;
    if(s->fim!=NULL) s->fim->prox=aux;
    s->fim=aux;
}

int removes(fila *s,int *d){
    struct no *aux;
    if(s->inicio==NULL) return false;
    aux=s->inicio;
    s->inicio=aux->prox;
    *d=aux->dado;
    free(aux);
    return true;
}

int isEmpty(fila s){
    if(s.inicio==NULL) return true;
    else return false;
}
