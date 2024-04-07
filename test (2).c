/* Să se scrie o funcție care primește ca parametru un șir de caractere și verifică dacă este o adresă URL validă. O adresă URL 
validă are urmat altul format: http://www.domeniu1.domeniu2. … domeniun.com, unde domeniu1, … domeniun sunt oricâte nume de domenii 
alcătuite doar din litere mici, despărțite prin puncte. Dacă șirul de caractere verificat este o adresă validă, se returnează NULL, 
iar altfel se returnează un pointer la locul în care începe să nu corespundă. Se verifică folosind șiruri de caractere de la tastatură. 
Se vor testa toate cazurile de eroare.*/

#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>
#include <ctype.h>

char *verificareURL(char *string)
{
    if(string == NULL)
    {
        return -1;
    }
    else
    {
        char inceput[] = "http://www";
        char separator[] = ".";
        char final[] = ".com";

        int len_inceput = strlen(inceput);
        int len_separator = strlen(separator);
  
        if((strstr(string, inceput)) == NULL)
	      {
	          return string;
	      }

        string = string + len_inceput;

        if((strstr(string, separator)) == NULL)
        {
	          return string;
        }

        string = string + len_separator;

        if((strstr(string, final)) == NULL)
        {
            return string;
        }

        while(*string != '\0')
        {
            if((!(islower(*string))) && (*string != '.'))
            {
                return string;
            }

            string++;
        }
    }
    
    return NULL;
}

int main(void)
{
    char string[100];
    char string1[] = "http://www.upt.com";
    char string2[100] = "htp://www.briana.com";
    char *string3 = NULL;
    char string4[] = "http://www.briana";
    char *rezultat;
    char *rezultat1;
    char *rezultat2;
    char *rezultat3;
    char *rezultat4;

    printf("Introduceti o adresa pe care doriti sa o verificati:\n");
    fgets(string, 100, stdin);
    string[strcspn(string, "\n")] = '\0';

    printf("Cazul dat de utilizator\n");
    rezultat = verificareURL(string);
    printf("Adresa: %s\n", string);

    if(rezultat == NULL)
    {
        printf("S-a introdus o adresa corecta.\n");
    }
    else if(rezultat == -1)
    {
      printf("S-a introdus un NULL.\n");
    }
    else
    {
        printf("Adresa introdusa nu este corecta. Eroare la pozitia: %ld\n", rezultat - string + 1);
    }
    printf("\n");
    
    printf("Cazul unei adrese valide:\n");
    rezultat1 = verificareURL(string1);
    printf("Adresa: %s\n", string1);

    if(rezultat1 == NULL)
    {
        printf("S-a introdus o adresa corecta.\n");
    }
    else if(rezultat1 == -1)
    {
      printf("S-a introdus un NULL.\n");
    }
    else
    {
        printf("Adresa introdusa nu este corecta. Eroare la pozitia: %ld\n", rezultat1 - string1 + 1);
    }
    printf("\n");

    printf("Cazul unei adrese invalide:\n");
    rezultat2 = verificareURL(string2);
    printf("Adresa: %s\n", string2);

    if(rezultat2 == NULL)
    {
        printf("S-a introdus o adresa corecta.\n");
    }
    else if(rezultat2 == -1)
    {
      printf("S-a introdus un NULL.\n");
    }
    else
    {
        printf("Adresa introdusa nu este corecta. Eroare la pozitia: %ld\n", rezultat2 - string2 + 1);
    }
    printf("\n");

    rezultat4 = verificareURL(string4);
    printf("Adresa: %s\n", string4);

    if(rezultat4 == NULL)
    {
        printf("S-a introdus o adresa corecta.\n");
    }
    else if(rezultat4 == -1)
    {
      printf("S-a introdus un NULL.\n");
    }
    else
    {
        printf("Adresa introdusa nu este corecta. Eroare la pozitia: %ld\n", rezultat4 - string4 + 1);
    }
    printf("\n");

    printf("Cazul string-ului NULL:\n");
    rezultat3 = verificareURL(string3);
    printf("Adresa: %s\n", string3);

    if(rezultat3 == NULL)
    {
        printf("S-a introdus o adresa corecta.\n");
    }
    else if(rezultat3 == -1)
    {
      printf("S-a introdus un NULL.\n");
    }
    else
    {
        printf("Adresa introdusa nu este corecta. Eroare la pozitia: %ld\n", rezultat3 - string3 + 1);
    }
    printf("\n");

    return 0;
}
