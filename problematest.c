#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

void afisare_puteri(uint32_t n)
{
    uint32_t mask = 0x80000000;
    uint8_t i = 0;
    for(i = 0; i < 32; i++)
    {
        if((n & mask) == 1)
        {
            if(i != 0) {
            printf("2^%d + ", i);
            }
        }
        mask = mask >> 1;
    }
}

int main(void)
{
    uint32_t numar;
    printf("Introduceti un numar de la tastatura:\n");
    scanf("%u", &numar);
    afisare_puteri(numar);
    return 0;
}