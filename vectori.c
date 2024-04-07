#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>

void read_array_random(uint16_t a[], int size)
{
  int i;
  srand(time(NULL));
  for(i = 0; i < size; i++)
    {
      a[i] = rand()%2000;
    }
  return;
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
  int i, s;
  uint16_t aux;
  do{
        s = 0;                            
        for (i = 1; i < size; i++){     
            if (a[i - 1] > a[i]){            
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
}
