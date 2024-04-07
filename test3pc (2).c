#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <ctype.h>
#include <math.h>

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

EXEMPLUL 15
Se citește un n<=10 și apoi n nume de persoane, fiecare nume putând apărea de mai multe ori. Să se 
afișeze de câte ori apare fiecare nume.

int main(void)
{
    int n;
    int i;
    int j;
    int gasit;
    int contor = 0;
    char total[11][100];
    char nume[100];
    int aparitii[11];

    for(i = 0; i < 11; i++)
    {
        aparitii[i] = 0;
    }

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

            gasit = 0;

            for(j = 0; j < i; j++)
            {
                if(strcmp(nume, total[j]) == 0)
                {
                    gasit = 1;
                    aparitii[j]++;
                    break;
                }
            }

            if (gasit == 0)
            {
                strcpy(total[i], nume);
                aparitii[i]++;
                contor++;
            }
        }
    }

    for(i = 0; i < contor; i++)
    {
        printf("Numele %s apare de %d ori.\n", total[i], aparitii[i]);
    }
    return 0;
}

EXEMPLUL 16
Se citește un text care este alcătuit doar din litere. Să se afișeze pentru fiecare literă de câte ori apare în text.

int main(void)
{
    char text[1000];                
    char alfabet[30];
    int i;
    int j;
    int gasit;
    int aparitii[30];
    int contor = 0;

    for(i = 0; i < 30; i++)
    {
        aparitii[i] = 0;
    }

    printf("Introduceti un text alcatuit doar din litere:\n");
    fgets(text, 1000, stdin);
    text[strcspn(text, "\n")] = '\0';

    if((strchr(text, ' ')) != NULL)
    {
        printf("Ati introdus un text cu spatii.\n");
        return 1;
    }
    else
    {
        for(i = 0; text[i]; i++)
        {
            gasit = 0;

            for(j = 0; j < contor; j++)
            {
                if(text[i] == alfabet[j])
                {
                    gasit = 1;
                    aparitii[j]++;
                    break;
                }
            }

            if (gasit == 0)
            {
                alfabet[contor] = text[i];
                aparitii[contor]++;
                contor++;
            }
        }

        for(i = 0; i < contor; i++)
        {
            if(aparitii[i] == 1)
            {
                printf("Litera %c apare o data.\n", alfabet[i]);
            }
            else
            {
                printf("Litera %c apare de %d ori.\n", alfabet[i], aparitii[i]);
            }
        }
    }
    return 0;
}

EXEMPLUL 17
Se citește n din intervalul [3,10] și apoi n nume de persoane. Să se concateneze primele n-1 
nume folosind ", ", ultimul nume cu " si ", iar apoi să se adauge "invata.". Să se afișeze propoziția rezultată.
Exemplu: n=3, numele: Ion Ana Maria
Propoziție rezultata: Ion, Ana și Maria invata.


int main(void)
{
    int n;
    int i;
    char nume[100];
    char rezultat[1000] = "";
    char virgula[] = ", ";
    char si[] = " si ";
    char final[] = " invata.";

    printf("Introduceti numarul de nume:\n");
    scanf("%d", &n);
    getchar();

    if((n < 3) || (n > 10))
    {
        printf("Numarul introdus nu face parte din interval.\n");
        return 1;
    }
    else
    {
        for(i = 0; i < n; i++)
        {
            printf("Introduceti numele cu numarul %d:\n", (i + 1));
            fgets(nume, 100, stdin);
            nume[strcspn(nume, "\n")] = '\0';

            if(i == (n - 1))
            {
                strcat(rezultat, nume);
                strcat(rezultat, final);
            }
            else if(i == (n - 2))
            {
                strcat(rezultat, nume);
                strcat(rezultat, si);
            }
            else
            {
                strcat(rezultat, nume);
                strcat(rezultat, virgula);
            }
        }

        printf("Propozitia rezultata este:\n%s\n", rezultat);
    }
    return 0;
}

EXEMPLUL 18
Se va citi un n<=10. Se vor citi apoi n produse, fiecare definit prin nume (un șir de caractere), cantitate (real) 
și preț unitar (real). Unele produse pot să fie date de mai multe ori, cu valori diferite. Să se calculeze pentru 
fiecare produs cantitatea și prețul total, iar în final să se calculeze și prețul global pentru toate produsele.   

typedef struct{
    char nume[39];
    double cantitate;
    double pret_unitar;
}Produs;

int main(void)
{
    int n;
    int i;
    int j;
    char nume[30];
    int contor = 0;
    double pret_global = 0;
    Produs produse[11];

    printf("Introduceti numarul de produse:\n");
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
            printf("Introduceti caracteristicile produsului cu numarul %d:\n", (i + 1));

            printf("Introduceti numele produsului:\n");
            fgets(nume, 30, stdin);
            nume[strcspn(nume, "\n")] = '\0';

            int exista = 0;

            for(j = 0; j < contor; j++)
            {
                if(strcmp(nume, produse[j].nume) == 0)
                {
                    exista = 1;
                    break;
                }
            }

            if(exista == 0)
            {
                strcpy(produse[i].nume, nume);

                printf("Introduceti cantitatea produsului:\n");
                scanf("%lf", &produse[i].cantitate);
                getchar();

                printf("Introduceti pretul unitar al produsului:\n");
                scanf("%lf", &produse[i].pret_unitar);
                getchar();

                contor++;
            }
            else
            {
                printf("Introduceti cantitatea produsului:\n");
                double cantitate;
                scanf("%lf", &cantitate);
                getchar();

                for(j = 0; j < contor; j++)
                {
                    if(strcmp(nume, produse[j].nume) == 0)
                    {
                        produse[j].cantitate = produse[j].cantitate + cantitate;
                        break;
                    }
                }
            }
        }

        for(i = 0; i < contor; i++)
        {
            printf("Produsul: %s\n", produse[i].nume);
            printf("Cantitate totala: %lf\n", produse[i].cantitate);
            
            double pret_total = 0;
            pret_total = produse[i].cantitate * produse[i].pret_unitar;

            printf("Pret unitar: %lf\n", pret_total);

            pret_global = pret_global + pret_total;
        }

        printf("Pretul global este: %lf", pret_global);
    }
    return 0;
}

EXEMPLUL 19
Sa se realizeze o implementare proprie a functiilor standard de prelucrare de string-uri cum ar fi: strcmp, strcpy, strstr, strchr, 
strcat, strncmp, strncpy, strncat, atoi, strtol (fara parametrul char **endptr). Se va realiza atat o implementare ce foloseste 
operatorul de indexare in tablou cat si o implementare ce foloseste doar pointeri si aritmetica cu pointeri fara a folosi in aceasta 
si operatorul de indexare.


int main(void)
{

    return 0;
}

EXEMPLUL 20
Sa se scrie o functie cu urmatorul antet:
uint32_t upper_sub_string(char *str, const char *substr);
Pentru fiecare aparitie a string-ului substr in string-ul str se va modifica ca acest string din str sa fie 
transpus in litere mari (upper-case) Functia va returna numarul de aparitii.

Exemplu:

char s1[] = "Acesta este un string si stringul este terminat cu 0x00";
char s2[] = "string";
int r = upper_sub_string(s1, s2);
s1 devine "Acesta este un STRING si STRINGul este terminat cu 0x00";
s2 ramane neschimbat
r devine 2

Se va testa cu string-uri citite de la tastatura.

uint32_t upper_sub_string(char *str, const char *substr)
{
    uint32_t aparitii = 0;
    uint32_t len = strlen(substr);
    char *mutare = str;
    int j;

    while ((mutare = strstr(mutare, substr)) != NULL) 
    {
        for (j = 0; j < len; j++) 
        {
            mutare[j] = toupper(mutare[j]);
        }

        aparitii++;
        mutare = mutare + len;
    }

    return aparitii;
}

int main(void)
{
    uint32_t aparitii;
    char s1[] = "Acesta este un string si stringul este terminat cu 0x00";
    char s2[] = "string";

    printf("String-ul 1 inainte de modificari:\n%s\n", s1);
    printf("Substring-ul:\n%s\n");

    aparitii = upper_sub_string(s1, s2);

    printf("String-ul modificat este:\n%s\n", s1);
    printf("Substring-ul apare de %u ori.\n", aparitii);
    return 0;
}

EXEMPLUL 21
Sa se scrie o functie cu urmatorul antet
uint32_t string_replace(char *where, const char *what, const char *replace)
Functia inlocuieste fiecare aparitie a string-ului what in string-ul where cu string-ul replace. Se considera ca zona de memorie 
a lui where este suficient de mare ca sa poata contine noul string. Functia returneaza numarul de inlocuiri.

char s1[1000];
char s2[] = "string";
char s3[] = "sir de caractere";
strcpy(s1, "Acesta este un string si un string este terminat cu 0x00");
int r = string_replace(s1, s2, s3);
s1 devine "Acesta este un sir de caractere si un sir de caractere este terminat cu 0x00";
s2, s3 - raman neschimbate
r = 2


uint32_t string_replace(char *where, const char *what, const char *replace)
{
    uint32_t inlocuiri = 0;
    uint32_t len2 = strlen(what);
    uint32_t len3 = strlen(replace);
    char *mutare = where;
    int j;

    while ((mutare = strstr(mutare, what)) != NULL) 
    {
        char temp[1000];
        strcpy(temp, mutare + len2);
        
        strcpy(mutare, replace);
        
        strcat(mutare, temp);

        inlocuiri++;
        mutare = mutare + len3;
    }

    return inlocuiri;
}

int main(void)
{
    uint32_t inlocuiri;
    char s1[1000];
    char s2[] = "string";
    char s3[] = "sir de caractere";
    strcpy(s1, "Acesta este un string si un string este terminat cu 0x00");

    printf("String-ul 1 inainte de inlocuiri:\n%s\n", s1);

    inlocuiri = string_replace(s1, s2, s3);

    printf("String-ul 1 dupa inlocuiri:\n%s\n", s1);
    printf("S-au efectuat %u inlocuiri.\n", inlocuiri);
    return 0;
}
*/

//LAB 10
/* EXEMPLUL 1
Se definește o structură Dreptunghi care conține lățimea și lungimea unui dreptunghi. 
Se cere n<=10 și apoi n dreptunghiuri. Să se afișeze dimensiunile dreptunghiului de arie maximă.

typedef struct{
    double latime;
    double lungime;
}Dreptunghi;

int main(void)
{
    int n;
    int i;
    double arieMax = 0;
    double arie;
    int indexMax;
    Dreptunghi dreptunghiuri[11];

    printf("Introduceti numarul de structuri:\n");
    scanf("%d", &n);
    getchar();

    if((n < 0) || (n > 10))
    {
        printf("Ati introdus un numar din afara intervalului.\n");
        return 1;
    }
    else
    {
        for(i = 0; i < n; i++)
        {
            printf("Introduceti latimea dreptunghiului cu numarul %d:\n", (i + 1));
            scanf("%lf", &dreptunghiuri[i].latime);
            getchar();
            printf("Introduceti lungimea dreptunghiului cu numarul %d:\n", (i + 1));
            scanf("%lf", &dreptunghiuri[i].lungime);
            getchar();

            arie = dreptunghiuri[i].latime * dreptunghiuri[i].lungime;

            if(arie > arieMax)
            {
                arieMax = arie;
                indexMax = i;
            }
        }

        printf("Dreptunghiul cu aria maxima este cel cu numarul %d si cu dimensiunile:\nlatime = %.2lf\nlungime = %.2lf\n", (indexMax + 1), dreptunghiuri[indexMax].latime, dreptunghiuri[indexMax].lungime);
    }
    return 0;
}

EXEMPLUL 2
Se definește o structură Punct cu membrii x și y reali. Se cere un n<=10 și apoi n puncte. Să se calculeze distanța dintre cele 
mai depărtate două puncte și să se afișeze.
Notă: în antetul <math.h> este definită funcția sqrt (square root), care se poate folosi pentru extragerea radicalului.


typedef struct{
    double x;
    double y;
}Punct;

int main(void)
{
    int n;
    int i;
    int j;
    int indiceMax1;
    int indiceMax2;
    double distantaMaxima = 0;
    Punct puncte[11];

    printf("Introduceti numarul de puncte:\n");
    scanf("%d", &n);
    getchar();

    if((n < 0) || (n > 10))
    {
        printf("Ati introdus un numar din afara intervalului.\n");
        return 1;
    }
    else
    {
        for(i = 0; i < n; i++)
        {
            printf("Introduceti coordonata x a punctului cu numarul %d:\n", (i + 1));
            scanf("%lf", &puncte[i].x);
            getchar();

            printf("Introduceti coordonata y a punctului cu numarul %d:\n", (i + 1));
            scanf("%lf", &puncte[i].y);
            getchar();
        }
        for(i = 0; i < n; i++)
        {
            for(j = i + 1; j < n; j++)
            {
                double difX = puncte[j].x - puncte[i].x;
                double difY = puncte[j].y - puncte[i].y;
                double patratX = difX * difX;
                double patratY = difY * difY;
                double dif = patratX - patratY;
                double distanta = sqrt(dif);

                if(distanta < 0)
                {
                    distanta = distanta * (-1);
                }

                if(distanta > distantaMaxima)
                {
                    distantaMaxima = distanta;
                    indiceMax1 = i;
                    indiceMax2 = j;
                }
            }
        }

        printf("Punctele cele mai departate ca distanta sunt cele cu numerele %d si %d, cu o distanta de %lf.\n", (indiceMax1 + 1), (indiceMax2 + 1), distantaMaxima);
    }
    return 0;
}

EXEMPLUL 3
Să se implementeze o bază de date cu produse definite prin câmpurile nume și preț. Operațiile necesare sunt introducere, afișare 
și ieșire, iar ele se vor cere de la tastatură, utilizatorului fiindu-i prezentat un meniu de unde poate alege operația dorită.

typedef struct{
    char nume[40];
    double pret;
}Produs;

int main(void)
{
    int n;
    int i = 0;
    int j;
    Produs produse[20];

    do
    {
        printf("\nAlegeti optiunea dorita:\n1.Introducere - introduceti un produs nou\n2.Afisare - afisati lista produselor existente\n3.Iesire - apasati tasta 3\n");

        scanf("%d", &n);
        getchar();

        switch(n)
        {
            case 1:
            {
                if(i == 19)
                {
                    printf("Ati umplut lista de produse.\n");
                    return 1;
                }
                else
                {
                    printf("Introduceti numele produsului cu numarul %d:\n", (i + 1));
                    fgets(produse[i].nume, 40, stdin);
                    produse[i].nume[strcspn(produse[i].nume, "\n")] = '\0';

                    printf("Introduceti pretul produsului cu numarul %d:\n", (i + 1));
                    scanf("%lf", &produse[i].pret);
                    getchar();
                    
                    i++;
                }
                break;
            }
            case 2:
            {
                for(j = 0; j < i; j++)
                {
                    printf("Produsul cu numarul %d:\n", (j + 1));
                    printf("Nume: %s\n", produse[j].nume);
                    printf("Pret: %lf\n", produse[j].pret);
                }
                break;
            }
        }
    }while(n != 3);

    return 0;
}

EXEMPLUL 4
Să se extindă exemplul 2 cu operația de căutare de produs după nume: se cere un nume de la tastatură și apoi se caută în baza de date. 
Dacă s-a găsit, se va afișa prețul său. Dacă nu s-a găsit, se va afișa textul „produs inexistent”.


typedef struct{
    char nume[40];
    double pret;
}Produs;

int main(void)
{
    int n;
    int i = 0;
    int j;
    char nume[40];
    Produs produse[20];

    do
    {
        printf("\nAlegeti optiunea dorita:\n1.Introducere - introduceti un produs nou\n2.Afisare - afisati lista produselor existente\n");
        printf("3.Iesire - apasati tasta 3\n4.Cautare - introduceti un produs pe care doriti sa il gasiti\n");

        scanf("%d", &n);
        getchar();

        switch(n)
        {
            case 1:
            {
                if(i == 19)
                {
                    printf("Ati umplut lista de produse.\n");
                    return 1;
                }
                else
                {
                    printf("Introduceti numele produsului cu numarul %d:\n", (i + 1));
                    fgets(produse[i].nume, 40, stdin);
                    produse[i].nume[strcspn(produse[i].nume, "\n")] = '\0';

                    printf("Introduceti pretul produsului cu numarul %d:\n", (i + 1));
                    scanf("%lf", &produse[i].pret);
                    getchar();
                    
                    i++;
                }
                break;
            }
            case 2:
            {
                for(j = 0; j < i; j++)
                {
                    printf("Produsul cu numarul %d:\n", (j + 1));
                    printf("Nume: %s\n", produse[j].nume);
                    printf("Pret: %.2lf\n", produse[j].pret);
                }
                break;
            }
            case 4:
            {
                printf("Introduceti numele produsului pe care il cautati:\n");
                fgets(nume, 40, stdin);
                nume[strcspn(nume, "\n")] = '\0';

                int gasit = 0;
                int indice;

                for(j = 0; j < i; j ++)
                {
                    if((strcmp(nume, produse[j].nume)) == 0)
                    {
                        gasit = 1;   
                        indice = j;
                        break;
                    }
                }

                if(gasit)
                {
                    printf("Produsul a fost gasit. Pretul acestuia este: %.2lf\n", produse[indice].pret);
                }
                else
                {
                    printf("Produs inexistent.\n");
                }
            }
        }
    }while(n != 3);

    return 0;
}

EXEMPLUL 5
Să se modifice exemplul 2 astfel încât să se poată cere un nume de produs și să se șteargă din baza de date toate produsele 
având acel nume (va fi redată numai partea specifică):

typedef struct{
    char nume[40];
    double pret;
}Produs;

int main(void)
{
    int n;
    int i = 0;
    int j;
    int b;
    char nume[40];
    Produs produse[20];

    do
    {
        printf("\nAlegeti optiunea dorita:\n1.Introducere - introduceti un produs nou\n2.Afisare - afisati lista produselor existente\n");
        printf("3.Iesire - apasati tasta 3\n4.Cautare - introduceti un produs pe care doriti sa il gasiti\n");
        printf("5.Stergere - introduceti numele produsului pe care doriti sa il eliminati din lista.\n");

        scanf("%d", &n);
        getchar();

        switch(n)
        {
            case 1:
            {
                if(i == 19)
                {
                    printf("Ati umplut lista de produse.\n");
                    return 1;
                }
                else
                {
                    printf("Introduceti numele produsului cu numarul %d:\n", (i + 1));
                    fgets(produse[i].nume, 40, stdin);
                    produse[i].nume[strcspn(produse[i].nume, "\n")] = '\0';

                    printf("Introduceti pretul produsului cu numarul %d:\n", (i + 1));
                    scanf("%lf", &produse[i].pret);
                    getchar();
                    
                    i++;
                }
                break;
            }
            case 2:
            {
                for(j = 0; j < i; j++)
                {
                    printf("Produsul cu numarul %d:\n", (j + 1));
                    printf("Nume: %s\n", produse[j].nume);
                    printf("Pret: %.2lf\n", produse[j].pret);
                }
                break;
            }
            case 4:
            {
                printf("Introduceti numele produsului pe care il cautati:\n");
                fgets(nume, 40, stdin);
                nume[strcspn(nume, "\n")] = '\0';

                int gasit = 0;
                int indice;

                for(j = 0; j < i; j ++)
                {
                    if((strcmp(nume, produse[j].nume)) == 0)
                    {
                        gasit = 1;   
                        indice = j;
                        break;
                    }
                }

                if(gasit)
                {
                    printf("Produsul a fost gasit. Pretul acestuia este: %.2lf\n", produse[indice].pret);
                }
                else
                {
                    printf("Produs inexistent.\n");
                }
                break;
            }
            case 5:
            {
                printf("Introduceti numele produsului pe care doriti sa il eliminati:\n");
                fgets(nume, 40, stdin);
                nume[strcspn(nume, "\n")] = '\0';

                
                for(j = 0; j < i; j++)
                {                                           
                    if(!strcmp(nume, produse[j].nume))
                    {             
                        for (b = j + 1; b < i; b++)
                        {                              
                            produse[b - 1] = produse[b];
                        }
                        i--;
                        j--;
                    }
                }
                break;
            }
        }
    }while(n != 3);

    return 0;
}

EXEMPLUL 6
Să se extindă exemplul 2 cu operația de sortare a produselor după nume.

typedef struct{
    char nume[40];
    double pret;
}Produs;

int main(void)
{
    int n;
    int i = 0;
    int j;
    int b;
    char nume[40];
    Produs produse[20];

    do
    {
        printf("\nAlegeti optiunea dorita:\n1.Introducere - introduceti un produs nou\n2.Afisare - afisati lista produselor existente\n");
        printf("3.Iesire - apasati tasta 3\n4.Cautare - introduceti un produs pe care doriti sa il gasiti\n");
        printf("5.Stergere - introduceti numele produsului pe care doriti sa il eliminati din lista.\n");
        printf("6.Sortare - sortati produsele alfabetic.\n");

        scanf("%d", &n);
        getchar();

        switch(n)
        {
            case 1:
            {
                if(i == 19)
                {
                    printf("Ati umplut lista de produse.\n");
                    return 1;
                }
                else
                {
                    printf("Introduceti numele produsului cu numarul %d:\n", (i + 1));
                    fgets(produse[i].nume, 40, stdin);
                    produse[i].nume[strcspn(produse[i].nume, "\n")] = '\0';

                    printf("Introduceti pretul produsului cu numarul %d:\n", (i + 1));
                    scanf("%lf", &produse[i].pret);
                    getchar();
                    
                    i++;
                }
                break;
            }
            case 2:
            {
                for(j = 0; j < i; j++)
                {
                    printf("Produsul cu numarul %d:\n", (j + 1));
                    printf("Nume: %s\n", produse[j].nume);
                    printf("Pret: %.2lf\n", produse[j].pret);
                }
                break;
            }
            case 4:
            {
                printf("Introduceti numele produsului pe care il cautati:\n");
                fgets(nume, 40, stdin);
                nume[strcspn(nume, "\n")] = '\0';

                int gasit = 0;
                int indice;

                for(j = 0; j < i; j ++)
                {
                    if((strcmp(nume, produse[j].nume)) == 0)
                    {
                        gasit = 1;   
                        indice = j;
                        break;
                    }
                }

                if(gasit)
                {
                    printf("Produsul a fost gasit. Pretul acestuia este: %.2lf\n", produse[indice].pret);
                }
                else
                {
                    printf("Produs inexistent.\n");
                }
                break;
            }
            case 5:
            {
                printf("Introduceti numele produsului pe care doriti sa il eliminati:\n");
                fgets(nume, 40, stdin);
                nume[strcspn(nume, "\n")] = '\0';

                
                for(j = 0; j < i; j++)
                {                                           
                    if(!strcmp(nume, produse[j].nume))
                    {             
                        for (b = j + 1; b < i; b++)
                        {                              
                            produse[b - 1] = produse[b];
                        }
                        i--;
                        j--;
                    }
                }
                break;
            }
            case 6:
            {
                for(j = 0; j < i - 1; j++)
                {
                    for(b = 0; b < i - j - 1; b++)
                    {
                        int modificare;
                        modificare = (strcmp(produse[j].nume, produse[j + 1].nume));
                        if(modificare > 0)
                        {
                            Produs temp = produse[b];
                            produse[b] = produse[b + 1];
                            produse[b + 1] = temp;
                        }
                    }
                }
                break;
            }
        }
    }while(n != 3);

    return 0;
}

EXEMPLUL 7
Să se modifice exemplul 2 astfel încât, la adăugarea unui produs, dacă numele respectiv există deja în baza de date, 
acesta să nu mai fie adăugat ci să fie schimbat prețul vechi cu cel nou introdus.

typedef struct{
    char nume[40];
    double pret;
}Produs;

int main(void)
{
    int n;
    int j;
    int b;
    int i = 0;
    char nume[40];
    Produs produse[20];

    do
    {
        printf("\nAlegeti optiunea dorita:\n");
        printf("1. Introducere - introduceti un produs nou\n");
        printf("2. Afisare - afisati lista produselor existente\n");
        printf("3. Iesire - apasati tasta 3\n");
        printf("4. Cautare - introduceti un produs pe care doriti sa il gasiti\n");
        printf("5. Stergere - introduceti numele produsului pe care doriti sa il eliminati din lista\n");
        printf("6. Sortare - sortati produsele alfabetic\n");
        printf("\n");

        scanf("%d", &n);
        getchar();

        switch(n)
        {
            case 1:
            {
                if(i == 19)
                {
                    printf("Ati umplut lista de produse. Se permit maxim 20.\n");
                    return 1;
                }
                else
                {
                    printf("Introduceti numele produsului cu numarul %d:\n", (i + 1));
                    fgets(nume, 40, stdin);
                    nume[strcspn(nume, "\n")] = '\0';

                    int gasit = 0;
                    int index;

                    for(j = 0; j < i; j++)
                    {
                        if((strcmp(nume, produse[j].nume)) == 0)
                        {
                            gasit = 1;
                            index = j;
                            break;
                        }
                    }

                    if(gasit)
                    {
                        double pret;

                        printf("Introduceti noul pret al produsului cu numarul %d:\n", (index + 1));
                        scanf("%lf", &pret);
                        getchar();

                        produse[index].pret = pret;
                    }
                    else
                    {
                        strcpy(produse[i].nume, nume);

                        printf("Introduceti pretul produsului cu numarul %d:\n", (i + 1));
                        scanf("%lf", &produse[i].pret);
                        getchar();
                        
                        i++;
                    }
                }
                break;
            }
            case 2:
            {
                for(j = 0; j < i; j++)
                {
                    printf("Produsul cu numarul %d:\n", (j + 1));
                    printf("Nume: %s\n", produse[j].nume);
                    printf("Pret: %.2lf\n", produse[j].pret);
                }
                break;
            }
            case 4:
            {
                printf("Introduceti numele produsului pe care il cautati:\n");
                fgets(nume, 40, stdin);
                nume[strcspn(nume, "\n")] = '\0';

                int gasit = 0;
                int indice;

                for(j = 0; j < i; j ++)
                {
                    if((strcmp(nume, produse[j].nume)) == 0)
                    {
                        gasit = 1;   
                        indice = j;
                        break;
                    }
                }

                if(gasit)
                {
                    printf("Produsul a fost gasit. Pretul acestuia este: %.2lf\n", produse[indice].pret);
                }
                else
                {
                    printf("Produs inexistent.\n");
                }
                break;
            }
            case 5:
            {
                printf("Introduceti numele produsului pe care doriti sa il eliminati:\n");
                fgets(nume, 40, stdin);
                nume[strcspn(nume, "\n")] = '\0';

                
                for(j = 0; j < i; j++)
                {                                           
                    if(!strcmp(nume, produse[j].nume))
                    {             
                        for (b = j + 1; b < i; b++)
                        {                              
                            produse[b - 1] = produse[b];
                        }
                        i--;
                        j--;
                    }
                }

                printf("S-a efectuat stergerea. Selectati afisare pentru a vizualiza.\n");

                break;
            }
            case 6:
            {
                for(j = 0; j < i - 1; j++)
                {
                    for(b = 0; b < i - j - 1; b++)
                    {
                        int modificare;
                        modificare = (strcmp(produse[j].nume, produse[j + 1].nume));
                        if(modificare > 0)
                        {
                            Produs temp = produse[b];
                            produse[b] = produse[b + 1];
                            produse[b + 1] = temp;
                        }
                    }
                }

                printf("S-a efectuat sortarea. Selectati afisare pentru a vizualiza.\n");

                break;
            }
        }
    }while(n != 3);

    return 0;
}

EXEMPLUL 8
Se consideră o structură Produs care conține un câmp nume și altul pret. Să se scrie o funcție care primește ca parametru un produs 
și un procent reprezentând o reducere de preț. Funcția va modifica prețul produsului conform cu reducerea dată. În programul principal 
se vor introduce un număr n de produse, cu n citit de la tastatură. Folosind funcția definită anterior, să se modifice prețurile 
produselor și să se afișeze.


typedef struct{
    char nume[100];
    double pret;
}Produs;

void modificare(Produs *p, int procent)
{
    double pret_nou;

    pret_nou = p->pret - ((procent * p->pret) / 100);

    p->pret = pret_nou;
}

void afisare(Produs *p, int n)
{
    int i;

    for(i = 0; i < n; i++)
    {
        printf("Numele produsului cu numarul %d este: %s\n", (i + 1), ((p + i)->nume));
        printf("Pretul produsului cu numarul %d este: %.2lf\n", (i + 1), ((p + i)->pret));
    }
}

int main(void)
{
    int n;
    int i;
    int procent;
    Produs produse[30];

    printf("Introduceti numarul de produse:\n");
    scanf("%d", &n);
    getchar();

    printf("Introduceti procentul reducerii:\n");
    scanf("%d", &procent);
    getchar();

    for(i = 0; i < n; i++)
    {
        printf("Introduceti numele produsului cu numarul %d:\n", (i + 1));
        fgets(produse[i].nume, 100, stdin);
        produse[i].nume[strcspn(produse[i].nume, "\n")] = '\0';

        printf("Introduceti pretul produsului cu numarul %d:\n", (i + 1));
        scanf("%lf", &produse[i].pret);
        getchar();
    }

    printf("Lista de produse inainte de modificare:\n");
    printf("\n");
    afisare(produse, n);

    for(i = 0; i < n; i++)
    {
        modificare((produse + i), procent);
    }

    printf("\n");
    printf("Lista de produse dupa modificare:\n");
    printf("\n");
    afisare(produse, n);

    return 0;
}

EXEMPLUL 9
Aplicația 12.5: O structură conține ora (întreg) la care s-a măsurat o anumită temperatură și valoarea acestei temperaturi (real). 
Se cere n<=10 și apoi n temperaturi. Se cere apoi o oră de început și una de sfârșit. Să se afișeze media temperaturilor care au 
fost măsurate în acel interval orar, inclusiv în capetele acestuia.


typedef struct{
    int ora;
    double temperatura;
}Temperatura;

int main(void)
{
    int n;
    int i;
    double suma_temperaturi = 0;
    double media;
    int ora_inceput;
    int ora_sfarsit;
    int total = 0;
    Temperatura temperaturi[11];

    printf("Introduceti numarul de temperaturi:\n");
    scanf("%d", &n);
    getchar();

    if((n < 0) || (n > 10))
    {
        printf("Ati introdus o valoare din afara intervalului.\n");
        return 1;
    }
    else
    {
        for(i = 0; i < n; i++)
        {
            printf("Introduceti ora temperaturii cu numarul %d:\n", (i + 1));
            scanf("%d", &temperaturi[i].ora);
            getchar();

            printf("Introduceti temperatura masurata la ora cu numarul %d:\n", (i + 1));
            scanf("%lf", &temperaturi[i].temperatura);
            getchar();
        }

        printf("Introduceti o ora de inceput:\n");
        scanf("%d", &ora_inceput);
        getchar();

        printf("Introduceti o ora de sfarsit:\n");
        scanf("%d", &ora_sfarsit);
        getchar();

        for(i = 0; i < n; i++)
        {
            if((temperaturi[i].ora >= ora_inceput) && (temperaturi[i].ora <= ora_sfarsit))
            {
                suma_temperaturi = suma_temperaturi + temperaturi[i].temperatura;
                total++;
            }
        }

        media = (double)suma_temperaturi / total;

        printf("Media temperaturilor din intervalul orar ales este: %.2lf grade Celsius.", media);
    }
    return 0;
}

EXEMPLUL 10
Se cere un text, citit până la \n. Să se afișeze de câte ori apare fiecare cuvânt din textul respectiv. 
Un cuvânt este o succesiune constituită doar din litere.

typedef struct{
    char cuvant[100];
    int aparitii;
}Cuvant;

int main(void)
{
    int i;
    int j;
    int nr_cuvinte = 0;
    int len;
    int index;
    int gasit;
    char text[1000];
    char cuvant[100];
    Cuvant cuvinte[1000];

    printf("Introduceti un text:\n");
    fgets(text, 1000, stdin);
    text[strcspn(text, "\n")] = '\0';

    for(i = 0; text[i]; i++) 
    {
        index = 0;

        while (isalpha(text[i])) 
        {
            cuvant[index++] = tolower(text[i++]);
        }
        if (index > 0) 
        {
            cuvant[index] = '\0';

            gasit = 0;
            for (j = 0; j < nr_cuvinte; j++) 
            {
                if (strcmp(cuvant, cuvinte[j].cuvant) == 0) 
                {
                    cuvinte[j].aparitii++;
                    gasit = 1;
                    break;
                }
            }

            if (!gasit) 
            {
                strcpy(cuvinte[nr_cuvinte].cuvant, cuvant);
                cuvinte[nr_cuvinte].aparitii = 1;
                nr_cuvinte++;
            }
        }
    }

    for(i = 0; i < nr_cuvinte; i++) 
    {
        if(cuvinte[i].aparitii == 1)
        {
            printf("Cuvantul %s apare o data.\n", cuvinte[i].cuvant);
        }
        else
        {
            printf("Cuvantul %s apare de %d ori.\n", cuvinte[i].cuvant, cuvinte[i].aparitii);
        }
    }

    return 0;
}

EXEMPLUL 11
Se consideră o structură Persoana care are un câmp nume și altul varsta. Să se scrie o funcție care primește ca parametru o 
persoană și îi modifică numele astfel încât prima literă să fie mare iar restul mici. Să se testeze funcția cu o persoană 
citită de la tastatură.


typedef struct{
    char nume[100];
    int varsta;
}Persoana;

Persoana modificare(Persoana p)
{
    int i;
    char nume[100];
    Persoana p1;

    strcpy(nume, p.nume);

    nume[0] = toupper(nume[0]);

    for(i = 1; nume[i]; i++)
    {
        nume[i] = tolower(nume[i]);
    }

    strcpy(p1.nume, nume);
    p1.varsta = p.varsta;

    return p1;
}

void afisare(Persoana p)
{
    printf("Numele persoanei: %s\n", p.nume);
    printf("Varsta persoanei: %d\n", p.varsta);
    printf("\n");
}

int main(void)
{
    Persoana individ;

    printf("Introduceti numele persoanei:\n");
    fgets(individ.nume, 100, stdin);
    individ.nume[strcspn(individ.nume, "\n")] = '\0';

    printf("Introduceti varsta persoanei:\n");
    scanf("%d", &individ.varsta);
    getchar();

    printf("Persoana inainte de modificari:\n");
    afisare(individ);

    individ = modificare(individ);

    printf("Persoana dupa modificari:\n");
    afisare(individ);

    return 0;
}

EXEMPLUL 12
Se citește un n oricât de mare și apoi n puncte în plan, definite prin coordonatele lor (x,y). Să se afișeze toate punctele, 
grupate în seturi de puncte care sunt pe aceeași linie orizontală (au același y). 

typedef struct{
    double x;
    double y;
}Punct;

void BubbleSort(Punct *puncte, int n)
{
	int s;
    int i;
    Punct aux;

	do{
		s = 0;                             
		for (i = 1; i < n; i++)
		{      
			if ((puncte + i - 1)->y > (puncte + i)->y)
			{             
				aux.y = (puncte + i - 1)->y;                
				(puncte + i - 1)->y = (puncte + i)->y;
				(puncte + i)->y = aux.y;
				s = 1;                            
			}
		}
	} while (s);                        
}

void afisare(Punct *puncte, int n)
{
    int i;

    for(i = 0; i < n; i++)
    {
        printf("Coordonata x a punctului cu numarul %d este: %.2lf\n", (i + 1), (puncte + i)->x);
        printf("Coordonata y a punctului cu numarul %d este: %.2lf\n", (i + 1), (puncte + i)->y);
    }
}

int main(void)
{
    int n;
    int i;
    Punct puncte[100];

    printf("Introduceti numarul de puncte pe care il doriti:\n");
    scanf("%d", &n);
    getchar();

    if((n < 0) || (n > 100))
    {
        printf("Ati introdus prea multe numere.\n");
        return 1;
    }
    else
    {
        for(i = 0; i < n; i++)
        {
            printf("Introduceti coordonata x a punctului cu numarul %d:\n", (i + 1));
            scanf("%lf", &puncte[i].x);
            getchar();

            printf("Introduceti coordonata y a punctului cu numarul %d:\n", (i + 1));
            scanf("%lf", &puncte[i].y);
            getchar();
        }

        printf("Lista punctelor inainte de grupare:\n");
        afisare(puncte, n);

        printf("Lista punctelor dupa grupare:\n");
        BubbleSort(puncte, n);
        afisare(puncte, n);
    }

    return 0;
}
*/

// LAB 12
/* EXEMPLUL 1
Se cere un număr n, iar apoi n numere întregi. Se cere să se sorteze crescător numerele. Programul va utiliza doar strictul 
necesar de memorie.

void BubbleSort(int *v, int n)
{
    int e;
    int i;
    int tmp;

    do
    {
        e = 0;

        for(i = 1; i < n; i++)
        {
            if(v[i - 1] > v[i])
            {
                tmp = v[i - 1];
                v[i - 1] = v[i];
                v[i] = tmp;
                e = 1;
            }
        }
    } while (e);
}

void afisare(int *v, int n)
{
    int i;

    for(i = 0; i < n; i++)
    {
        printf("Elementul cu numarul %d este: %d\n", (i + 1), v[i]);
    }
}

int main(void)
{
    int n;
    int i;
    int *v;
    
    printf("Introduceti un numar n de la tastatura:\n");
    scanf("%d", &n);
    getchar();

    if((v = (int*)malloc(n * sizeof(int))) == NULL)
    {
        printf("Eroare la alocarea memoriei.\n");
        return 1;
    }
    else
    {
        for(i = 0; i < n; i++)
        {
            printf("Introduceti elementul cu numarul %d:\n", (i + 1));
            scanf("%d", &v[i]);
            getchar();
        }

        printf("Vectorul inainte de sortare:\n");
        afisare(v, n);

        printf("Vectorul dupa sortare:\n");
        BubbleSort(v, n);
        afisare(v, n);

        free(v);
    }
    return 0;
}

EXEMPLUL 2
Să se scrie o funcție citire(n), care primește ca argument un număr n și alocă dinamic un vector de n numere întregi, pe care 
îl inițializează cu valori citite de la tastatură și îl returnează. În programul principal se citesc două numere, m și n, iar apoi, 
folosind funcția citire, se citesc elementele a doi vectori, primul de m elemente iar al doilea de n elemente. Să se afișeze toate 
elementele din primul vector care se regăsesc și în al doilea vector. Programul va utiliza doar strictul necesar de memorie.

int* citire(int n)
{
    int *v;
    int i;

    if((v = (int *)malloc(n * sizeof(int))) == NULL)
    {
        printf("Eroare la alocarea memoriei.\n");
        exit(EXIT_FAILURE);
    }

    for(i = 0; i < n; i++)
    {
        printf("Introduceti valoarea elementului cu numarul %d:\n", (i + 1));
        scanf("%d", &v[i]);
        getchar();
    }

    return v;
}

void afisare(int *v, int n)
{
    int i;

    for(i = 0; i < n; i++)
    {
        printf("Elementul cu numarul %d este: %d\n", (i + 1), v[i]);
    }
}

int* comparare(int *unu, int *doi, int m, int n, int *dimensiune_rezultat)
{
    int i;
    int j;
    int a = 0;
    int *trei;

    if((trei = (int *)malloc(m * sizeof(int))) == NULL)
    {
        printf("Eroare la alocarea memoriei.\n");
        exit(EXIT_FAILURE);
    }

    for(i = 0; i < m; i++)
    {
        for(j = 0; j < n; j++)
        {
            if(unu[i] == doi[j])
            {
                trei[a] = unu[i];
                a++;
            }
        }
    }

    if((trei = (int *)realloc(trei, a * sizeof(int))) == NULL)
    {
        printf("Eroare la realocarea memoriei.\n");
        exit(EXIT_FAILURE);
    }

    *dimensiune_rezultat = a;
    return trei;
}

int main(void)
{
    int m;
    int n;
    int a;
    int *unu;
    int *doi;
    int *trei;

    printf("Introduceti numarul de elemente pentru primul vector:\n");
    scanf("%d", &m);
    getchar();

    printf("Introduceti numarul de elemente pentru al doilea vector:\n");
    scanf("%d", &n);
    getchar();

    unu = citire(m);
    doi = citire(n);

    printf("Primul vector:\n");
    afisare(unu, m);

    printf("Al doilea vector:\n");
    afisare(doi, n);

    printf("Elementele din primul vector care se gasesc si in al doilea sunt:\n");
    trei = comparare(unu, doi, m, n, &a);
    afisare(trei, a);

    free(unu);
    free(doi);
    free(trei);
    return 0;
}

EXEMPLUL 3
Se citesc de la tastatură numere până la introducerea valorii 0. Să se afișeze dacă toate numerele sunt pare, sau nu. 
Programul va utiliza doar strictul necesar de memorie.


int main(void)
{
    int n;
    int j;
    int gasit;
    int i = 0;
    int *v = NULL;

    do
    {
        if((v = (int *)realloc(v, (i + 1) * sizeof(int))) == NULL)
        {
            printf("Eroare la alocarea memoriei.\n");
            return 1;
        } 

        printf("Introduceti valoarea elementului cu numarul %d:\n", (i + 1));
        scanf("%d", &n);
        getchar();

        v[i] = n;
        i++;

    }while(n != 0);

    gasit = 0;

    for(j = 0; j < i; j++)
    {
        if(v[j] % 2 != 0)
        {
            gasit = 1;
            break;
        }
    }

    if(!gasit)
    {
        printf("Toate numerele sunt pare.\n");
    }
    else
    {
        printf("Exista si numere impare.\n");
    }
    
    free(v);

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

3. Se citesc dintr-un fișier linii de forma:
produs,preț unde produsul are maxim 15 caractere și poate conține spații, iar prețul e un număr real. Se cere să se 
afișeze produsul cu cel mai mare preț. 


typedef struct{
    char nume[100];
    double pret;
}Produs;
 
int main(void)
{
    FILE *intrare;

    if((intrare = fopen("linii.txt","r")) == NULL) 
    {
        printf("Eroare la deschiderea fisierului.\n");
        exit(EXIT_FAILURE);
    }

    Produs produse[1000];
    int i = 0;
    double pretMax = 0;
    int indice;

    while((fscanf(intrare, "%99[^,],%lf", produse[i].nume, &produse[i].pret)) != EOF)
    {
        if(produse[i].pret > pretMax)
        {
            pretMax = produse[i].pret;
            indice = i;
        }
        i++;
    }

    printf("Produsul cu pretul cel mai mare (%lf) este: %s\n", pretMax, produse[indice].nume);
    fclose(intrare);
    return 0;
}

4. Sa se construiasca o functie de tip void, care are ca parametrii char *fisier_dest, char *fisier_sursa, int n. Din fisierul sursa sa se
ia toate caracterele de pe pozitiile 0, n, 2*n, 3*n.. si sa se afiseze in fisierul destinatie.
*/

void mutare(char *fisier_dest, char *fisier_sursa, int n)
{
    FILE *dest;
    FILE *sursa;

    if ((dest = fopen(fisier_dest, "w")) == NULL)
    {
        printf("Eroare la deschiderea fisierului de destinatie.\n");
        exit(EXIT_FAILURE);
    }

    if ((sursa = fopen(fisier_sursa, "r")) == NULL)
    {
        printf("Eroare la deschiderea fisierului sursa.\n");
        exit(EXIT_FAILURE);
    }

    int pozitie = 0;
    char caracter;

    while ((caracter = fgetc(sursa)) != EOF)
    {
        if (pozitie % n == 0)
        {
            fputc(caracter, dest);
        }
        pozitie++;
    }

    fclose(dest);
    fclose(sursa);
}

int main(void)
{
    mutare("dest.txt", "sursa.txt", 2);

    return 0;
}

