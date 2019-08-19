#include<bits/stdc++.h>

struct no{
    int dado;
    struct no *prox;
};
typedef struct{
        struct no *inicio;
}listas;

void create(listas *q){
    q->inicio=NULL;
}

int inserts(listas *q,int d){
    struct no *aux, *atual,*anterior;
    aux=(struct no*)malloc(sizeof(struct no));
    if(aux!=NULL){
        aux->dado=d;
        aux->prox=NULL;
        anterior=NULL;
        atual=q->inicio;
    }
    while(atual!=NULL && d>atual->dado){
        anterior=atual;
        atual=atual->prox;
    }
    if(anterior==NULL){
        aux->prox=q->inicio;
        q->inicio=aux;
    }
    else{
        anterior->prox=aux;
        aux->prox=atual;
    }
}
int isEmpty(listas q){
        if(q.inicio==NULL) return (true);
        else return(false);
}

void imprime(listas q){
        struct no *aux;
        aux=q.inicio;
        if(!isEmpty(q)){
            while(aux!=NULL){
                printf("%d\n",aux->dado);
                aux=aux->prox;
            }
        }
}



int remover(listas *q,int d){
        struct no *aux, *atual,*anterior;
        if(d == (q->inicio)->dado){
            aux=q->inicio;
            q->inicio=(q->inicio)->prox;
            free(aux);
            return(true);
        }
        else{
            anterior=q->inicio;
            atual=(q->inicio)->prox;
            while(atual!=NULL && d!=atual->dado){
                anterior=atual;
                atual=atual->prox;
            }
            if(atual!=NULL){
                aux=atual;
                anterior->prox=atual->prox;
                free(aux);
                return(true);
            }
            else return (false);
        }
}

