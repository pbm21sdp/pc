/* PROBLEMA 1
Să se citească o linie de la tastatură. Linia conține cuvinte care sunt formate doar din litere, 
cuvintele fiind despărțite prin orice alte caractere ce nu sunt litere. 
Să se capitalizeze prima literă din fiecare cuvânt și să se afișeze șirul rezultat*/

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

/*
int main(void)
{
    char ch;
    char caracter_anterior = ' ';
    printf("Introduceti sirul pe care doriti sa il modificati:\n");

    while((ch = getchar()) != '\n')
    {
        if(((ch != ' ') && (ch != '\n')) && ((caracter_anterior == ' ') || (caracter_anterior == '\n')))
        {
            putchar(toupper(ch));
        }
        else
        {
            putchar(ch);
        }
        caracter_anterior = ch;
    }
    return 0;
}*/

/* PROBLEMA 2
Se va citi un n<=10. Se vor citi apoi pe rând n nume. Se cere ca în final să fie afișat numele cel mai lung și lungimea sa*/

/*
int main(void)
{
    int n;
    char ch;
    char nume[100];
    int lungime;
    int lungime_maxima = 0;
    char maxim[100];

    printf("Introduceti numarul de nume:\n");
    scanf("%d", &n);

    if((n < 0) || (n > 10))
    {
        printf("Ati introdus un numar in afara intervalului.\n");
        exit(EXIT_FAILURE);
    }

    while(n > 0)
    {
        scanf("%s", nume);
        lungime = strlen(nume);
        if(lungime > lungime_maxima)
        {
            lungime_maxima = lungime;
            strcpy(maxim, nume);
        }
        n--;
    }

    printf("Numele cel mai lung este %s si are lungimea %d", maxim, lungime_maxima);
    return 0;
}*/

/* PROBLEMA 3
Se citește un n<=10 și apoi n nume de persoane, fiecare nume putând apărea de mai multe ori. 
Să se afișeze de câte ori apare fiecare nume*/

/*
int main(void)
{
    int n;
    int i;
    int j;
    char nume[10][100];
    int aparitii[10];
    char tmp[100];
    int gasit;

    printf("Introduceti numarul de nume de persoane:\n");
    scanf("%d", &n);

    if((n < 0) || (n > 10))
    {
        printf("Ati introdus un numar in afara intervalului.\n");
        exit(EXIT_FAILURE);
    }

    while (getchar() != '\n');

    for(i = 0; i < n; i++)
    {
        printf("Introduceti numele persoanei %d:\n", i + 1);
        fgets(tmp, sizeof(tmp), stdin);
        tmp[strcspn(tmp, "\n")] = '\0'; 

        gasit = 0;

        for(j = 0; j < i; j++)
        {
            if((strcmp(tmp, nume[j])) == 0)
            {
                gasit = 1;
                aparitii[j]++;
                break;
            }
        }
        if (gasit == 0)
        {
            strcpy(nume[i], tmp);
            aparitii[i] = 1;
        }
    }

    printf("Aparitiile fiecarui nume:\n");
    for (i = 0; i < n; i++)
    {
        if((strlen(nume[i])) > 0)
        {
        printf("%s: %d\n", nume[i], aparitii[i]);
        }
    }

    return 0;
}*/

/* PROBLEMA 4 
Se citește un text care este alcătuit doar din litere. Să se afișeze pentru fiecare literă de câte ori apare în text*/

/*
int main(void)
{
    int i;
    char text[1000];
    int numar_aparitii_mari[26];
    int numar_aparitii_mici[26];
    char caracter_curent;

    for(i = 0; i < 26; i++)
    {
        numar_aparitii_mari[i] = 0;
        numar_aparitii_mici[i] = 0;
    }

    printf("Introduceti textul: ");
    fgets(text, sizeof(text), stdin);

    for (i = 0; text[i] != '\0'; i++) 
    {
        caracter_curent = text[i];

        if (isalpha(caracter_curent)) 
        {
            if(isupper(caracter_curent)) 
            {
                numar_aparitii_mari[caracter_curent - 'A']++;
            }
            else
            {
                numar_aparitii_mici[caracter_curent - 'a']++;
            }
        }
    }

    printf("Frecventa literelor:\n");
    for (i = 0; i < 26; ++i) 
    {
        printf("%c: %d\n", 'A' + i, numar_aparitii_mari[i]);
        printf("%c: %d\n", 'a' + i, numar_aparitii_mici[i]);
    }

    return 0;
}*/

/* PROBLEMA 5 
Se citește n din intervalul [3,10] și apoi n nume de persoane. Să se concateneze primele n-1 nume folosind „, ”, 
ultimul nume cu „ si ”, iar apoi să se adauge „invata.”. Să se afișeze propoziția rezultată.
Exemplu: n=3, numele: Ion Ana Maria
Propoziție rezultata: Ion, Ana și Maria invata.*/

/*
int main(void)
{
    int i;
    int n;
    char nume[10][30];
    char final[300] = " ";
    char sir1[] = ", ";
    char sir2[] = " si ";
    char sir3[] = " invata.";
    printf("Introduceti numarul de nume:\n");
    scanf("%d", &n);

    if((n < 3) || (n > 10))
    {
        printf("Ati introdus un numar in afara intervalului.\n");
        exit(EXIT_FAILURE);
    }

    for(i = 0; i < n; i++)
    {
        scanf("%29s", nume[i]);
        strcat(final, nume[i]);

        if(i < (n - 2))
        {
            strcat(final, sir1);
        }
        else if(i == (n - 2))
        {
            strcat(final, sir2);
        }
    }

    strcat(final, sir3);
    
    printf("Textul final este:%s", final);
    return 0;
}*/

/* PROBLEMA 6
Se va citi un n<=10. Se vor citi apoi n produse, fiecare definit prin nume (un șir de caractere), cantitate (real) și preț unitar (real). Unele produse pot să fie date de mai multe ori, cu valori diferite. 
Să se calculeze pentru fiecare produs cantitatea și prețul total, iar în final să se calculeze și prețul global pentru toate produsele.*/

typedef struct{
    char nume[30];
    float cantitate;
    float pret_unitar;
    float pret_total;
}Produs;

int main(void) 
{
    int n;
    int i;

    printf("Introduceti numarul de produse (maxim 10): ");
    scanf("%d", &n);
   
    if((n < 1) || (n > 10))
    {
        printf("Ati introdus un numar in afara intervalului.\n");
        exit(EXIT_FAILURE);
    }

    Produs produse[10];

    for (i = 0; i < n; i++) 
    {
        printf("Introduceti informatiile pentru produsul %d:\n", i + 1);

        printf("Nume: ");
        scanf("%29s", produse[i].nume);

        printf("Cantitate: ");
        scanf("%f", &produse[i].cantitate);

        printf("Pret unitar: ");
        scanf("%f", &produse[i].pret_unitar);

        // Calcularea prețului total pentru produsul curent
        products[i].total_price = products[i].quantity * products[i].unit_price;
    }

    // Afișarea cantității și prețului total pentru fiecare produs
    printf("\nCantitate si pret total pentru fiecare produs:\n");
    for (int i = 0; i < n; i++) {
        printf("%s: %.2f unitati, %.2f pret total\n", products[i].name, products[i].quantity, products[i].total_price);
    }

    // Calcularea prețului global pentru toate produsele
    float total_global_price = 0;
    for (int i = 0; i < n; i++) {
        total_global_price += products[i].total_price;
    }

    // Afișarea prețului global pentru toate produsele
    printf("\nPret global pentru toate produsele: %.2f\n", total_global_price);

    return 0;
}
