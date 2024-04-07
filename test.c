#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

/*1. Functie care primeste un uint32_t si returneaza numarul de biti de 1
uint8_t bit_1_count(uint32_t n)
2. Functie care primeste un uint32_t si returneaza un uint16_t, care o sa aiba pe MSB numarul de biti de 0 si pe LSB numarul de biti de 1 din nr primit
uint16_t count_0_sau_1(uint32_t n)
3. Functie care primeste un uint32_t si returneaza cate perechi de biti de 1 se regasesc in nr.
uint8_t count_pair(uint32_t)
4. Functie care primeste un uint32_t si returneaza tot un uint32_t care are pe fiecare byte paritatea byte ului corespunzator din nr primit -> paritate para -> nr par de biti de 1 -> returneaza 0 -> paritate impara -> nr impar de biti de 1 -> returneaza 1
uint32_t parity_byte(uint32_t) */

/*Problema 1

uint8_t bit_1_count(uint32_t n)
{
  uint32_t mask = 0x80000000;
  uint8_t i = 0;
  int contor = 0;
  for(i = 0; i < 32; i++)
    {
      if((n & mask) != 0)
	{
	  contor++;
	}
      mask = mask >> 1;
    }
  return contor;
}

int main(void)
{
  uint32_t n = 0b10010001101011100101110101010110;
  uint8_t rezultat = bit_1_count(n);
  printf("%d\n", rezultat);
  return 0;
}

Problema 2

uint8_t bit_1_count(uint32_t n)
{
  uint32_t mask = 0x80000000;
  uint8_t i = 0;
  int contor = 0;
  for(i = 0; i < 32; i++)
    {
      if((n & mask) != 0)
	{
	  contor++;
	}
      mask = mask >> 1;
    }
  return contor;
}

uint8_t bit_0_count(uint32_t n)
{
  uint32_t mask = 0x80000000;
  uint8_t i = 0;
  int contor = 0;
  for(i = 0; i < 32; i++)
    {
      if((n & mask) == 0)
	{
	  contor++;
	}
      mask = mask >> 1;
    }
  return contor;
}

uint16_t count_0_sau_1(uint32_t n)
{
  uint8_t rezultat0 = bit_0_count(n);
  uint8_t rezultat1 = bit_1_count(n);
  uint16_t final = (rezultat0 << 8) | rezultat1;
  return final;
}

void print_bit_16(uint16_t nr)
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
      mask = mask >> 1; // mask >>= 1;
    }
  printf ("\n");
}

int main(void)
{
  uint32_t n = 0b10010001101011100101110101010110;
  uint16_t final = count_0_sau_1(n);
  print_bit_16(final);
  return 0;
}

*/

/* Problema 3

uint8_t count_pair(uint32_t n)
{
  uint8_t contor = 0, i, bit_precedent = 0, bit_curent;

  for(i = 0; i < 32; i++)
  {
    bit_curent = (n >> i) & 1;
    if(bit_curent == 0 && bit_precedent == 0)
      {
	contor++;
      }
    bit_curent = bit_precedent;
  }
  return contor;
}

int main(void)
{
  int n = 0b10010001101011100101110101010110;
  uint8_t nr_perechi = count_pair(n);
  printf("Numarul de perechi de biti de 1 este: %d\n", nr_perechi);
  return 0;
}

*/

//Problema 4

uint8_t bit_1_count(uint32_t n)
{
  uint8_t mask = 0b10000000;
  uint8_t i = 0;
  uint8_t paritate;
  for(i = 0; i < 8; i++)
    {
      if((n & mask) != 0)
	{
	  contor++;
	}
      mask = mask >> 1;
      if(contor % 2 == 0)
	{
	  paritate = 0;
	}
      else
	{
	  paritate = 1;
	}
      n = n >> 8;
    }
  return paritate;
}

uint32_t parity_byte(uint32_t n)
{
  uint8_t i = 0;
  uint8_t paritate;
  uint32_t par;
  
}
*/
