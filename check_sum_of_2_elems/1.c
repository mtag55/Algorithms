#include <stdio.h>
#include <limits.h>
#include <math.h>

/* O(n lg n) alogithm. Given a Set S of n integers
   and another integer x, determine whether or not there
   exist two elems in S whose sun in exactly x. */

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

int bin_search(int* a, int l, int r, int val)
{
    if(l > r)
        return 0;
    int mid = (l+r)/2;
    if(a[mid] == val)
        return 1;
    else if(a[mid] < val)
        return bin_search(a, mid + 1, r, val);
    else
        return bin_search(a, l, mid - 1, val);
}

int main()
{
    int a[10] = { 1, 7, 10, 2, 3, 11, 12};
    int x = 10;
    int n = 7;
    int i;

    merge_sort(a, 0, 6);

    for(i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");

    for(i = 0; i < n; i++)
    {
        if(a[i] > (x/2 + 1))
            break;
        if(a[i] == x/2 && x%2 == 0 && i < n-1 && a[i] == a[i+1])
            printf("Found double\n");
        if(bin_search(a, 0, n-1, x-a[i]))
            printf("Found at position %d\n", i);
    }


    return 0;
}


