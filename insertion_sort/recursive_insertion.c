#include <stdio.h>


void insert(int* a, int n)
{
    int i = n-1;
    int temp = a[n];
    while(a[i] > temp && i >= 0)
    {
        a[i+1] = a[i];
        i--;
    }
    a[i+1] = temp;
}

void sort(int* a, int n)
{
    int i;
    if(n > 0)
    {
        sort(a, n-1);
        insert(a, n);
    }
}

int main()
{
    int i;
    int a[10] = { 7, 2, 6, 1, 9, 8};

    sort(a, 5);

    for(i = 0; i < 6; i++)
        printf("%d ", a[i]);
    printf("\n");

    return 0;
}
