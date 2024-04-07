/* 1.	Se citește de la tastatură un număr fără semn. Să se seteze biții săi cu indecșii 0,2,3, să se reseteze biții cu indecșii 1,5,6 
și să se complementeze biții cu indecșii 4,7. Se vor afișa în binar atât numărul inițial cât și cel final.

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

void showBits(unsigned a){
    int i;
    for(i=sizeof(a)*8-1;i>=0;i--)
        printf("%d",(a>>i)&1);
    printf("\n");
}

int main(void)
{
    unsigned int a;
    printf("Introduceti numarul a:\n");
    scanf("%u", &a);
    printf("Valoarea initiala in binar a lui a:\n");
    showBits(a);
    a = a | (1<<0) | (1<<2) | (1<<3);
    printf("Numarul a cu bitii 0, 2, 3 setati este:\n");
    showBits(a);
    a = a & (~(1<<1)) & (~(1<<5)) & (~(1<<6));
    printf("Numarul a cu bitii 0, 2, 3 setati si bitii 1, 5, 6 resetati este:\n");
    showBits(a);
    a = a ^ (1<<4) ^ (1<<7);
    printf("Numarul a cu bitii 0, 2, 3 setati, bitii 1, 5, 6 resetati si bitii 4, 7 complementati este:\n");
    showBits(a);
    return 0;
}
*/

/* 1.O variabilă de tip char ocupă în memorie 8 biţi. Aceşti 8 biţi pot fi împărţiţi în 2 zone de câte 4 biţi. 
În fiecare zonă de câte 4 biţi s-ar putea memora câte un număr între 0 şi 15. 
Scrieţi un program care citeşte două numere între 1 şi 10 şi le memorează (împachetează) în cele două zone de câte 4 biţi 
ale unei variabile de tip char. 
După memorare, programul va despacheta valorile memorate şi le va afişa.

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

void showBits(unsigned a){
    int i;
    for(i=sizeof(a)*8-1;i>=0;i--)
        printf("%d",(a>>i)&1);
    printf("\n");
}

int main(void) 
{
    unsigned char a = 0;
    unsigned int b, c;
    unsigned int despachetat1, despachetat2;
    printf("Introduceti numarul b cuprins intre 1 si 10:\n");
    scanf("%u", &b);
    printf("Introduceti numarul c cuprins intre 1 si 10:\n");
    scanf("%u", &c);
    if(b < 1 || b > 10 || c < 1 || c > 10)
    {
        printf("Ati introdus numere in afara intervalului.\n");
        exit(1);
    }
    a = a | (b<<4) | c;
    printf("Numarul a compus din b pe MSB si c pe LSB:\n");
    showBits(a);
    printf("Numarul b era:\n");
    despachetat1 = (a>>4) & 0xFF;
    printf("%u\n", despachetat1);
    showBits(b);
    printf("Numarul c era:\n");
    despachetat2 = a & 0x0F;
    printf("%u\n", c);
    showBits(c);
    return 0;
}
*/

/* 1.	Se citește o valoare de tip int. 
Se cere să se afișeze valoarea bitului de semn. Nu se cunoaște a priori dimensiunea tipului de date int.

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(void) 
{
    int a, size, semn;
    printf("Introduceti numarul a:\n");
    scanf("%d", &a);
    size = sizeof(a)*8;
    semn = a & (1<<(size-1));
    if(semn)
    {
        printf("1");
    }
    else
    {
        printf("0");
    }
    return 0;
}
*/

/* 1.	Se citește o valoare. Să se afișeze suma primilor săi 4 biți LSB (cei mai din dreapta) 
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

void showBits(unsigned a){
    int i;
    for(i=sizeof(a)*8-1;i>=0;i--)
        printf("%d",(a>>i)&1);
    printf("\n");
}

int main(void) 
{
    unsigned int a, suma = 0, i, bit;
    printf("Introduceti valoarea lui a:\n");
    scanf("%u", &a);
    printf("Acestia sunt toti bitii lui a:\n");
    showBits(a);
    for(i = 0; i < 4; i++)
    {
        bit = a & 1;
        suma = suma + bit;
        a = a >> 1;
    }
    printf("Suma primilor 4 biti LSB este: %u\n", suma);
    return 0;
}
*/

/* 1.Scrieţi o funcție care ia ca parametru un întreg fără semn şi returnează numărul de biţi de 1 din reprezentarea sa.
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int count_bits_1(unsigned int a)
{
    int contor = 0;
    int size = sizeof(a)*8;
    int i;
    for(i = 0; i < size; i++)
    {
        if((a & 1) == 1)
        {
            contor++;
        }
        a = a >> 1;
    }
    return contor;
}

int main(void)
{
    unsigned int a;
    int contor;
    printf("Introduceti numarul a:\n");
    scanf("%u", &a);
    contor = count_bits_1(a);
    printf("Numarul a contine %d biti de 1.", contor);
    return 0;
}
*/

/* 1.	Un nibble este un grup de 4 biti. Să se scrie un program care primește un număr fără semn n și această funcție
a) returnează valoarea acestui număr cu ordinea inversă a nibble-urilor
b) returnează valoarea acestui număr cu biții din fiecare nibble în ordine inversă
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

void showBits(unsigned a){
    int i;
    for(i=sizeof(a)*8-1;i>=0;i--)
        printf("%d",(a>>i)&1);
    printf("\n");
}

unsigned int nibble_invers(unsigned int n)
{
    unsigned int rez1 = 0;
    rez1 = rez1 | ((n&0x0F)<<4) | ((n&0xF0)>>4);
    return rez1;
}

//unsigned int nibble_biti_invers(unsigned int n)
//{

//}

int main(void) 
{
    unsigned int n, rezultat1;
    printf("Introduceti numarul n de la tastatura:\n");
    scanf("%u", &n);
    printf("Acesta este numarul n pe biti inainte de modificari:\n");
    showBits(n);
    printf("Acesta este numarul n cu nibbleurile inversate:\n");
    rezultat1 = nibble_invers(n);
    showBits(rezultat1);
    return 0;
}

