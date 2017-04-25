#include <stdio.h>

void bubble_sort(int* a, int n)
{
    int i, j;
    int temp;

    for(i = 0; i < n - 1; i++)
    {
        for(j = n-1; j > i; j--)
        {
            if(a[j] < a[j - 1])
            {
                temp = a[j];
                a[j] = a[j-1];
                a[j-1] = temp;
            }
        }
    }

}

int main()
{
    int a[10] = { 2, 3, 1, 7, 8, 4, 3 };
    int n = 7;

    int i;

    bubble_sort(a, n);
    for(i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");

    return 0;
}
