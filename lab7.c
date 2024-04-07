#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

int read_array_stdin(uint16_t *arr, int size)
{
  int i;
  int c = 0;
  for (i = 0; i < size; i++)
    {
      printf ("Introduceti elementul cu numarul %d: ", i);
      c = scanf ("%hd", (arr+i));
      if(c != 1)
	{
	  return i;
	}
    }
  return;
}

void print_array(uint16_t *arr, int size)
{
  int i;
  for (i = 0; i < size; i++)
    {
      printf ("%u ", *(arr + i));
    }
  printf ("\n");
}

uint16_t max_array(uint16_t *arr, int size)
{
  int i = 0;
  uint16_t *max = arr;
  for(i = 0; i < size; i++)
    {
      if(*(arr + i) > *max)
	{
	  *max = *(arr + i);
	}
    }
  return *max;
}

uint16_t min_array(uint16_t *arr, int size)
{
  int i;
  uint16_t *min = arr;
  for(i = 0; i < size; i++)
  {
    if(*(arr + i) < *min)
      {
	*min = *(arr + i);
      }
  }
  return *min;
}

void sort_array(uint16_t *arr, int size)
{
  int s, i;
  uint16_t aux;
  do{
    s = 0;                          
    for (i = 0; i < size; i++)
      {
	if (*(arr + i) > *(arr + i + 1))
	  {             
	    aux = *(arr + i);              
	    *(arr + i) = *(arr + i + 1);
	    *(arr + i + 1) = aux;
	    s = 1;                            
	  }
      }
    } while (s);         
}

int main(void)
{
  static uint16_t arr[3];
  uint16_t maximul, minimul;
  read_array_stdin(arr, 3);
  print_array(arr, 3);
  maximul = max_array(arr, 3);
  printf("Maximul din vector este: %u\n", maximul);
  minimul = min_array(arr, 3);
  printf("Minimul din vector este: %u\n", minimul);
  sort_array(arr, 3);
  printf("Vectorul sortat este:\n");
  print_array(arr, 3);
  return 0;
}
