struct rbno{
    struct rbno *esq;
    struct rbno *dir;
    int d;
    struct rbno *cor;
    struct rbno *pai;
    int raiz=0;
};

typedef struct rbno *Arvorerb;

void insertrb(Arvorerb *t,int x);
void removerb(Arvorerb *t,int x);
void balanc_cor(Arvorerb *t,int x);
