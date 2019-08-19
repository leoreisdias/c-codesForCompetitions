#include "arvoreavl.h"
#include<bits/stdc++.h>

//Altura geral
int Altura(Arvore t){
    int u,v;
    if(t == NULL) return -1;
    u=Altura(t->esq);
    v=Altura(t->dir);
    if(u>v) return u+1;
    else
        return v+1;
}

//Altura a direita
int Alturadir(AVL t){
    int v;
    if(t == NULL) return -1;
    v=Alturadir(t->dir);
    return v+1;
}

//Altura a esquerda
int Alturaesq(AVL t){
    int u;
    if(t == NULL) return -1;
    u=Alturaesq(t->esq);
    return u+1;
}

//Calcular fator de balanceamento
void fatb(AVL *t){
    (*t)->fb=Alturadir(*t) - Alturaesq(*t);
}

// Balancear
void balanc(AVL *t){
    struct avlno *aux;
    if((*t)->fb >=-1 && (*t)->fb<=1) return;
    if((*t)->fb > 0){
        fatb(&(*t)->dir);
        if(((*t)->dir)->fb < 0){
            aux=(*t)->dir;
            (aux)->esq = ((aux)->esq)->dir;
            ((aux)->esq)->dir=(*t)->dir;
        }
        (*t)->dir=((*t)->dir)->esq;
        ((*t)->dir)->esq = (*t);
    }
    else{
        fatb(&(*t)->esq);
        if(((*t)->esq)->fb > 0){
            aux=(*t)->esq;
            (aux)->dir = ((aux)->dir)->esq;
            ((aux)->dir)->esq=(*t)->esq;
        }
        (*t)->esq=((*t)->esq)->dir;
        ((*t)->esq)->dir = (*t);
        }
    free(aux);
}

//Inserir nó e dados
void insertavl(AVL *t,int d){
    if(*t==NULL){
        *t=(struct avlno*) malloc(sizeof(struct avlno));
        if(*t!=NULL){
            (*t)->esq=NULL;
            (*t)->dir=NULL;
            (*t)->d=d;
                    }
        else
            printf("Sem Memoria\n");
                }
    else{
        fatb(&(*t));
        balanc(&(*t));
        if(d < (*t)->d)
            insertavl(&(*t)->esq,d);
        else
            insertavl(&(*t)->dir,d);
        }
        fatb(&(*t));
        balanc(&(*t));
}

//remover nó de dado especifico
void removeavl(AVL *t,int x){
    if((*t)->d == x) (*t)=NULL;
    else{
        if((*t)->d < x){
         if(x == ((*t)->esq)->d){
            (*t)->esq=NULL;
            fatb(&(*t));
            balanc(&(*t));
         }
         else
         removeavl(&(*t)->esq,x);
        }
        else{
            if(x == ((*t)->dir)->d){
                (*t)->dir=NULL;
                fatb(&(*t));
                balanc(&(*t));
                }
                else
                removeavl(&(*t)->dir,x);
            }
        }
}
