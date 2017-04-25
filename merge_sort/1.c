#include <stdio.h>
#include <limits.h>

void merge(int* a, int p, int q, int r)
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
            a[k] = R[j++];
        else
            a[k] = L[i++];
    }

}

//without using sentinels
void merge2(int* a, int p, int q, int r)
{
    int n1 = q - p + 1;
    int n2 = r - q;
    int L[n1];
    int R[n2];
    int i, j, k;
    for(i = 0; i < n1; i++)
    {
        L[i] = a[p + i];
    }
    for(j = 0; j < n2; j++)
    {
        R[j] = a[q + 1 + j];
    }
    i = j = 0;
    for(k = p; k < r + 1; k++)
    {
        if(i == n1)
        {
            a[k] = R[j++];
            continue;
        }
        if(j == n2)
        {
            a[k] = L[i++];
            continue;
        }
        if(L[i] > R[j])
            a[k] = R[j++];
        else
            a[k] = L[i++];

    }
}


void merge_sort2(int* a, int l, int r)
{
    if(l < r)
    {
        int q = (l + r) / 2;
        merge_sort2(a, l, q);
        merge_sort2(a, q + 1, r);
        merge2(a, l, q, r);
    }
}


void merge_sort(int* a, int l, int r)
{
    if(l < r)
    {
        int q = (l + r) / 2;
        merge_sort(a, l, q);
        merge_sort(a, q + 1, r);
        merge(a, l, q, r);
    }
}

int main()
{
    int a[10] = { 1, 7, 10, 2, 3, 11};
    int i;
    for(i = 0; i < 6; i++)
        printf("%d ", a[i]);
    printf("\n");

    merge_sort2(a, 0, 5);

    for(i = 0; i < 6; i++)
        printf("%d ", a[i]);
    printf("\n");
    return 0;
}


