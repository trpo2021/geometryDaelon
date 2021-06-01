#include "ctype.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include <libgeometry/checkgeometry.h>

int check_circle(char* string)
{
    char cir[] = "circle";
    if (memcmp(string, cir, 6) != 0) {
        return -1;
    }
    char cir_2[] = "circle(";
    if (memcmp(string, cir_2, 7) != 0) {
        return -2;
    }
    return 0;
}

void warning(int sig)
{
    if (sig == -1)
        printf("Error: expected circle\n");

    if (sig == -2)
        printf("Error: expected (\n");

    if (sig == -3)
        printf("Error: expected ,\n");

    if (sig == -4)
        printf("Error\n");

    if (sig == -5)
        printf("Error: expected coordinatehh\n");

    if (sig == -6)
        printf("Error: expected coordinate\n");

    if (sig == -7)
        printf("Error: expected digit\n");
}