#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>

// LAB 9
/* TEORIE 

Sirul de caractere este un tablou de elemente de tip CHAR 
Se termina cu caracterul \0

SINTAXA 
char nume_string[dimensiune]

EXEMPLUL 1 

char mystring1[] = {'s', 'a', 'l', 'u', 't', 0}; -> declaratie ca si tablou si initializare ca si tablou
char mystring2[] = "salut" -> declaratie ca si tablou si initializare cu o constanta de tip sir de caractere;
! mystring1 si mystring2 sunt identice 
char *mystring3 = "salut"; -> variabila de tip pointer ce este initializata cu o constanta de tip sir de caractere din zona .code
                           -> are ca rezultat o zona de memorie read-only
                           -> incercarea de modificare va produce SEGMENTATION FAULT
                           -> nu este acelasi lucru cu mystring1 si mystring2

string-ul nul (gol) -> "" ocupa un octet si contine doar caracterul NULL\0 


EXEMPLUL 2

int main(void)
{
    char text[30];
    printf("Introduceti un sir de caractere:\n");
    scanf("%s", text);
    printf("Sirul de caractere introdus este:\n%s", text);
    return 0;
}

PRINTF SI SCANF 

-> functiile PRINTF si SCANF folosesc directiva de formatare %s

1. SCANF

-> scanf de mai sus citeste de la stdin pana intalneste un spatiu alb, un EOF sau o linie noua (\n) si adauga la sfarsit \0
-> text aici nu se mai trimite la scanf cu & pentru ca este deja o adresa (un pointer)
-> scanf este foarte periculos pentru ca utilizatorul poate introduce oricate caractere si poate rezulta BUFFER OVERFLOW, adica 
se depaseste zona de memorie alocata
-> adaugarea unei dimensiuni la scanf, intre % si s, elimina posibilitatea aparitiei unui buffer overflow
-> dimensiunea este cu 1 mai mica decat cea alocata, pentru ca trebuie rezervat loc pentru \0
-> scanf va citi maxim cate caractere sunt specificate in dimensiunea dintre % si s
-> se va opri la numarul maxim / la spatiu / la un EOF, pentru ca nu mai are de unde citi
-> daca se citeste un tablou de caractere fara \0 nu e string, doar tablou de caractere 

EXEMPLUL 3 

int main(void)
{
    char text[30];
    printf("Introduceti un sir de caractere:\n");
    scanf("%29s", text);
    printf("Sirul introdus este:\n%s", text);
    return 0;
}

FUNCTIA FGETS

-> citeste un sir de caractere pana la EOF sau linie noua (\n) 
-> adauga la sfarsit \0
-> citeste maxim dimensiune - 1 caractere si le stocheaza in variabila data ca prim parametru
-> pentru a citi de la tastatura ultimul parametru va fi stdin
-> daca se opreste pentru ca a intalnit linie noua adauga si caracterul \n
-> returneaza NULL daca a aparut o eroare si nu s-a citit niciun caracter
-> returneaza variabila in care a citit daca s-a realizat cu succes
-> char *fgets(char *s, int size, FILE *stream)
-> parametrii sunt, in ordine: variabila in care se citeste, cate caractere se citesc, locul
de unde se citeste (fisier / stdin)

EXEMPLUL 4

int main(void)
{
    char text[20];

    printf("Introduceti o linie:\n"); //poate citi cu tot cu spatii

    if(fgets(text, 20, stdin) != NULL) //chiar daca primeste aici 20, citeste 19
    {
        printf("Linia introdusa este:\n%s", text);
    }
    else
    {
        printf("Eroare\n");
    }
    return 0;
}

FUNCTIA STRLEN

-> size_t strlen(const char *s)
-> primeste un string si returneaza dimensiunea acestuia, numarul de caractere pana 
la \0, deci cate caractere se vad
-> nu verifica transmiterea unui NULL, deci programul va crapa cu SEGMENTATION FAULT

EXEMPLUL 5

int main(void)
{
    char text[64] = "text";
    int n = 0;
    int m = 0;

    n = strlen(text);
    m = sizeof(text);

    printf("Dimensiunea acestuia in caractere este: %d\n", n);
    printf("Dimensiunea zonei de memorie este: %d\n", m);
    return 0;
}

FUNCTIA STRCPY

-> char *strcpy(char *dest, const char *src)
-> copiaza string-ul src pana la \0 in zona de memorie referita de dest
-> adauga \0 la final
-> nu verifica (nu are cum) daca este suficient loc in dest pentru a copia src
-> nu verifica transmiterea unui NULL nici pentru src, nici pentru dest, deci programul
poate crapa cu SEGMENTATION FAULT
-> nu se permite suprapunerea zonelor src si dest

EXEMPLUL 6

int main(void)
{
    char text[] = "ana are mere";
    char text2[128] = "text";

    printf("Dest initial, inainte de copiere:\n%s\n", text2);

    strcpy(text2, text);

    printf("Dest final, dupa copiere:\n%s\n", text2);
    return 0;
}

FUNCTIA STRCAT

-> char *strcat(char *dest, const char *src)
-> concateneaza, adauga la finalul lui dest continutul lui src
-> adauga \0
-> dest trebuie sa se termine cu \0 dar nu se verifica
-> nu verifica (nu are cum) daca este suficient loc in dest si pentru src
-> nu verifica transmiterea unui NULL nici pentru src, nici pentru dest, deci programul
poate crapa cu SEGMENTATION FAULT
-> nu se permite suprapunerea zonelor src si dest

EXEMPLUL 7

int main(void)
{
    char text[128] = "ana are mere";
    char text2[128] = " si pere";

    printf("Dest inainte de concatenare:\n%s\n", text);

    strcat(text, text2);

    printf("Dest dupa concatenare:\n%s\n", text);
    return 0;
}

FUNCTIA STRCHR
-> char *strchr(const char *s, int c)
-> cauta prima aparitie a caracterului c in string-ul s
-> returneaza un pointer la prima aparitie 
-> returneaza NULL daca nu exista caracterul c in s
-> nu returneaza pointerul dintr-o zona de memorie noua, ci din zona ce contine s
-> nu verifica transmiterea lui NULL, deci e posibil ca programul sa crape cu
SEGMENTATION FAULT

EXEMPLUL 8

int main(void)
{
    char text[128] = "ana are mere";
    char *rezultat = NULL;

    rezultat = strchr(text, 'm');

    if(rezultat == NULL)
    {
        printf("Nu exista acest caracter in string.\n");
    }
    else
    {
        printf("Gasit incepand de aici:\n%s\n", rezultat);
    }
    return 0;
}

FUNCTIA STRSTR

-> char *strstr(const char *haystack, const char *needle)
-> cauta prima aparitie a string-ului needle in string-ul haystack
-> returneaza un pointer la aceasta prima aparitie
-> returneaza NULL daca nu il gaseste
-> nu returneaza pointerul dintr-o zona de memorie noua, ci din zona ce contine haystack
-> nu verifica transmiterea lui NULL, deci programul poate crapa cu SEGMENTATION FAULT

EXEMPLUL 9

int main(void)
{
    char text[128] = "ana are mere";
    char *rezultat = NULL;

    rezultat = strstr(text, "are");

    if(rezultat == NULL)
    {
        printf("Nu exista acest string in string.\n");
    }
    else
    {
        printf("Gasit incepand de aici:\n%s\n", rezultat);
    }
    return 0;
}

FUNCTIA STRCMP

-> int strcmp(const char *s1, const char *s2)
-> compara cele 2 string-uri primite ca parametru
-> returneaza un intreg care poate lua valori:
a. valoarea 0 - daca cele 2 string-uri sunt egale
b. valoare > 0 - daca string-ul s1 (primul) este "mai mare" decat s2, 
adica alfabetic urmeaza DUPA s2
c. valoare < 0 - daca string-ul s1 (primul) este "mai mic" decat s2, 
adica alfabetic urmeaza INAINTE de s2
-> se compara caracter cu caracter 
-> returneaza diferenta dintre caractere (folosind ASCII)
-> nu verifica transmieterea unui NULL, deci programul se poate termina cu 
SEGMENTATION FAULT

EXEMPLUL 10

int main(void)
{
    char text[128] = "ana are mere";
    int rezultat = 0;

    rezultat = strcmp(text, "ana are bere");

    printf("%d\n", rezultat);

    rezultat = strcmp(text, "ana are mere");

    printf("%d\n", rezultat);

    rezultat = strcmp(text, "ana are pere");

    printf("%d\n", rezultat);
    return 0;
}

EXEMPLUL 11
Să se scrie un program care citește o linie de text, îi convertește toate caracterele 
la litere mari și apoi afișează textul rezultat.

int main(void)
{
    char linie[128];
    int i;

    printf("Introduceti o linie de la tastatura:\n");
    fgets(linie, 200, stdin);

    for(i = 0; linie[i]; i++)
    {
        linie[i] = toupper(linie[i]);
    }

    printf("Linia modificata este:\n%s\n", linie);
    return 0;
}

EXEMPLUL 12
Să se citească o linie de la tastatură. Linia conține cuvinte care sunt 
formate doar din litere, cuvintele fiind despărțite prin orice alte caractere ce nu 
sunt litere. Să se capitalizeze prima literă din fiecare cuvânt și să se afișeze 
șirul rezultat.

int main(void)
{
    char linie[256];
    int i;

    printf("Introduceti o linie de la tastatura:\n");
    fgets(linie, 256, stdin);

    linie[0] = toupper(linie[0]);

    for(i = 1; linie[i]; i++)
    {
        if((isalpha(linie[i-1]) == 0) && (isalpha(linie[i])))
        {
            linie[i] = toupper(linie[i]);
        }
    }

    printf("Linia modificata:\n%s\n", linie);
    return 0;
}

EXEMPLUL 13

Să se scrie un program care citește pe rând 2 nume. Cele două nume vor fi 
concatenate într-un alt șir de caractere cu „ și ” între ele și rezultatul va fi afișat.

int main(void)
{
    char nume1[30];
    char nume2[30];
    char legatura[] = " si ";
    char numerezultat[60] = "";

    printf("Introduceti primul nume:\n");
    scanf("%29s", nume1);

    printf("Introduceti al doilea nume:\n");
    scanf("%29s", nume2);

    strcat(numerezultat, nume1);
    strcat(numerezultat, legatura);
    strcat(numerezultat, nume2);

    printf("Numele rezultat este:\n%s\n", numerezultat);
    return 0;
}

EXEMPLUL 14
Se va citi un n<=10. Se vor citi apoi pe rând n nume. Se cere ca în final să fie 
afișat numele cel mai lung și lungimea sa.
*/

int main(void)
{
    int n;
    int i;
    char nume[100];
    char numeMax[100] = "";
    int len;
    int lungime = 0;

    printf("Introduceti numarul de nume:\n");
    scanf("%d", &n);
    getchar();

    if((n < 0) || (n > 10))
    {
        printf("Numarul introdus nu se afla in intervalul potrivit.\n");
        return 1;
    }
    else
    {
        for(i = 0; i < n; i++)
        {
            printf("Introduceti numele cu numarul %d:\n", (i + 1));
            fgets(nume, 100, stdin);
            nume[strcspn(nume, "\n")] = '\0';

            len = strlen(nume);

            if(len > lungime)
            {
                lungime = len;
                strcpy(numeMax, nume);
            }
        }

        printf("Numele cel mai lung este: %s\n", numeMax);
        printf("Lungimea sa este de %d caractere\n", lungime);
    }
    
    return 0;
}

// LAB 13
/* 1. Să se scrie un program care citește de la tastatură un n întreg și scrie 
într-un fișier cu numele ”out.txt” pentru fiecare număr din intervalul [0,n] 
dacă este par sau impar.

int citire()
{
    int n;

    printf("Introduceti un numar de la tastatura:\n");
    scanf("%d", &n);

    return n;
}

int main(void)
{
    int n;
    int i;
    FILE *iesire;

    if((iesire = fopen("out.txt", "w")) == NULL)
    {
        printf("A aparut o eroare la deschiderea fisierului.\n");
        return 1;
    }

    n = citire();

    for(i = 0; i <= n; i++)
    {
        if(i % 2 == 0)
        {
            fprintf(iesire, "Numarul %d este par\n", i);
        }
        else
        {
            fprintf(iesire, "Numarul %d este impar\n", i);
        }
    }
    fclose(iesire);
    return 0;
}
*/

/* 2. Se citesc de la tastatură maxim 100 numere reale, până la întâlnirea numărului 0. 
Să se sorteze aceste numere și să se scrie într-un fișier, toate numerele fiind pe o 
singură linie, separate prin | (bară verticală).

void BubbleSort(int *v, int n)
{
	int s;
    int i;
    int aux;
	do{
		s = 0;                             
		for (i = 1; i < n; i++)
		{     
			if (v[i - 1] > v[i])
			{             
				aux = v[i - 1];                 
				v[i - 1] = v[i];
				v[i] = aux;
				s = 1;                            
			}
		}
	} while (s);                         
}

int main(void)
{
    float v[101];
    int i = 0;
    int j = 0;

    FILE *iesire;

    if((iesire = fopen("pb2.txt", "w")) == NULL)
    {
        printf("Eroare la deschiderea fisierului de scriere.\n");
        return 1;
    }

    do
    {
        printf("Introduceti valoarea elementului cu numarul %d\n", i);
        scanf("%f", &v[i]);
        i++;

        if (v[i - 1] == 0)
        {
            j = i - 1;
            break;
        }
    } while (i < 100);

    BubbleSort(v, j);

    for(i = 0; i < j; i++)
    {
        if(i == (j - 1))
        {
            fprintf(iesire, "%f", v[i]);
        }
        else
        {
            fprintf(iesire, "%f | ", v[i]);
        }
    }
    fclose(iesire);
    return 0;
}
*/


