#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int *citire(int n)
{
    int i;
    int *v;
    if((v=(int*)malloc(n*sizeof(int))) == NULL)
    {
        printf("memorie insuficienta.\n");
        exit(EXIT_FAILURE);
    }
    for(i=0; i<n; i++)
    {
        printf("v[%d]=", i);
        scanf("%d", &v[i]);
    }
    return v;
}

int main()
{
    int m, n, i, j;
    printf("n= ");
    scanf("%d", &n);
    int *v1 = citire(n);
    printf("m= ");
    scanf("%d", &m);
    int *v2 = citire(m);
for(i=0; i<m; i++)
{
    for(j=0; j<n; j++)
    {
        if(v1[i] == v2[j])
        {
            printf("%d\n", v1[i]);
            break;
        }
    }
}
free(v1);
free(v2);
    return 0;
}