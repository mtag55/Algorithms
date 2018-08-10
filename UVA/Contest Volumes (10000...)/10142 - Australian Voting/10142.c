#include <stdio.h>

#define MAX_CANDIDATES 20

int main()
{
    int number_of_cases = 0;
    int number_of_candidates = 0;
    char candidates[MAX_CANDIDATES][80];
    int i = 0;
    int j = 0;
    char c;

    scanf("%d", &number_of_cases);

    while(number_of_cases--) {
        getchar(); /* reads an empty line */
        scanf("%d", &number_of_candidates);
        getchar();
        printf("n = %d\n", number_of_candidates);
        while(number_of_candidates) {
            c = getchar();
            if (c == '\n') {
                /* go to next candidate */
                candidates[i][j] = '\0';
                i++;
                j = 0;
                number_of_candidates--;
                continue;
            }
            candidates[i][j] = c;
            j++;
        }
    }

    printf("%s\n", candidates[1]);

    return 0;
}