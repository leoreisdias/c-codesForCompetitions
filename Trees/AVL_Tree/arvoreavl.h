struct avlno{
     int fb;
     int d;
     struct avlno *esq;
     struct avlno *dir;

};
typedef struct avlno *AVL;

void insertavl(AVL *t,int d);
void balanc(AVL *t);
void fatb(AVL *t);
void removeavl(AVL *t,int x);
