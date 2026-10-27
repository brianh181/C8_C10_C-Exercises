#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

#define NUM_RATES ((int) (sizeof (value) / sizeof(value [0])))
#define INITIAL_BALANCE 100.00

int main(void) {
    int i, low_arate, num_years, year;

    double value[5];

    printf ("Enter annual interest rate: ");
    scanf ("%d", &low_arate);



    printf("Enter number of years: ");
    scanf ("%d", &num_years);

    printf("\nYears");

    for (i = 0; i < NUM_RATES; i++){
        printf("%6d%%", low_arate + i);
        value[i] = INITIAL_BALANCE;
    }


    printf("\n");
    for (year = 1; year <= num_years; year++) {
        printf("%3d ", year);
        for (i = 0; i < NUM_RATES; i++) {
            double low_mrate = pow(1.0 + (low_arate + i) / 100.0, 1.0 / 12.0) - 1.0;

            for (int month = 0; month < 12; month++) {
                value[i] += low_mrate * value[i];
            }
            printf("%7.2f", value[i]);
        }

        printf("\n"); 
    }

    return 0;
}