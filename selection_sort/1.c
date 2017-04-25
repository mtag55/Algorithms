#include <stdio.h>

//finds the minimum from the usorted array and swaps it's palce with the current element'

void swap(int* v, int i, int j)
{
    int aux;
    aux  = v[i];
    v[i] = v[j];
    v[j] = aux;
}

int main()
{
    int v[10] = {2, 4, 1, 9, 5, 7};
    int n = 6;
    int i, j, k;
    for(i = 0; i < n-1; i++)
    {
        k = i;
        for(j = i+1; j < n; j++)
        {
            if(v[j] < v[k])
            {
                k = j;
            }
        }
        swap(v, i, k);
    }

    for(i = 0; i < n; i++)
        printf("%d ", v[i]);
    printf("\n");

    return 0;
}
