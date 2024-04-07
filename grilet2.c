#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(void)
{
    float n;
    scanf("%f", &n);
    switch(n)
    {
        case 1.5:
        {
            printf("DA");
            break;
        }
        case 2.3:
        {
            printf("NU");
            break;
        }
    }
    return 0;
}