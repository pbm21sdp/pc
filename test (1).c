#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void cap(char *linie)
{
  int i;

  if(isalpha(linie[0]))
    {
      linie[0] = toupper(linie[0]);
    }
  
  for(i = 1; i < linie[i]; i++)
    {
      if((isspace(linie[i-1])) && (isalpha(linie[i])))
	{
	  linie[i] = toupper(linie[i]);
	}
    }
  printf("%s\n", linie);
}

uint32_t upper_sub_string(char *str, const char *substr)
{
  char i, j;
  uint32_t schimbari = 0;
  uint32_t dimsub = strlen(substr);

  
  return schimbari;
}

uint32_t string_replace(char *where, const char *what, const char *replace)
{
  uint32_t schimbari = 0;
  
  return schimbari;
}

int main(void)
{
  char linie[3000];
  uint32_t rezultat8, rezultat9;
  char s1[] = "Acesta este un string si stringul este terminat cu 0x00";
  char s2[] = "string";
  char s3[1000];
  char s4[] = "string";
  char s5[] = "sir de caractere";
  strcpy(s3, "Acesta este un string si un string este terminat cu 0x00");

  //Problema 1
  printf("\nProblema 1\n");
  fgets(linie, 3000, stdin);
  linie[strlen(linie) - 1] = '\0';
  cap(linie);

  //Problema 8
  printf("\nProblema 8\n");
  printf("Stringul s1 inainte de modificari:\n");
  printf("%s\n", s1);
  printf("Stringul substr:\n");
  printf("%s\n", s2);
  rezultat8 = upper_sub_string(s1, s2);
  printf("Stringul s1 dupa modificari:\n");
  printf("%s\n", s1);
  printf("S-au efectuat %d schimbari\n", rezultat8);

  //Problema 9
  printf("\nProblema 9\n");
  printf("Stringul s3 inainte de modificari:\n");
  printf("%s\n", s3);
  printf("Stringul what:\n");
  printf("%s\n", s4);
  printf("Stringul replace:\n");
  printf("%s\n", s5);
  rezultat9 = string_replace(s3, s4, s5);
  printf("Stringul s3 dupa modificari:\n");
  printf("%s\n", s3);
  printf("S-au efectuat %d schimbari\n", rezultat9);
  return 0;
}











/*while((str = strstr(str, substr)) != NULL)
    {
      for(i = 0; i < dimsub; i++)
	{
	  str[i] = toupper(str[i]);
	}
      str = str + dimsub;
      schimbari++;
      }*/

/*for(i = str; str[i]; )
    {
      char *rezultat = NULL;
      rezultat = strstr(str, substr);
      if(rezultat == NULL)
	{
	  break;
	}
      else
	{
	  for(j = str + rezultat; j <= dimsub; j++)
	    {
	      str[j] = toupper(str[j]);
	    }
	}
      i = i + j;
      }*/
