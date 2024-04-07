/*Se cere un număr impar n>4. Să se deseneze cifra „8”, scris ca un pătrat cu o linie orizontală în mijloc, 
în așa fel încât pe verticală și pe orizontală să fie câte n steluțe. 
În program nu vor fi admise duplicări de cod.*/

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

void linieOrizontala(int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("* ");
    printf("\n");
}



int main(void)
{
    int n;
    printf("Introduceti un numar de la tastatura: \n");
    scanf("%d", &n);
    if(n < 4)
    {
        printf("Ati introdus un numar prea mic.\n");
        exit(1);
    }
    if(n % 2 == 0)
    {
        printf("Numarul introdus trebuie sa fie impar.\n");
        exit(1);
    }
 
    deseneazaCifra8(n);
    return 0;
}