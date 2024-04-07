/* PROBLEMA 3
Se citesc 2 numere reale x, y de la tastatură și ulterior se va afișa meniul de mai jos. După afișarea meniului, se cere un 
cod de operație și se va afișa rezultatul corespunzător acesteia.
1) Maximul dintre x si y
2) Minimul dintre x si y
3) x
4) y
De exemplu, pentru x = 19.5, y = 23 și codul 2, se va afișa minimul dintre x și y care este 19.5

#include <stdio.h>
#include <stdint.h>

int maxim(int a, int b)
{
    if(a > b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

int minim(int a, int b)
{
    if (a < b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

int main(void)
{
    float x, y, min, max;
    int n = 0;
    printf("Introduceti primul numar x: ");
    scanf("%f", &x);
    printf("Introduceti al doilea numar y: ");
    scanf("%f", &y);
    printf("1. Maximul dintre x si y\n2. Minimul dintre x si y\n3. x\n4. y\n");
    while(n < 1 || n > 4)
    {
        printf("Alegeti una dintre optiunile enumerate mai sus: ");
        scanf("%d", &n);
    }
    switch(n)
    {
        case 1:
        {
            max = maxim(x, y);
            printf("Maximul dintre cele doua numere este: %f", max);
            break;
        }
        case 2:
        {
            min = minim(x, y);
            printf("Minimul dintre cele doua numere este: %f", min);
            break;
        }
        case 3:
        {
            printf("Numarul x este: %d", x);
            break;
        }
        case 4:
        {
            printf("Numarul y este: %d", y);
        }
    }
    return 0;
}

PROBLEMA 4 Se citește pe rând câte un n întreg. Dacă n<0, se va afișa un mesaj de eroare și se va cere alt număr. 
Dacă n>0, să se afișeze dacă este par sau impar. Dacă n==0, programul se va termina. 

#include <stdio.h>
#include <stdint.h>

int main(void)
{
    int n;
    while(n != 0)
    {
        printf("Introduceti un numar n: ");
        scanf("%d", &n);
        if(n < 0)
        {
            printf("Eroare. Numarul introdus este negativ.\n");
            continue;
        }
        else
        {
            if(n%2==0)
            {
                printf("Numarul n introdus este par.\n");
            }
            else
            {
                printf("Numarul n introdus este impar.\n");
            }
        }
    }
    return 0;
}

PROBLEMA 5
Să se implementeze un calculator cu următoarele opțiuni: 1-Adunare, 2-Scădere, 3-Înmulțire, 4-Împărțire, 5-Ieșire. 
După ce se afișează pe ecran acest meniu, se va cere un cod de operație. 
Dacă s-a introdus 5, programul se va termina. Altfel, se cer două numere reale și se afișează rezultatul operației selectate. 

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

int main(void)
{
    float x, y, suma, diferenta, produsul, catul;
    int n;
    printf("Acesta este un calculator cu diferite optiuni.\n1.Adunare\n2.Scadere\n3.Inmultire\n4.Impartire\n5.Iesire\n");
    printf("Alegeti una dintre optiunile de mai sus: ");
    scanf("%d", &n);
    if(n < 1 || n > 4 || n == 5)
    {
        printf("Optiunea aleasa nu face parte din meniul calculatorului.\n");
        exit(0);
    }
    else
    {
        printf("Introduceti primul numar real x: ");
        scanf("%f", &x);
        printf("Introduceti al doilea numar real y: ");
        scanf("%f", &y);
        switch(n)
        {
            case 1:
            {
                suma = x + y;
                printf("Suma celor doua numere este: %f", suma);
                break;
            }
            case 2:
            {
                if(x > y)
                {
                    diferenta = x - y;
                }
                else
                {
                    diferenta = y - x;
                }
                printf("Diferenta dintre cele doua numere este: %f", diferenta);
            }
            case 3:
            {
                produsul = x * y;
                printf("Produsul dintre cele doua numere este: %f", produsul);
            }
            case 4:
            {
                if(x == 0 || y == 0)
                {
                    printf("Nu se poate efectua operatia de impartire.\n");
                    exit(0);
                }
                catul = x / y;
                printf("Catul dintre cele doua numere este: %f", catul);
            }
        }
    }
    scanf("%d", &n);
    return 0;
}

PROBLEMA 6
Se citesc două numere întregi. Să se afișeze dacă numerele au sau nu același semn. Numărul 0 se consideră pozitiv. 

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

int main(void)
{
    int a, b;
    printf("Introduceti primul numar: ");
    scanf("%d", &a);
    printf("Introduceti al doilea numar: ");
    scanf("%d", &b);
    if((a < 0 && b > 0) || (a > 0 && b < 0))
    {
        printf("Numerele nu au acelasi semn.\n");
    }
    else
    {
        printf("Numerele au acelasi semn.\n");
    }
    return 0;
}

PROBLEMA 7
Se citește un număr natural n. Să se determine cele mai mari două numere impare, mai mici decât n. 

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

int main(void)
{
    unsigned int n, imp1, imp2;
    printf("Introduceti un numar natural n: ");
    scanf("%d", &n);
    if(n % 2 == 0)
    {
        imp1 = n - 1;
        imp2 = n - 3;
        printf("Cele mai mari doua numere impare, mai mici decat n sunt: %d si %d", imp1, imp2);
    }
    else
    {
        imp1 = n - 2;
        imp2 = n - 4;
        printf("Cele mai mari doua numere impare, mai mici decat n sunt: %d si %d", imp1, imp2);
    }
    return 0;
}

PROBLEMA 8
Se cere un an n. Să se afișeze dacă anul este sau nu bisect. Anii bisecți se calculează pe baza următorului algoritm: 
fiecare an care se divide la 4 este un an bisect, exceptând anii care se divid la 100 și nu se divid la 400. 
De exemplu, anii 1600 și 1200 sunt ani bisecți, dar anii 1700, 1800 și 1900 nu sunt bisecți. 

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>


int bisect(int a)
{
    if(a % 4 != 0)
    {
        return 0;
    }
    else if((a % 100 == 0) && (a % 400 != 0))
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

int main(void)
{
    int n;
    printf("Introduceti anul: ");
    scanf("%d", &n);
    if(bisect(n))
    {
        printf("Anul este bisect.\n");
    }
    else
    {
        printf("Anul nu este bisect.\n");
    }
    return 0;
}

PROBLEMA 9
De la un magazin se cumpară x kg de mere si y kg de pere, cu x și y valori reale, introduse de la tastatură. 
Știind că 1kg de mere costă 5 lei și 1kg de pere costă 7 lei, să se verifice dacă suma de 20 de lei ajunge pentru cumpărarea fructelor. 

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

int main(void)
{
    float x, y, total;
    printf("Introduceti numarul de kg de mere, stiind ca 1 kg costa 5 lei: ");
    scanf("%f", &x);
    printf("Introduceti numarul de kg de pere, stiind ca 1 kg costa 7 lei: ");
    scanf("%f", &y);
    if(x < 0 || y < 0)
    {
        printf("Acest lucru este imposibil.\n");
        exit(0);
    }
    total = (x * 5) + (y * 7);
    if(total > 20)
    {
        printf("Ne pare rau, nu va ajung banii.\n");
    }
    else
    {
        printf("Felicitari, va ajung banii. Totalul dumneavoastra este %f lei", total);
    }
    return 0;
}

PROBLEMA 10
Se citesc 3 numere întregi de la tastatură x, y, z. Să se verifice dacă z este în interiorul intervalului [x,y). */

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

int main(void)
{
    int x, y, z;
    printf("Introduceti capatul din stanga al intervalului: ");
    scanf("%d", &x);
    printf("Introduceti capatul din dreapta al intervalului: ");
    scanf("%d", &y);
    printf("Introduceti numarul pe care doriti sa il verificati: ");
    scanf("%d", &z);
    if(z < x || z >= y)
    {
        printf("Numarul nu face parte din interval.\n");
    }
    else
    {
        printf("Numarul face parte din interval.\n");
    }
    return 0;
}