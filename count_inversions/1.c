#include <stdio.h>
#include <limits.h>

void merge(int* a, int p, int q, int r, int* count)
{
    int n1 = q - p + 1;
    int n2 = r - q;
    int L[n1 + 1];
    int R[n2 + 1];
    int infinity = INT_MAX;
    int i, j, k;
    for(i = 0; i < n1; i++)
    {
        L[i] = a[p + i];
    }
    for(j = 0; j < n2; j++)
    {
        R[j] = a[q + 1 + j];
    }
    L[n1] = infinity;
    R[n2] = infinity;
    i = j = 0;
    for(k = p; k < r + 1; k++)
    {
        if(L[i] > R[j])
        {
            a[k] = R[j++];
            *count += 1;
        }
        else
            a[k] = L[i++];
    }

}

void merge_sort(int* a, int l, int r, int* count)
{
    if(l < r)
    {
        int q = (l + r) / 2;
        merge_sort(a, l, q, count);
        merge_sort(a, q + 1, r, count);
        merge(a, l, q, r, count);
    }
}

int main()
{
    int a[10] = { 2, 3, 8, 6, 1};
    int i;
    for(i = 0; i < 5; i++)
        printf("%d ", a[i]);
    printf("\n");

    int *count;
    *count = 0;

    merge_sort(a, 0, 4, count);

    for(i = 0; i < 5; i++)
        printf("%d ", a[i]);
    printf("\n");

    printf("%d\n", *count);
    return 0;
}


