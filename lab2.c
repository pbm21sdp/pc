#include <stdio.h>
#include <stdint.h>

int maxim(int a, int b)
{
    if(a > b)
    {
        return a;
    }
    else 
    {
        return b;
    }
}

int minim(int a, int b)
{
    if (a < b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

int main(void)
{
    int x, y, n;
    printf("Introduceti primul numar, x: ");
    scanf("%d", &x);
    printf("Introduceti al doilea numar, y: ");
    scanf("%d", &y);
    for(;;)
    {
        printf("Alegeti una dintre urmatoarele optiuni:\n 1. Maximul dintre x si y\n 2. Minimul dintre x si y\n 3. x\n 4. y\n 5. Iesire din program\n");
        scanf("%d", &n);
        switch(n)
        {
            case 1:
            {
                maxim(x, y);
                break;
            }
            case 2:
            {
                minim(x, y);
                break;
            }
            case 3:
            {
                printf("%d", x);
            }
        }
    }
    return 0;
}