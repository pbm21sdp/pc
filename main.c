#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    int v[14]={7, -5, 4, 3, -9, 2, -8};
    int n = 7;
    int i, j;
    for(i=0; i<n; i++)
    {
        for(j=n; j>i; j--)
        {
            v[j] = v[j-1];
        }
        v[i] = -v[i];
        n++;
        i++;
    }
    for(i=0; i<n; i++)
    {
        printf("%d\n", v[i]);
    }
    
    return 0;
}