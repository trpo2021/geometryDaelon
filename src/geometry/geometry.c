#include "libgeometry/checkcoords.h"
#include "libgeometry/checkgeometry.h"
#include "libgeometry/perim.h"
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int sig = 0;
    double arr[2];
    double save_arr[3];
    double* save_x = NULL;
    double* save_y = NULL;
    double* save_rad = NULL;
    double* save_p = NULL;
    double* save_s = NULL;
    int i, count_fig = 0;
    for (i = 0; i > -1; i++) {
        count_fig++;
        char mcoord[50] = "";
        char mrad[50] = "";
        int i;
        char instr[100] = "";
        fgets(instr, 100, stdin);
        if (instr[0] == '\n')
            break;

        char out[100] = "";
        strncpy(out, instr, 100);
        for (i = 0; i < 100; i++) {
            instr[i] = tolower(instr[i]);
        }
        sig = check_circle(instr);
        warning(sig);
        sig = check_digit(instr, mcoord, mrad, save_arr);
        warning(sig);
        save_rad = realloc(save_rad, count_fig * sizeof(double));
        save_rad[count_fig - 1] = save_arr[0];
        save_x = realloc(save_x, count_fig * sizeof(double));
        save_x[count_fig - 1] = save_arr[1];
        save_y = realloc(save_y, count_fig * sizeof(double));
        save_y[count_fig - 1] = save_arr[2];
        coord_and_rad(mrad, arr);
        save_p = realloc(save_p, count_fig * sizeof(double));
        save_p[count_fig - 1] = arr[1];
        save_s = realloc(save_s, count_fig * sizeof(double));
        save_s[count_fig - 1] = arr[0];
    }
    for (int i = 0; i < count_fig - 1; i++) {
        printf("%d) circle(%f %f,%f)\n",
               i + 1,
               save_x[i],
               save_y[i],
               save_rad[i]);
        printf("square=%f\n", save_s[i]);
        printf("perimetr=%f\n", save_p[i]);
        printf("intersec:");
        intersec(i, count_fig - 1, save_rad, save_x, save_y);
    }
    free(save_rad);
    free(save_x);
    free(save_y);
    free(save_s);
    free(save_p);

    return 0;
}
