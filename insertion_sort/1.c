
#include <stdio.h>

int main()
{
    int v[10] = { 31, 41, 59, 26, 41, 58 };

    int i, j, temp;
    int steps = 0;

    for(i = 1; i < 6; i++)
    {
        temp = v[i];
        j = i-1;
        // find the position where to insert the element
        while(j >= 0 && v[j] < temp)
        {
            v[j+1] = v[j];
            j--;
            steps ++;
        }
        v[j+1] = temp;
    }

    for (i = 0; i < 6; i++)
    {
        printf("%d\n",v[i]);
    }
    printf("steps = %d\n",steps);
}
