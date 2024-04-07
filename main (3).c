/*
o biblioteca cu un tablou de structuri care stocheaza nume, autor, tip

daca e tip carte tehnica sa se memoreze daca e mate, chimie sau fizica

daca e tip belitristica sa se memoreze nr capitole

meniu cu 3 optiuni
1. adaugare
2. afisare
3. sortare dupa titlu

sa se foloseasca alocare dinamica progresiv la functia de adaugare
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum
{
    Technical,
    Beletristica,
} Tip;

typedef struct
{
    char *nume;
    char *autor;
    Tip tip;
    char *materie;
    int capitole;
} Carte;

void printCarte(Carte *carte)
{
    if (carte->tip == Technical)
    {
        printf("Nume=%s, Autor=%s, Materie=%s\n", carte->nume, carte->autor, carte->materie);
    }
    else if (carte->tip == Beletristica)
    {
        printf("Nume=%s, Autor=%s, Capitole=%d\n", carte->nume, carte->autor, carte->capitole);
    }
}

char *allocString(char *string)
{
    char *response = malloc(sizeof(char) * (strlen(string) + 1));
    strcpy(response, string);
    return response;
}

Carte *createTechnical(char *autor, char *nume, char *materie)
{
    Carte *carte = malloc(sizeof(Carte));
    carte->autor = allocString(autor);
    carte->nume = allocString(nume);
    carte->materie = allocString(materie);
    carte->tip = 0;
    return carte;
}

Carte *createBeletristica(char *autor, char *nume, int capitole)
{
    Carte *carte = malloc(sizeof(Carte));
    carte->autor = allocString(autor);
    carte->nume = allocString(nume);
    carte->capitole = capitole;
    carte->tip = 1;
    return carte;
}

void freeCarte(Carte *carte)
{
    free(carte->autor);
    free(carte->nume);
    if (carte->tip == Technical)
    {
        free(carte->materie);
    }
    free(carte);
}

void afisareCarti(Carte **carti, int n)
{
    for (int i = 0; i < n; i++)
    {
        printCarte(carti[i]);
    }
}

Carte *citesteCarte()
{
    int tip;
    Carte *carte;
    char *titlu = malloc(sizeof(char) * 50);
    printf("titlu=");
    scanf("%s", titlu);
    char *autor = malloc(sizeof(char) * 50);
    printf("autor=");
    scanf("%s", autor);
    printf("Alegeti tipul, 0 pentru tehnic, 1 pentru beletristic\n");
    scanf("%d", &tip);

    if (tip == 0)
    {
        char *materie = malloc(sizeof(char) * 50);
        printf("materie=");
        scanf("%s", materie);
        carte = createTechnical(autor, titlu, materie);
        free(titlu);
        free(autor);
        free(materie);
    }
    else if (tip == 1)
    {
        int capitole;
        printf("capitole=");
        scanf("%d", &capitole);
        carte = createBeletristica(autor, titlu, capitole);
        free(titlu);
        free(autor);
    }
    else
    {
        printf("Am zis 0 sau 1.\n");
        exit(1);
    }
    return carte;
}
void sortare(Carte **carti, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (strcmp(carti[i]->nume, carti[j]->nume) > 0)
            {
                Carte *aux;
                aux = carti[j];
                carti[j] = carti[i];
                carti[i] = aux;
            }
        }
    }
}
int main()
{
    int optiune;
    Carte **carti = malloc(sizeof(Carte) * 50);
    int n = 0;
    printf("Alegeti una din optiuni:\n");
    printf("1. Adaugare\n2. Afisare\n3. Sortare dupa titlu\n4.Iesire\n");
    printf("optiune=");
    scanf("%d", &optiune);
    while (optiune != 4)
    {
        switch (optiune)
        {
        case 1:
            carti[n] = citesteCarte();
            n++;
            break;
        case 2:
            afisareCarti(carti, n);
            break;
        case 3:
            sortare(carti, n);
            afisareCarti(carti, n);
            break;
        }
        printf("Alegeti una din optiuni:\n");
        printf("1. Adaugare\n2. Afisare\n3. Sortare dupa titlu\n4.Iesire\n");
        printf("optiune=");
        scanf("%d", &optiune);
    }
    return 0;
}