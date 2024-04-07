#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

/* OPERATII LAB 2*/

/* 3. Se citesc 2 numere reale x, y de la tastatură și ulterior se va afișa meniul de mai jos. După afișarea meniului, se cere un cod de operație și se va afișa rezultatul corespunzător acesteia.
1) Maximul dintre x si y
2) Minimul dintre x si y
3) x
4) y*/

float maxim(int a, int b)
{
    if(a == b)
    {
        return 21;
    }
    else if(a > b)
    {
        return a;
    }
    return b;
}

float minim(int a, int b)
{
    if(a == b)
    {
        return 21;
    }
    else if(a < b)
    {
        return a;
    }
    return b;
}

int main(void)
{
    return 0;
}

/* VECTORI LAB 6*/

/* 1. Să se scrie o funcție care ia un număr fără semn n și returnează numărul de segmente de biți consecutivi egali. 
Exemplu: 000100 are 3 segmente: 000, 1, 00, deci programul va returna 3

unsigned bitiEgali(unsigned n)
{
    unsigned contor = 0;
    unsigned prevBit = n & 1;  

    while (n != 0)
    {
        unsigned LSB = n & 1;

        if (LSB != prevBit)
        {
            contor++;
        }

        prevBit = LSB;
        n = n >> 1;
    }
    return contor;
}

int main(void)
{
    unsigned n, contor;

    printf("Introduceti numarul pe care doriti sa il testati:\n");
    scanf("%u", &n);

    contor = bitiEgali(n);
    printf("Numarul de segmente de biti consecutivi egali este: %u", contor);

    return 0;
} */

/* 2. Să se afișeze minimul elementelor din vectorul {7, -5, 4, 3, -9, 2, -8}.

int main(void)
{
    int v[] = {7, -5, 4, 3, -9, 2, -8};
    int n = 7;
    int i, imin = 0;

    for(i = 1; i < n; i++)
    {
        if(v[i] < v[imin])
        {
            imin = i;
        }
    }

    printf("Minimul elementelor din vector este %d\n", v[imin]);
    return 0;
}
*/

/*3. Să se citească de la tastatură un număr n<=10 iar apoi n valori de tip int. Să se afișeze dacă toate valorile pozitive sunt pare.

int main(void)
{
    unsigned int n;
    int i;
    int v[11];

    printf("Introduceti numarul de elemente ale vectorului:\n");
    scanf("%u", &n);

    if((n <= 0) || (n > 10))
    {
        printf("Ati introdus un numar din afara intervalului.\n");
        return 1;
    }
    else
    {
        for(i = 0; i < n; i++)
        {
            printf("Introduceti elementul %d:\n", i + 1);
            scanf("%d", &v[i]);
        }

        for(i = 0; i < n; i++)
        {
            if(v[i] >= 0)
            {
                if(v[i] % 2 != 0)
                {
                    break;
                }
            }
        }

        if(i == n)
        {
            printf("Toate valorile pozitive sunt pare.\n");
        }
        else
        {
            printf("Exista anumite valori pozitive care nu sunt pare.\n");
        }
    }
    return 0;
}
*/

/* 4. Se citește un număr k. Să se afișeze dacă în vectorul {7, -5, 4, 3, -9, 2, -8} există cel puțin un număr mai mare decat k.

int main(void)
{
    int v[] = {7, -5, 4, 3, -9, 2, -8};
    int n = 7;
    int i;
    int k;

    printf("Introduceti numarul cu care doriti sa comparati elementele.\n");
    scanf("%d", &k);

    for(i = 0; i < n; i++)
    {
        if(v[i] > k)
        {
            break;
        }
    }

    if(i == n)
    {
        printf("Nu exista niciun numar mai mare decat k in vector.\n");
    }
    else
    {
        printf("Exista cel putin un numar mai mare decat k in vector.\n");
    }
    return 0;
} */

/* 5. Se citesc 2 numere x și y cu x<y. Să se afișeze minimul elementelor din vectorul {7, -5, 4, 3, -9, 2, -8}, 
care se află în același timp și în intervalul [x,y].

int main(void)
{
    int v[] = {7, -5, 4, 3, -9, 2, -8};
    int n = 7;
    int i;
    int imin = 0;
    int x, y;
    
    printf("Introduceti capatul inferior al intervalului, x:\n");
    scanf("%d", &x);

    printf("Introduceti capatul superior al intervalului, y:\n");
    scanf("%d", &y);

    if(x >= y)
    {
        printf("Ati introdus numere care nu pot fi capete de interval.\n");
        return 1;
    }
    else
    {
        for(i = n; i >= 1; i--)
        {
            if((v[i-1] >= x) && (v[i-1] <= y))
            {
                if(v[i - 1] < v[imin])
                {
                    imin = i - 1;
                }
            }
        }

        printf("Valoarea minima din vector aflata si in interval este %d\n", v[imin]);
    }
    return 0;
} */

/* 6. Să se citească de la tastatură un număr n<=5 iar apoi n valori de tip intreg. 
Să se afișeze toate valorile ale căror modul (valoare absolută) este strict mai mare decat 10.

int main(void)
{
    int v[6];
    int n;
    int i;
    int flag = 0;

    printf("Introduceti numarul de elemente ale vectorului:\n");
    scanf("%d", &n);

    if((n <= 0) || (n > 5))
    {
        printf("Ati introdus o valoare care nu corespunde cerintelor.\n");
        return 1;
    }
    else
    {
        for(i = 0; i < n; i++)
        {
            printf("Introduceti elementul cu numarul %d:\n", i + 1);
            scanf("%d", &v[i]);
        }

        for(i = 0; i < n; i++)
        {
            if((v[i] < -10) || (v[i] > 10))
            {
                printf("%d ", v[i]);
                flag++;
            }
        }

        if(flag == 0)
        {
            printf("Nu exista valori in vector care sa corespunda acestei conditii.\n");
        }
    }
    return 0;
}*/

/*Se citește un număr n (n<=10) și apoi n numere întregi. 
Se cere să se sorteze aceste numere astfel încât numerele impare să fie înaintea celor pare

int main(void)
{
    int v[12];
    int n;
    int i;
    int s;
    int aux;

    printf("Introduceti numarul de elemente ale vectorului:\n");
    scanf("%d", &n);

    if((n <= 0) || (n > 10))
    {
        printf("Ati introdus un numar care nu corespunde cerintei.\n");
        return 1;
    }
    else
    {
        for(i = 0; i < n; i++)
        {
            printf("Introduceti elementul cu numarul %d:\n", i+1);
            scanf("%d", &v[i]);
        }

        do
        {
            s = 0;
            for(i = 1; i < n; i++)
            {
                if((v[i-1] % 2 == 0) && (v[i] % 2 != 0))
                {
                    aux = v[i-1];
                    v[i-1] = v[i];
                    v[i] = aux;
                    s = 1;
                }
            }
        }while(s);

        printf("Valorile aranjate sunt:\n");

        for(i = 0; i < n; i++)
        {
            printf("%d ", v[i]);
        }
    }
    return 0;
}*/

/* 8. Se citește un număr n<=10 și apoi n numere întregi. Se cere să se șteargă din vector toate acele elemente 
care sunt urmate de un număr strict mai mare decât ele, păstrându-se ordinea elementelor

int main(void)
{
    int v[12];
    int n;
    int i;
    int j;

    printf("Introduceti numarul de elemente ale vectorului:\n");
    scanf("%d", &n);

    if((n <= 0) || (n > 10))
    {
        printf("Ati introdus o valoare care nu corespunde cerintei.\n");
        return 1;
    }
    else
    {
        for(i = 0; i < n; i++)
        {
            printf("Introduceti elementul cu numarul %d:\n", i+1);
            scanf("%d", &v[i]);
        }

        for(i = 0; i < n; i++)
        {
            if(v[i+1] > v[i])
            {
                for(j = i + 1; j < n; j++)
                {
                    v[j - 1] = v[j];
                }
                n--;
                i--;
            }
        }

        printf("Vectorul modificat:\n");

        for(i = 0; i < n; i++)
        {
            printf("%d ", v[i]);
        }
    }
    return 0;
}*/

/*9. Se citește un număr n<=10 și apoi n numere pozitive. 
Se cere să se insereze înainte de fiecare valoare impară din vectorul original valoarea 0.

int main(void)
{
    int v[13];
    int n;
    int i;
    int j;

    printf("Introduceti numarul de elemente ale vectorului:\n");
    scanf("%d", &n);

    if((n <= 0) || (n > 10))
    {
        printf("Ati introdus un numar care nu corespunde cerintei.\n");
        return 1;
    }
    else
    {
        for(i = 0; i < n; i++)
        {
            printf("Introduceti elementul cu numarul %d:\n", i+1);
            scanf("%d", &v[i]);
        }

        for(i = 0; i < n; i++)
        {
            if(v[i] < 0)
            {
                printf("Elementele vectorului trebuie sa fie numere pozitive.\n");
                return 1;
            }
            else
            {
                if(v[i] % 2 != 0)
                {
                    for (j = n; j > i; j--)
                    {                                      
                        v[j] = v[j - 1];                                               
                    }
                    v[i] = 0;                                                   
                    n++;                                                           
                    i++;
                }
            }
        }

        printf("Vectorul modificat este:\n");

        for(i = 0; i < n; i++)
        {
            printf("%d ", v[i]);
        }
    }
    return 0;
}*/

/* 10. Se citește un număr n<=10 și apoi n numere întregi, inclusiv negative. 
Se cere să se sorteze aceste numere astfel încât numerele pozitive să fie înaintea celorlalte numere.

int main(void)
{
    int v[11];
    int n;
    int i;
    int s;
    int aux;

    printf("Introduceti numarul de elemente ale vectorului:\n");
    scanf("%d", &n);

    if((n <= 0) || (n > 10))
    {
        printf("Ati introdus o valoare care nu corespunde cerintei.\n");
        return 1;
    }
    else
    {
        for(i = 0; i < n; i++)
        {
            printf("Introduceti elementul cu numarul %d:\n", i+1);
            scanf("%d", &v[i]);
        }

        do
        {
		    s = 0;                             
		    for(i = 1; i < n; i++)
		    {      
			    if ((v[i - 1] < 0) && (v[i] >= 0))
			{             
				aux = v[i - 1];                 
				v[i - 1] = v[i];
				v[i] = aux;
				s = 1;                            
			}
		}
	    } while (s);  

        printf("Vectorul modificat:\n");

        for(i = 0; i < n; i++)
        {
            printf("%d ", v[i]);
        }                       
    }
    return 0;
}*/

/* 11. Se citește un număr n<=10 și apoi n numere întregi. 
Se cere să se șteargă toate duplicatele (ori de câte ori apar acestea) din vector, păstrându-se ordinea elementelor.

int main(void)
{
    int v[11];
    int n;
    int i;
    int j;
    int k;

    printf("Introduceti numarul de elemente ale vectorului:\n");
    scanf("%d", &n);

    if((n <= 0) || (n > 10))
    {
        printf("Ati introdus o valoare care nu corespunde cerintei.\n");
        return 1;
    }
    else
    {
        for(i = 0; i < n; i++)
        {
            printf("Introduceti elementul cu numarul %d:\n", i+1);
            scanf("%d", &v[i]);
        }

        for(i = 0; i < n; i++)
        {
            for(j = i + 1; j < n;)
            {
                if(v[i] == v[j])
                {
                    for(k = j; k < n - 1; k++)
                    {
                        v[k] = v[k+1];
                    }
                    n--;
                }
                else
                {
                    j++;
                }
            }
        }

        printf("Vectorul modificat:\n");

        for(i = 0; i < n; i++)
        {
            printf("%d ", v[i]);
        }
    }
    return 0;
}*/

/*12. Se citește un număr n<=10 și apoi n numere întregi. Se cere să se insereze după fiecare valoare din vectorul original pătratul ei.

int main(void)
{
    int v[11];
    int n;
    int i;
    int j;
    
    printf("Introduceti numarul de elemente ale vectorului:\n");
    scanf("%d", &n);

    if((n <= 0) || (n > 10))
    {
        printf("Ati introdus o valoare care nu corespunde cerintei.\n");
        return 1;
    }
    else
    {
        for(i = 0; i < n; i++)
        {
            printf("Introduceti elementul cu numarul %d:\n", i+1);
            scanf("%d", &v[i]);
        }

        for (i = 0; i < n; i++)
        {
            for (j = n; j > i + 1; j--)
            {                                      
                v[j] = v[j - 1];                                               
            }
            v[i+1] = v[i]*v[i];                                                 
            n++;                                                           
            i++;
        }

        printf("Vectorul modificat:\n");

        for(i = 0; i < n; i++)
        {
            printf("%d ", v[i]);
        }
    }
    return 0;
}*/

/* 13. Se citește un număr n<=10 și apoi n perechi de numere întregi. 
Se cere să se insereze după fiecare pereche din vectorul original suma și apoi produsul numerelor din pereche.

int main(void)
{
    int v[22];
    int n;
    int m;
    int i;
    int q = 1;
    int j;

    printf("Introduceti numarul de perechi ale vectorului:\n");
    scanf("%d", &n);

    if((n <= 0) || (n > 10))
    {
        printf("Ati introdus o valoare care nu corespunde cerintei.\n");
        return 1;
    }
    else
    {
        int m = 2 * n;
        for(i = 0; i < m; i++)
        {
            if(i % 2 == 0)
            {
                printf("Introduceti elementul 1 din perechea %d:\n", q);
                scanf("%d", &v[i]);
            }
            else
            {
                printf("Introduceti elementul 2 din perechea %d:\n", q);
                scanf("%d", &v[i]);
                q++;
            }
        }

        for (i = 1; i < m; i = i + 3)
        {
            for (j = m + 1; j > i + 3; j = j - 2)
            {                                      
                v[j] = v[j - 2];
                v[j - 1] = v[j - 3];                                              
            }
            v[i+1] = v[i] + v[i-1];
            v[i+2] = v[i] * v[i-1];                                                   
            m = m + 2;                                                           
            i++;
        }

        printf("Vectorul modificat:\n");

        for(i = 0; i < m; i++)
        {
            printf("%d ", v[i]);
        }
    }
    return 0;
}*/

/* POINTERI LAB 7*/

/* 1. Se citesc două variabile, a și b, de tip întreg. 
Să se stocheze într-un pointer adresa variabilei care conține valoarea maximă și apoi să se afișeze valoarea pointată

int main(void)
{
    int a, b;
    int *p = NULL;

    printf("Introduceti valoarea primului numar, a:\n");
    scanf("%d", &a);
    printf("Introduceti valoarea celui de-al doilea numar, b:\n");
    scanf("%d", &b);

    if(a > b)
    {
        p = &a;
    }
    else
    {
        p = &b;
    }

    printf("Valoarea pointata este %d, cu adresa %p", *p, p);
    return 0;
}*/

/* 2. Să se scrie un program care citește un număr n<10 iar apoi citește 2 vectori v1 și v2 de câte n elemente de tip int. 
Pentru citirea elementelor unui vector se folosește o funcție citire(v,n). 
Se va implementa o funcție egal(v1,v2,n), care testează dacă toate elementele din v1 sunt egale cu cele din v2 la poziții corespondente.

int citire(int *v, int size)
{
    int i; 
    int c = 0;
    for(i = 0; i < size; i++)
    {
        printf("Introduceti elementul cu numarul %d:\n", i+1);
        c = scanf("%d", (v + i));
        if(c != 1)
        {
            return i;
        }
    }
    return;
}

int egal(int *v1, int *v2, int size)
{
    int i;
    int flag = 0;

    for(i = 0; i < size; i++)
    {
        if(*(v1 + i) != *(v2 + i))
        {
            flag = 1;
        }
    }
    return flag;
}

int main(void)
{
    int n;
    static int v1[11], v2[11];
    int verificare1, verificare2;
    int egalitate;

    printf("\nIntroduceti numarul de elemente ale vectorilor:\n");
    scanf("%d", &n);

    if((n <= 0) || (n >= 10))
    {
        printf("Ati introdus o valoare care nu corespunde cerintei.\n");
        return 1;
    }
    else
    {
        printf("\nIntroduceti elementele primului vector\n");
        verificare1 = citire(v1, n);
        printf("\nPentru primul vector s-au citit %d numere din %d.\n", verificare1, n);

        printf("\nIntroduceti elementele celui de-al doilea vector\n");
        verificare2 = citire(v2, n);
        printf("\nPentru al doilea vector s-au citit %d numere din %d.\n", verificare2, n);

        egalitate = egal(v1, v2, n);
        if(egalitate == 0)
        {
            printf("Elementele vectorilor sunt egale la pozitii corespondente.\n");
        }
        else
        {
            printf("Elementele vectorilor nu sunt egale la pozitii corespondente.\n");
        }
    }
    return 0;
}*/

/* Exemplu: Un program care citește valori până când întâlnește 0 (exclusiv), după care afișează aceste valori în ordine inversă. 
Programul va fi implementat atât cu indecși, cât și cu pointeri, pentru a se ilustra diferențele dintre cele două moduri de abordare.*/

/* VARIANTA CU INDECSI 

int main(void)
{
    int v[15];
    int i;
    int size = 0;

    for(;;)
    {
        printf("Introduceti elementul cu numarul %d:\n", size);
        scanf("%d", &v[size]);
        if(v[size] == 0)
        {
            break;
        }
        size++;
    }

    printf("Tabloul initial:\n");
    for(i = 0; i < size; i++)
    {
        printf("%d ", v[i]);
    }
    printf("\n");

    printf("Tabloul inversat:\n");
    for(i = size - 1; i >= 0; i--)
    {
        printf("%d ", v[i]);
    }
    return 0;
}*/

/* VARIANTA CU POINTERI 

int main(void)
{
    static int v[15];
    int i;
    int size = 0;

    for(;;)
    {
        printf("Introduceti elementul cu numarul %d:\n", size);
        scanf("%d", (v + size));
        if(*(v + size) == 0)
        {
            break;
        }
        size++;
    }

    printf("Tabloul initial:\n");
    for(i = 0; i < size; i++)
    {
        printf("%d ", *(v + i));
    }
    printf("\n");

    printf("Tabloul inversat:\n");
    for(i = 0; i < size; i++)
    {
        printf("%d ", *(v + size - 1 - i));
    }
    return 0;
}*/

/* Exemplu: Să se scrie o funcție care primește ca parametru un vector de tip float și numărul său de elemente și 
returnează 1 (true) dacă toate valorile sunt pozitive sau 0 (false) dacă există și valori negative în vector. 
Se va testa funcția folosind un program care cere un n<=10 și apoi n elemente de tip float.*/

/* VARIANTA CU INDECSI 

int citire(float v[], int size)
{
    int i;
    int c = 0;
    for(i = 0; i < size; i++)
    {
        printf("Introduceti elementul cu numarul %d:\n", i+1);
        c = scanf("%g", &v[i]);
        if(c != 1)
        {
            return i;
        }
    }
    return;
}

int verif(float v[], int size)
{
    int i;
    for(i = 0; i < size; i++)
    {
        if(v[i] < 0)
        {
            return 0;
        }
    }
    return 1;
}

int main(void)
{
    float v[15];
    int n;
    int i;
    int verificare;

    printf("Introduceti numarul de elemente ale vectorului:\n");
    scanf("%d", &n);

    if((n <= 0) || (n > 10))
    {
        printf("Ati introdus o valoare care nu corespunde cerintei.\n");
        return 1;
    }
    else
    {
        printf("\nIntroduceti elementele vectorului:\n");
        printf("\n");
        verificare = citire(v, n);
        printf("\nS-au citit %d elemente din %d.\n", verificare, n);

        if(verif(v, n))
        {
            printf("Toate valorile sunt pozitive.\n");
        }
        else
        {
            printf("Exista si valori negative.\n");
        }
    }
    return 0;
}*/

/* VARIANTA CU POINTERI 

int citire(float *v, int size)
{
    int i;
    int c = 0;
    for(i = 0; i < size; i++)
    {
        printf("Introduceti elementul cu numarul %d:\n", i);
        c = scanf("%g", (v + i));
        if(c != 1)
        {
            return i;
        }
    }
    return;
}

int verif(float *v, int size)
{
    int i;
    for(i = 0; i < size; i++)
    {
        if(*(v + i) < 0)
        {
            return 0;
        }
    }
    return 1;
}

int main(void)
{
    float v[15];
    int n;
    int i;
    int verificare;

    printf("Introduceti numarul de elemente ale vectorului:\n");
    scanf("%d", &n);

    if((n <= 0) || (n > 10))
    {
        printf("Ati introdus o valoare care nu corespunde cerintei.\n");
        return 1;
    }
    else
    {
        printf("\nIntroduceti elementele vectorului:\n");
        printf("\n");
        verificare = citire(v, n);
        printf("\nS-au citit %d elemente din %d.\n", verificare, n);

        if(verif(v, n))
        {
            printf("Toate valorile sunt pozitive.\n");
        }
        else
        {
            printf("Exista si valori negative.\n");
        }
    }
    return 0;
}*/

/* 3. Să se citească de la tastatură două variabile de tip double (se citește cu %lf, nu cu %g!!!) și 
să se afișeze numele variabilei care se află la adresa cea mai mică de memorie utilizând pointeri.

int main(void)
{
    double a, b;
    double *p, *q;

    printf("Introduceti valoarea lui a:\n");
    scanf("%lf", &a);
    printf("Introduceti valoarea lui b:\n");
    scanf("%lf", &b);
    p = &a;
    q = &b;
    if(p < q)
    {
        printf("%p e mai mica decat %p.\n", p, q);
        printf("a");
    }
    else
    {
        printf("%p e mai mica decat %p.\n", q, p);
        printf("b");
    }
    return 0;
}*/

/* 4. Scrieți un program care interschimbă valorile a două variabile de tip întreg utilizând pointeri

void swap(int *a, int *b)
{
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

int main(void)
{
    int a, b;

    printf("Introduceti valoarea lui a:\n");
    scanf("%d", &a);
    printf("Introduceti valoarea lui b:\n");
    scanf("%d", &b);

    printf("Valori initiale:\n");
    printf("a = %d\n", a);
    printf("b = %d\n", b);

    swap(&a, &b);

    printf("Valori dupa schimbare:\n");
    printf("a = %d\n", a);
    printf("b = %d\n", b);

    return 0;
}*/

/* 5. Să se afișeze câte elemente negative sunt în vectorul {7, -5, 4, 3, -9, 2, -8} utilizând pointeri, fără indecși. 
(Fără indecși înseamnă că în cod nu va exista niciun v[i])

int negative(int *v, int size)
{
    int i;
    int contor = 0;
    for(i = 0; i < size; i++)
    {
        if(*(v + i) < 0)
        {
            contor++;
        }
    }
    return contor;
}

int main(void)
{
    int v[] = {7, -5, 4, 3, -9, 2, -8};
    int n = 7;
    int cate;

    cate = negative(v, n);
    printf("Sunt %d elemente negative in vector.\n", cate);
    return 0;
}*/

/* 6. Să se afișeze minimul elementelor din vectorul {7, -5, 4, 3, -9, 2, -8} utilizând pointeri, fără indecși.

int min_vector(int *v, int size)
{
    int i;
    int minim = v;
    for(i = 1; i < size; i++)
    {
        if(*(v + i) < minim)
        {
            minim = *(v + i);
        }
    }
    return minim;
}

int main(void)
{
    int v[] = {7, -5, 4, 3, -9, 2, -8};
    int n = 7;
    int m;

    m = min_vector(v, n);
    printf("Minimul elementelor din vector este: %d.\n", m);
    return 0;
}*/

/* 7.  Se citește un număr n (n<=10) și apoi n numere întregi. Se cere să se sorteze aceste numere în ordine descrescătoare 
utilizând pointeri, fără indecși. 
(Inclusiv citirea se va face cu pointeri.)

int citire(int *v, int size)
{
    int i;
    int c = 0;
    for(i = 0; i < size; i++)
    {
        printf("Introduceti elementul cu numarul %d:\n", i+1);
        c = scanf("%d", (v + i));
        if(c != 1)
        {
            return i;
        }
    }
    return;
}

void BubbleSort(int *v, int size)
{
	int s;
    int i;
    int aux;

	do
    {
		s = 0;                             
		for (i = 1; i < size; i++)
		{      
			if (*(v + i - 1) < *(v + i))
			{             
				aux = *(v + i - 1);                 
				*(v + i - 1) = *(v + i);
				*(v + i) = aux;
				s = 1;                             
			}
		}
	} while (s);                         
}

void afisare(int *v, int size)
{
    int i;
    for(i = 0; i < size; i++)
    {
        printf("%d ", *(v + i));
    }
}

int main(void)
{
    int n;
    static int v1[11];
    int verificare1;

    printf("\nIntroduceti numarul de elemente ale vectorului:\n");
    scanf("%d", &n);

    if((n <= 0) || (n >= 10))
    {
        printf("Ati introdus o valoare care nu corespunde cerintei.\n");
        return 1;
    }
    else
    {
        printf("\nIntroduceti elementele\n");
        verificare1 = citire(v1, n);
        printf("\nS-au citit %d numere din %d.\n", verificare1, n);

        printf("Vectorul initial\n");
        afisare(v1, n);
        printf("\n");

        BubbleSort(v1, n);

        printf("Vectorul dupa sortare\n");
        afisare(v1, n);
        printf("\n");
    }
    return 0;
}*/

/* 8. Să se șteargă din vectorul {5, 8, 1, 4, 2, 6, 9} toate elementele pare, 
păstrând neschimbată ordinea elementelor, după care să se afișeze noul vector. Utilizați pointeri, fără indecși.

int stergere(int *v, int size)
{
    int i;
    int j;

    for (i = 0; i < size; i++)
    {
        if(*(v + i) % 2 == 0)
        {
            for(j = i + 1; j < size; j++)
            {
                *(v + j - 1) = *(v + j);
            }
            size--;
            i--;
        }
    }
    return size;
}

void afisare(int *v, int size)
{
    int i;
    for(i = 0; i < size; i++)
    {
        printf("%d ", *(v + i));
    }
}

int main(void)
{
    int v[] = {5, 8, 1, 4, 2, 6, 9};
    int n = 7;
    int n_nou;

    printf("Vectorul initial\n");
    afisare(v, n);
    printf("\n");

    n_nou = stergere(v, n);

    printf("Vectorul dupa stergere\n");
    afisare(v, n_nou);
    printf("\n");
    return 0;
}*/

/* 9. 
                REVIZUIESTE AFISEAZA IN LOC DE 3 14
Se dă vectorul {7, -5, 4, 3, -9, 2, -8}. 
Să se insereze înainte de fiecare valoare din vectorul original negativul ei. Utilizați pointeri, fără indecși.

int inserare(int *v, int size)
{
    int i, j;
    for (i = 0; i < size; i++)
    {
        size++; 
        for (j = size; j > i; j--)
        {                                      
            *(v + j) = *(v + j - 1);                                               
        }
        *(v + i) = -(*(v + i));                                                                                                             
        i++;
    }
    return size;
}

void afisare(int *v, int size)
{
    int i;
    for(i = 0; i < size; i++)
    {
        printf("%d ", *(v + i));
    }
}

int main(void)
{
    int v[] = {7, -5, 4, 3, -9, 2, -8};
    int n = 7;
    int n_nou;

    printf("Vectorul initial\n");
    afisare(v, n);
    printf("\n");

    n_nou = inserare(v, n);

    printf("Vectorul dupa inserare\n");
    afisare(v, n_nou);
    printf("\n");
    return 0;
}*/

/* 
                REVIZUIESTE AFISEAZA DE MAI MULTE ORI VALOAREA CARE ARE MAI MULTE DUPLICATE
10. Se citesc n<=10 valori întregi. Folosind doar pointeri, fără niciun fel de indexare, 
să se afișeze toate valorile care au cel puțin un duplicat. (Inclusiv citirea se va face cu pointeri.)

int citire(int *v, int size)
{
    int i;
    int c = 0;
    
    for(i = 0; i < size; i++)
    {
        printf("Introduceti elementul cu numarul %d\n", i+1);
        c = scanf("%d", (v + i));
        if(c != 1)
        {
            return i;
        }
    }

    return;
}

void duplicate(int *v, int size)
{
    int i;
    int j;

    for(i = 0; i < size; i++)
    {
        for(j = i + 1; j < size; j++)
        {
            if(*(v + i) == *(v + j))
            {
                printf("%d ", *(v + i));
            }
        }
    }
}

void afisare(int *v, int size)
{
    int i;

    for(i = 0; i < size; i++)
    {
        printf("%d ", *(v + i));
    }

    printf("\n");
}

int main(void)
{
    int v[11];
    int n;
    int verificare;

    printf("Introduceti numarul de elemente ale vectorului:\n");
    scanf("%d", &n);

    if((n <= 0) || (n > 10))
    {
        printf("Ati introdus o valoare care nu corespunde cerintei.\n");
        return 1;
    }
    else
    {
        printf("Introduceti elementele vectorului\n");
        printf("\n");
        verificare = citire(v, n);
        printf("\nS-au citit %d numere din %d\n", verificare, n);

        printf("\nVectorul introdus\n");
        afisare(v, n);

        printf("\nElementele duplicate\n");
        duplicate(v, n);
    }
    return 0;
}*/

/* 11. Să se implementeze, fără a se folosi variabile index, un program cu următorul meniu:
1. Citire - citește o valoare reală și o adaugă într-un vector cu maxim 100 de elemente
2. Afișare - afișează toate valorile din vector
3. Ștergere - citește o valoare și șterge toate elementele egale cu valoarea citită
4. Ieșire 

void citire(float *v, int *size)
{
    if(*size <= 100) 
    {
    printf("Introduceti o valoare reala\n");
    scanf("%f", (v + *size));
    (*size)++;
    printf("Valoarea a fost adaugata cu succes.\n");
    }
    else
    {
        printf("Vectorul este deja plin.\n");
    }
}

void afisare(float *v, int size)
{
    if(size == 0)
    {
        printf("Vectorul este gol.\n");
    }
    else
    {
        int i = 0;
        printf("Vectorul este:\n");
        for(i = 0; i < size; i++)
        {
            printf("%f ", *(v + i));
        }
        printf("\n");
    }
}

void stergere(float *v, int *size)
{
    int i;
    int j;
    float valoare;

    printf("Introduceti valoarea pe care doriti sa o stergeti:\n");
    scanf("%f", &valoare);

    for(i = 0; i < *size; i++)
    {
        if(*(v + i) == valoare)
        {
            for(j = i + 1; j < *size; j++)
            {            
                *(v + j - 1) = *(v + j);
            }
            (*size)--;                                  
            i--;     
        }
    }
}

int main(void)
{
    int n;
    float v[100];
    int size = 0;

    printf("\n1. Citire\n2. Afisare\n3.Stergere\n4.Iesire\n");
    
    do
    {
        printf("\nAlegeti optiunea:\n");
        scanf("%d", &n);

        switch(n)
        {
            case 1:
            {
                citire(v, &size);
                break;
            }
            case 2:
            {
                afisare(v, size);
                break;
            }
            case 3:
            {
                stergere(v, &size);
                break;
            }
            case 4:
            {
                printf("La revedere!\n");
                break;
            }
            default:
            {
                printf("Ati introdus o valoare inexistenta.\n");
                return 1;
            }
        }
    } while (n != 4);

    return 0;
} */

/* 12. Să se implementeze, fără a se folosi indecși, următorul program: se citește pe rând câte o valoare întreagă și se 
inserează într-un vector, astfel încât vectorul să fie mereu sortat crescător. După fiecare inserare se va afișa noul vector. 
Programul se termină la citirea valorii 0. Presupunem că vectorul va avea maxim 100 de elemente.

#define MAX_SIZE 100

void insert_and_print_sorted(int *v, int size, int valoare) 
{
    v[size] = valoare;
    size++;
    int i;
    int j;
    int tmp;

    for (i = 0; i < size - 1; i++) 
    {
        for (j = 0; j < size - i - 1; j++) 
        {
            if (*(v + j) > *(v + j + 1)) 
            {
                tmp = *(v + j);
                *(v + j) = *(v + j + 1);
                *(v + j + 1) = tmp;
            }
        }
    }

    printf("Vectorul sortat:\n");
    for (i = 0; i < size; i++) 
    {
        printf("%d ", *(v + i));
    }
    printf("\n");
}

int main() {
    int v[MAX_SIZE];
    int size = 0;
    int valoare;

    while (1) 
    {
        printf("Introduceti o valoare intreaga (0 pentru a termina):\n");
        scanf("%d", &valoare);

        if (valoare == 0) 
        {
            printf("Programul s-a incheiat.\n");
            break;
        }

        if (size < MAX_SIZE) 
        {
            insert_and_print_sorted(v, size, valoare);
            size++;
        } 
        else 
        {
            printf("Vectorul este plin. Programul se incheie.\n");
            break;
        }
    }
    return 0;
}*/

/* PROBLEME TEST COD 2*/

/* 13. Sa se implementeze o functie care primeste ca parametru un tablou de intregi fara semn pe 16 biti A, un intreg N 
reprezentand numarul de elemente si un intreg pe 8 biti fara semn x. 
Functia va returna cate elemente din tablou au cei mai putin semnificativi 8 biti identici cu valoarea x. 
Testarea programului se va realiza printr-un tablou generat cu numere aleatoare din intervalul 0...60000. 
Numarul x va fi citit de la tastatura. 
Dimensiunea maxima a tabolului va fi constanta, configurabila printr-un macro (define).

#define MAX_SIZE 100

void print_bit_16 (uint16_t nr)
{
  uint16_t mask = 0x8000; 
  uint8_t i = 0;
  for (i = 0; i < 16; i++)
    {
      if ((nr & mask) == 0)
        {
          printf ("0");
        }
      else
        {
          printf ("1");
        }
      mask = mask >> 1; 
    }
  printf ("\n");
}

void populare(uint16_t *A, int N)
{
    int i;
    srand(time(NULL));

    for(i = 0; i < N; i++)
    {
        (*(A + i)) = rand()%60000;
    }
}

void afisare(uint16_t *A, int N)
{
    int i;

    printf("Vectorul populat\n");

    for(i = 0; i < N; i++)
    {
        printf("%hd", *(A + i));
        printf("\n");
        print_bit_16(*(A + i));
        printf("\n");
        print_bit_16((*(A + i)) & 0x00FF);
        printf("\n");
    }
    printf("\n");
}

int contor(uint16_t *A, int N, uint8_t x)
{
    int contor = 0;
    int i;

    for(i = 0; i < N; i++)
    {   
        uint16_t aux = A[i];
        aux = aux & 0x00FF;
        printf(" BAJSHASDA ");
        if(aux == x)
        {
            contor++;
        }
    }
    return contor;
}

int main(void)
{
    uint16_t A[MAX_SIZE];
    int N;
    uint8_t x;
    int count;

    printf("Introduceti numarul de elemente ale vectorului\n");
    scanf("%d", &N);

    if((N <= 0) || (N > MAX_SIZE))
    {
        printf("Ati introdus o valoare care nu corespunde cerintelor.\n");
        return 1;
    }
    else
    {
        populare(A, N);
            
        afisare(A, N);

        printf("Introduceti valoarea celor 8 biti:\n");
        scanf("%hhu", &x);
        printf("Valoarea lui x pe biti:\n");
        print_bit_16(x);
        count = contor(A, N, x);

        if(x >= 256)
        {
            printf("Ati introdus o valoare prea mare.\n");
            return 1;
        }
        else
        {
            printf("%d elemente din tablou au cei mai putin semnificativi 8 biti identici cu valoarea lui x.\n", count);
        }
    }
    return 0;
}*/

/* Scrieti functii care folosesc doar aritmetica de pointeri si realizeaza urmatoarele functionalitati:
1. Citeste valori de la stdin
2. Afiseaza valori 
3. Maxim
4. Minim
5. Sortare

#define MAX_SIZE 100

int read_array_stdin(int *v, int size)
{
    int i;
    int c = 0;

    for(i = 0; i < size; i++)
    {
        printf("Introduceti elementul cu numarul %d:\n", i+1);
        c = scanf("%d", (v + i));
        if(c != 1)
        {
            return i;
        }
    }
}

void generate_random(int *v, int size)
{
    int i;
    srand(time(NULL));

    for(i = 0; i < size; i++)
    {
        *(v + i) = rand()%200;
    }
}

void afiseaza(int *v, int size)
{
    int i;

    for(i = 0; i < size; i++)
    {
        printf("%d ", *(v + i));
    }

    printf("\n");
}

int maxim(int *v, int size)
{
    int i;
    int indicemax = 0;

    for(i = 1; i < size; i++)
    {
        if(*(v + i) > *(v + indicemax))
        indicemax = i;
    }

    return *(v + indicemax);
}

int minim(int *v, int size)
{
    int i;
    int indicemin = 0;

    for(i = 1; i < size; i++)
    {
        if(*(v + i) < *(v + indicemin))
        indicemin = i;
    }

    return *(v + indicemin);
}

void sortare(int *v, int size)
{
	int s;
    int i;
    int aux;

	do
    {
		s = 0;                         
		for (i = 1; i < size; i++)
		{      
			if (*(v + i - 1) > *(v + i))
			{             
				aux = *(v + i - 1);                 
				*(v + i - 1) = *(v + i);
				*(v + i) = aux;
				s = 1;                             
			}
		}
	} while (s);                         
}

int main(void)
{
    int v[MAX_SIZE], a[MAX_SIZE];
    int n;
    int verificare;
    int max1, max2, min1, min2;

    printf("Introduceti numarul de elemente ale vectorului:\n");
    scanf("%d", &n);

    if((n <= 0) || (n > MAX_SIZE))
    {
        printf("Ati introdus o valoare care nu corespunde cerintei.\n");
        return 1;
    }
    else
    {
        printf("Vectorul v\n");

        verificare = read_array_stdin(v, n);
        if(verificare == n)
        {
            printf("Elementele s-au citit cu succes.\n");
        }
        else
        {
            printf("Citirea a intampinat probleme.\n");
        }

        printf("Vectorul initial\n");
        afiseaza(v, n);

        max1 = maxim(v, n);
        printf("Maximul din vector este %d\n", max1);

        min1 = minim(v, n);
        printf("Minimul din vector este %d\n", min1);

        printf("Vectorul sortat\n");
        sortare(v, n);
        afiseaza(v, n);

        printf("Vectorul a\n");

        generate_random(a, n);

        printf("Vectorul initial\n");
        afiseaza(a, n);

        max2 = maxim(a, n);
        printf("Maximul din vector este %d\n", max2);

        min2 = minim(a, n);
        printf("Minimul din vector este %d\n", min2);

        printf("Vectorul sortat\n");
        sortare(a, n);
        afiseaza(a, n);
    }
    return 0;
}*/

/* Scrieti functii care folosesc doar indecsi si realizeaza urmatoarele functionalitati:
1. Citeste valori de la stdin si verifica 
2. Citeste valori random
2. Afiseaza valori 
3. Maxim
4. Minim
5. Sortare 

void read_array_random(uint16_t a[], int size)
{
  int i;
  srand(time(NULL));

  for(i = 0; i < size; i++)
    {
      a[i] = rand()%2000;
    }
}

void print_array(uint16_t a[], int size)
{
  int i;

  for(i = 0; i < size; i++)
    {
      printf("%hd\n", a[i]);
    }
}

uint16_t max_array(uint16_t a[], int size)
{
  int i;
  int maxim = a[0];

  for(i = 1; i < size; i++)
    {
        if(a[i] > maxim)
	    {
	        maxim = a[i];
	    }
    }

  return maxim;
}

uint16_t min_array(uint16_t a[], int size)
{
  int i;
  int minim = a[0];

  for(i = 1; i < size; i++)
    {
      if(a[i] < minim)
	    {
	        minim = a[i];
	    }
    }

  return minim;
}

void sort_array(uint16_t a[], int size)
{
  int i;
  int s;
  uint16_t aux;

    do
    {
        s = 0;                            
        for (i = 1; i < size; i++)
        {     
            if (a[i - 1] > a[i])
            {            
                aux = a[i - 1];                
                a[i - 1] = a[i];
                a[i] = aux;
                s = 1;                           
            }
        }
    } while (s);
}

uint16_t read_array_stdin(uint16_t a[], int size)
{
  int i;
  int c;

  for(i = 0; i < size; i++)
  {
    c = scanf("%d", &a[i]);
    if(c != 1)
    {
      return i;
    }
  }
}

int main(void)
{
  static uint16_t tab[40000], a[1000];
  uint16_t maxim, minim, verificare;
  read_array_random(tab, 10);
  verificare = read_array_stdin(a, 5);
  printf("S- au citit %u numere\n", verificare);
  print_array(tab, 10);
  maxim = max_array(tab, 10);
  printf("Maximul din vector este: %hd\n", maxim);
  minim = min_array(tab, 10);
  printf("Minimul din vector este: %hd\n", minim);
  printf("Vectorul sortat\n");
  sort_array(tab, 10);
  print_array(tab, 10);
  return 0;
}*/

/* Să se scrie o funcție care primește ca parametrii un tablou de întregi A și un întreg N care reprezintă numărul de elemente. 
Funcția va elimina toate elementele care sunt numere prime, păstrând ordinea elementelor neschimbată și va returna dimensiunea.
Pe tot parcursul programului se vor folosi indecsi, nu pointeri. Intregul N nu va fi citit de la tastatura. Elementele vectorului
vor fi citite pana la intalnirea caracterului EOF. Se va testa folosind redirectarea intrarii standard. Se vor testa cazurile de eroare.

#define MAX_SIZE 10000

int este_prim(int nr)
{
    int i;

    for(i = 2; i < nr; i++)
    {
        if(nr % i == 0)
        {
            return 0;
        }
    }
    return 1;
}

int elimina(int A[], int N)
{
    int i;
    int j;

    for(i = 0; i < N; i++)
    {
        if(este_prim(A[i]))
        {
            for(j = i + 1; j < N; j++)
            {
                A[j - 1] = A[j];
            }
            N--;
            i--;
        }
    }
    return N;
}

int main(void)
{
    int A[MAX_SIZE];
    int N = 0;
    int valoare;
    int dim_nou;

    printf("Introduceti valoarea:\n");

    while((scanf("%d", &valoare)) != EOF)
    {
        printf("Introduceti valoarea:\n");
        A[N] = valoare;
        N++;
    }

    if(N > MAX_SIZE)
    {
        printf("Ati introdus un numar prea mare.\n");
        return 1;
    }
    else
    {
        int dim_nou = elimina(A, N);
        printf("\nNoua dimensiune a vectorului este: %d\n", dim_nou);
    }
    return 0;
}
*/

/* Să se scrie o funcție care primește ca parametrii un tablou de întregi A, un întreg N care reprezintă numărul de elemente și 
un întreg c care reprezintă un număr de cifre. Funcția va elimina toate elementele care au un număr mai mare de cifre ca și c, 
păstrând ordinea elementelor neschimbată și va returna dimensiunea. Pe tot parcursul programului se vor folosi indecsi, nu pointeri. 
Intregul N nu va fi citit de la tastatura. Elementele vectorului vor fi citite pana la intalnirea caracterului EOF. 
Se va testa folosind redirectarea intrarii standard. Se vor testa cazurile de eroare.

#define MAX_SIZE 100000

int calculeaza_cifre(int nr)
{
    int cifre = 0;
    
    while(nr != 0)
    {
        cifre++;
        nr = nr / 10;
    }

    return cifre;
}

int elimina_cifre(int A[], int N, int c)
{
    int i;
    int j;
    int nr_cifre;

    for(i = 0; i < N; i++)
    {
        nr_cifre = calculeaza_cifre(A[i]);
        if(nr_cifre > c)
        {
            for(j = i + 1; j < N; j++)
            {
                A[j - 1] = A[j];
            }
            N--;
            i--;
        }
    }

    return N;
}

int main(void)
{
    int A[MAX_SIZE];
    int N = 0;
    int c;
    int rezultat;
    int valoare;

    printf("Introduceti cifra c:\n");
    scanf("%d", &c);

    printf("Introduceti elementul:\n");
    while((scanf("%d", &valoare)) != EOF)
    {
        printf("Introduceti valoarea:\n");
        A[N] = valoare;
        N++;
    }

    if((N > MAX_SIZE) || N < 0)
    {
        printf("Ati introdus o valoare care nu corespunde cerintei.\n");
        return 1;
    }
    else
    {
        rezultat = elimina_cifre(A, N, c);
        printf("Noua dimensiune este: %d\n", rezultat);
    }

    return 0;
}
*/