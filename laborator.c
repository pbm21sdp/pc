/* PROBLEMA 2
Să se scrie o aplicație care declară câte o variabilă de fiecare tip întreg. În fiecare dintre aceste variabile se va citi 
o valoare de la tastatură și apoi se va afișa valoarea respectivă.
int a=5,b=1,c;
c=--a - --b;
printf("%d %d %d\n",a,b,c);
c=--a + b--;
printf("%d %d %d\n",a,b,c);
c=a++ - b++;
printf("%d %d %d\n",a,b,c); */

#include <stdio.h>
#include <stdint.h>

int main()
{
    char a;
    printf("Introduceti un numar de tipul char: ");
    scanf("%hhd", &a);
    printf("%hhd", a);
    return 0;
}