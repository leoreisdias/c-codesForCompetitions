struct no{
    struct no *esq;
    struct no *dir;
    int d;
    int fb;
};

typedef struct no *Arvore;
typedef struct no *AVL;

void insertNode(Arvore *t,int d);
void inOrder(Arvore t);
void preOrder(Arvore t);
void posOrder(Arvore t);
void insertavl(AVL *t,int d);
void balanc(AVL *t);
void fatb(AVL *t);
