#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <ctype.h>

typedef struct{
    char txt[20];
    int cnt;
}Cuvant;

Cuvant cuvinte[100];
int nCuvinte;

Cuvant *cauta(char *txt)
{
    for(int i =0; i<nCuvinte; i++)
    {
        if(strcmp(cuvinte[i].txt, txt) == 0)
            return &cuvinte[i];
    }
    return NULL;
}

void sortare()
{
    char schimbare;
    do{
        schimbare = 0;
        for(int i =1; i<nCuvinte; i++)
        {
            if(strcmp(cuvinte[i-1].txt, cuvinte[i].txt) > 0)
            {
                Cuvant c = cuvinte[i-1];
                cuvinte[i-1] = cuvinte[i];
                cuvinte[i] = c;
                schimbare = 1;
            }
        }
    }while(schimbare);
}

int main()
{
   char txt[20];
   for(;;)
   {
    fgets(txt, 20, stdin);
    txt[strcspn(txt, "\n")] = '\0';
    if(strlen(txt)==0) break;
    Cuvant *c = cauta(txt);
    if(c)
    {
        c-> cnt++;
    }
    else
    {
        strcpy(cuvinte[nCuvinte].txt, txt);
        cuvinte[nCuvinte].cnt = 1;
        nCuvinte++;
    }
   }
   sortare();
   for(int i =0; i<nCuvinte; i++)
   {
    printf("%s: %d\n", cuvinte[i].txt, cuvinte[i].cnt);
   }
}