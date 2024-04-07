/*Scrieti un program care numără caracterele, cuvintele şi liniile citite de la intrarea standard, pana la sfarsitul acesteia. Cuvintele sunt secvenţe de caractere despărţite prin unul sau mai multe "spatii albe". Precizări O linie se numără doar când e încheiată cu '\n'. Programul va tipări la ieşire numărul de linii, cuvinte, şi caractere, aliniate la dreapta pe un câmp de lăţime 7 (se poate face cu formatul %7d), şi separate prin câte un spaţiu. Pentru comparaţie, folosiţi programul UNIX wc (word count).*/

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <ctype.h>

int main(void)
{
  int linii = 0, cuvinte = 0, caractere = 0;
  int caracter_anterior = ' ';
  int caracter_curent;
  int tab[256];
  int i, j;
  float numar_aparitii = 0;

  for(i = 0; i < 256; i++)
    {
      tab[i] = 0; //initializam tabloul de aparitii cu 0
    }
  
  while((caracter_curent = getchar()) != EOF)
  {
    caractere++; //orice citeste se considera caracter, deci incrementam nr de caractere
    
    if(caracter_curent == '\n')
      {
	linii++; //daca caracter_curent este \n inseamna ca am trecut la linie noua, deci incrementam nr de linii
      }
    
    if(((caracter_curent != ' ') && (caracter_curent != '\n')) && ((caracter_anterior == ' ') || (caracter_anterior == '\n')))
      {
	cuvinte++; //daca ne aflam la o litera si inainte am avut spatiu / linie noua, inseamna ca am gasit un cuvant si incrementam numarul de cuvinte 
	putchar(toupper(caracter_curent)); //ne aflam la prima litera din cuvant, deci o facem majuscula 
      }
    else
      {
	putchar(caracter_curent); //daca nu e prima litera printam asa cum era
      }
    
    if(isalpha(caracter_curent))
      { 
        tab[caracter_curent]++; //daca e litera mare/mica ii crestem numarul de aparitii in tabloul de aparitii
      }
    caracter_anterior = caracter_curent;
  }

  printf("\n");
  printf("\n");
  printf("Linii - Cuvinte - Caractere\n");
  printf("%7d%7d%7d\n", linii, cuvinte, caractere);

  printf("\n");
  printf("Histograma literelor mari:\n");
  printf("\n");
  for(i = 65; i < 91; i++) //de la caracterul 'A' la 'Z'
    {
      numar_aparitii = ((float)tab[i] * 100) / ((float)caractere); //procentul aparitiilor din totalul de caractere
      printf("Caracterul %c - %.5f\n", i, numar_aparitii);
    }

  printf("\n");
  printf("Histograma literelor mici:\n");
  printf("\n");
  for(j = 97; j < 123; j++) //de la caracterul 'a' la 'z'
    {
      numar_aparitii = ((float)tab[j] * 100) / ((float)caractere); //procentul aparitiilor din totalul de caractere
      printf("Caracterul %c - %.5f\n", j, numar_aparitii);
    }
  
  return 0;
}
