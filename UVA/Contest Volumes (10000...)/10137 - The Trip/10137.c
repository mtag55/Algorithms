#include <stdio.h>
#define MAX_STUDENTS 1000

int main()
{
    long student_number = 0;
    double amount[MAX_STUDENTS];
    int i = 0;
    double sum = 0;
    double average = 0;
    double exchange_sum = 0;
    double exchange_diff = 0;
    double diff = 0;

    while((scanf("%ld", &student_number) == 1) && student_number != 0) {
        
        /* reinitialize */
        sum = 0;
        average = 0;
        exchange_sum = 0;
        exchange_diff = 0;

        /* calculate sum */
        for (i = 0; i < student_number; i++) {
            scanf("%lf", &amount[i]);
            sum += amount[i];
        }

        average = sum / student_number;

        for (i = 0; i < student_number; i++) {
            diff = (double) (long) ((amount[i] - average) * 100.0) / 100.0;
            if (amount[i] < average) {
                exchange_sum += -diff;
            }
            else {
                exchange_diff += diff;
            }
        }
        printf("$%.2lf\n", exchange_sum > exchange_diff ? exchange_sum : exchange_diff);
    }
    return 0;
}