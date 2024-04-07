#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

/*LABORATOR 3 PROBLEMA 1
Exemplu: Se citește un număr n, care semnifică numărul de note primite. 
Se vor citi ulterior n note (numere reale) și se va afișa media lor aritmetică.

int main()
{
    int n, x, i;
    float suma = 0, media;
    printf("Introduceti numarul de note primite: ");
    scanf("%d", &n);
    for(i = 1; i <= n; i++)
    {
        printf("Introduceti nota %d: ", i);
        scanf("%d", &x);
        suma = suma + x;
    }
    media = suma/n;
    printf("Media notelor obtinute este %g", media);
    return 0;
}

LABORATOR 3 PROBLEMA 2
Exemplu: Să se afișeze în ordine inversă toate cifrele unui număr întreg. 

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(void)
{
    int n, cifra;
    printf("Introduceti un numar de la tastatura: ");
    scanf("%d", &n);
    do
    {
        cifra = n % 10;
        printf("%d\n", cifra);
        n = n /10;
    } while (n > 0);
    return 0;
}

Sa se scrie un program care primeste un numar in sistem zecimal si il afiseaza in binar. 

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main()
{
    int n, cifra, nr_invers = 0, cifra1, nr_binar = 0;
    printf("Introduceti un numar de la tastatura: ");
    scanf("%d", &n);
    while(n > 0)
    {
        cifra =  n % 2;
        nr_invers =  nr_invers * 10 + cifra;
        n = n / 2;
    }
    while(nr_invers > 0)
    {
        cifra1 =  nr_invers % 10;
        nr_binar = nr_binar * 10 + cifra1;
        nr_invers = nr_invers / 10;
    }
    printf("Numarul in sistem binar este: %d", nr_binar);
    return 0;
}

LABORATOR 3 PROBLEMA 3
Exemplu: Se cere un n>0.
Să se afișeze pe prima linie o steluță, pe a doua linie două steluțe și tot așa până la linia n inclusiv. 

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

int main(void)
{
    int n, i, j;
    printf("Introduceti un numar de la tastatura: ");
    scanf("%d", &n);
    if(n <= 0)
    {
        printf("Ati introdus un numar prea mic.\n");
        exit(0);
    }
    for(i = 0; i < n; i++)
    {
        for(j = 0; j <= i; j++)
        {
            printf("* ");
        }
        printf("\n");
    }
    return 0;
}

LABORATOR 2 PROBLEMA 1
Exemplu: se cere să se citească 3 numere întregi de la tastatură, a, b, 
x și să se afișeze o valoare de adevărat sau de fals dacă x este sau nu în interiorul intervalului închis [a,b]. */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(void)
{
    int a, b, x;
    printf("Introduceti primul numar, a: ");
    scanf("%d", &a);
    printf("Introduceti al doilea numar, b: ");
    scanf("%d", &b);
    printf("Introduceti al treilea numar, x: ");
    scanf("%d", &x);
    printf("Daca numarul se afla in interval se va afisa 1, daca nu, se va afisa 0: %d", (x >= a && x <= b));
    return 0;
}