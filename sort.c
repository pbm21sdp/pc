#include <stdio.h>

int main()
{
    int v[] = {5, 3, 21, 6, 1, 2, 3};
    int n = 7;

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (v[i] > v[j])
            {
                int aux;
                aux = v[j];
                v[j] = v[i];
                v[i] = aux;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        printf("%d ", v[i]);
    }
    printf("\n");
    return 0;
}