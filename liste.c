#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>


typedef struct nod{
    int info;
    struct nod *urm;
}nod;

nod *nou(int n, nod *urm)
{
    nod *e=(nod*)malloc(sizeof(nod));
    if(!e)
    {
        printf("memorie insuficienta");
        exit(EXIT_FAILURE);
    }
    e->info=n;
    e->urm=urm;
 return e;
}

nod *adaugaInceput(nod *lista, int n)
{
 return nou(n,lista);
}

nod *adaugaSfarsit(nod *lista,int n)
{
    if(!lista)
        return nou(n,NULL);
    nod *p=lista,*urm;
    for(urm=p->urm;urm;p=urm,urm=p->urm){}
    p->urm=nou(n,NULL);
    return lista;
}
void afisare(nod *lista)
{
    for(;lista;lista=lista->urm)
    {
    printf("%d ",lista->n);
    }
    putchar('\n');
}

void eliberare(nod *lista)
{
    nod *p;
    while(lista)
    {
        p=lista->urm;
        free(lista);
        lista=p;
    }
}




int main()
{
    return 0;
}