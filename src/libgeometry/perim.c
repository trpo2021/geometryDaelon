#include "libgeometry/perim.h"
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int count;

double coord_and_rad(char* rad, double* arr)
{
    double s = atof(rad) * atof(rad) * M_PI;
    double pir = 2 * atof(rad) * M_PI;
    arr[0] = s;
    arr[1] = pir;
    return s;
}

int intersec(int n, int end, double* save_rad, double* save_x, double* save_y)
{
    for (int i = n; i < end; i++) {
        for (int j = 0; j < end; j++) {
            if (i != j) {
                double lenght
                        = sqrt(pow(save_x[j] - save_x[i], 2)
                               + pow(save_y[j] - save_y[i], 2));
                double summ = save_rad[i] + save_rad[j];
                if (lenght <= summ) {
                    printf("%d,", j + 1);
                    count++;
                }
            }
        }
        break;
    }

    printf("\n");
    return count;
}