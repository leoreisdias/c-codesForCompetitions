#include "arvore.h"
#include<bits/stdc++.h>

void insertNode(Arvore *t,int d){
    if(*t == NULL){
        *t = (struct no*) malloc(sizeof(struct no));
        if(*t != NULL){
            (*t)->esq=NULL;
            (*t)->dir=NULL;
            (*t)->d=d;
        }
        else
            printf("Memoria Insuficiente\n");
    }
    else
        if (d < (*t)->d)
            insertNode(&(*t)->esq,d);
        else if(d > (*t)->d)
            insertNode(&(*t)->dir,d);
        else
            printf("Duplicacao de no\n");

}

void inOrder(Arvore t){
    if(t != NULL){
    inOrder(t->esq);
    printf("%d ",t->d);
    inOrder(t->dir);
    }
}

void preOrder(Arvore t){
    if(t != NULL){
        printf("%d ",t->d);
        preOrder(t->esq);
        preOrder(t->dir);
    }
}

void posOrder(Arvore t){
    if(t !=NULL){
        posOrder(t->esq);
        posOrder(t->dir);
        printf("%d ",t->d);
    }
}

int ContaNos(Arvore t){
    if(t==NULL)
        return 0;
    return ContaNos(t->esq) + ContaNos(t->dir) + 1;
}

int Altura(Arvore t){
    int u,v;
    if(t == NULL) return -1;
    u=Altura(t->esq);
    v=Altura(t->dir);
    if(u>v) return u+1;
    else
        return v+1;
}

int ContaFolhas(Arvore t){
    if(t==NULL) return 0;
    if(t->esq == NULL && t->dir==NULL) return 1;
    else
        return ContaFolhas(t->esq) + ContaFolhas(t->dir);
}
