/* PROBLEMA 1
Se citește un număr întreg n>10. Să se afișeze toată seria de numere începând cu n, 
următorul număr fiind obținut prin scăderea din cel anterior a n/10, atâta timp cât n>10 

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main()
{
    int n;
    printf("Introduceti un numar n de la tastatura: ");
    scanf("%d", &n);
    if(n <= 10)
    {
        printf("Numarul introdus este prea mic.\n");
        exit(0);
    }
    while(n > 10)
    {
        printf("%d ", n);
        n = n - n/10;
    }
    return 0;
} 

PROBLEMA 2
Se citește un număr întreg n>1. Să se afișeze seria ”1+2+3+4+…+n=s”, unde s=suma(1...n). 

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main()
{
    int n, i, s = 0;
    printf("Introduceti un numar n de la tastatura: ");
    scanf("%d", &n);
    if(n <= 1)
    {
        printf("Numarul introdus este prea mic.\n");
        exit(0);
    }
    for(i = 1; i <= n; i++)
    {
        if(i == n)
        {
            s = s + n;
            printf("%d = %d", n, s);
            break;
        }
        printf("%d + ", i);
        s = s + i;
    }
    return 0;
}


//PROBLEMA 3
//Se citește un număr n>1. Să se afișeze folosind steluțe un pătrat gol, având latura de n steluțe. 

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main()
{
    int n, i, j;
    printf("Introduceti un numar de la tastatura: ");
    scanf("%d", &n);
    if(n <= 1)
    {
        printf("Ati introdus un numar prea mic.\n");
        exit(0);
    }
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            if((j == 0) || (j == 4) || (i == 0) || (i == (n-1)))
            {
                printf("*");
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
}


PROBLEMA 4
Se citește un număr întreg n>2. 
Să se afișeze folosind steluțe litera N, formată cu laturile și diagonala unui pătrat de latură n. 

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

int main()
{
    int n, i, j;
    printf("Introduceti un numar de la tastatura: ");
    scanf("%d", &n);
    if(n < 2)
    {
        printf("Numarul introdus este prea mic.\n");
        exit(0);
    }
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            if((j == 0) || (j == 4) || (j == i))
            {
                printf("*");
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
}


PROBLEMA 5
Se citesc două numere întregi n și m, cu m>0 și n>m. Să se afișeze n numere care cresc 
de la 0 din 1 în 1 și dacă trec de m redevin 0, ciclul repetându-se. 
Exemplu pentru n==14 și m==3: 0 1 2 3 0 1 2 3 0 1 2 3 0 1


#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

int main()
{
    int n, m, i, j;
    printf("Introduceti un numar m de la tastatura: ");
    scanf("%d", &m);
    if(m < 0)
    {
        printf("Ati introdus un numar prea mic.\n");
        exit(0);
    }
    printf("Introduceti un numar n de la tastatura: ");
    scanf("%d", &n);
    if(n < m)
    {
        printf("Ati introdus un numar prea mic.\n");
        exit(0);
    }
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; i < n && j <= m; i++, j++)
        {
            printf("%d ", j);
        }
    }
    return 0;
}


PROBLEMA 6
Să se afișeze tabla înmulțirii pentru 
toate numerele de la 0 la 10 inclusiv, sub forma: 0*0=0, 0*1=0,..., 0*10=0, 1*0=0, 1*1=1, ... 10*10=100


#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main()
{
    int i, j;
    for(i = 0; i < 11; i++)
    {
        for(j = 0; j < 11; j++)
        {
            printf("%d * %d = %d\n", i, j, i*j);
        }
    }
    return 0;
}



PROBLEMA 7
Se citește un număr natural de 3 cifre. Să se determine câte cifre impare conține numărul dat. 

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main()
{
    int n, cifra, contor = 0;
    printf("Introduceti un numar natural de 3 cifre: ");
    scanf("%d", &n);
    if(n < 100 || n > 999)
    {
        printf("Ati introdus un numar in afara intervalului cerut.\n");
        exit(0);
    }
    while(n != 0)
    {
        cifra = n % 10;
        if(cifra % 2 != 0)
        {
            contor ++;
        }
        n = n / 10;
    }
    printf("Numarul dat are %d cifre impare.\n", contor);
    return 0;
}
*/

//Functie care sa transforme un nr in binar folosind un singur printf

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main()
{
    int binary[32], i = 0, j = 0, num;

    printf("Introduceti un numar zecimal: ");
    scanf("%d", &num);

    while (num > 0) 
    {
        binary[i] = num % 2;
        num = num / 2;
        i++;
    }
    printf("Reprezentarea binara a numarului este: ");
    for (j = i - 1; j >= 0; j--) 
    {
        printf("%d", binary[j]);
    }
    printf("\n");

    return 0;
}