#include "ctype.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include <../src/libgeometry/checkcoords.h>

int check_digit(char* str, char* mcoord, char* mrad, double* arr)
{
    unsigned int i = 0;
    char copystr[100] = "";
    int count = 0;
    strncpy(copystr, str, 100);
    char del[] = "(,)";
    char* object1 = strtok(str, del);
    while (object1 != NULL) {
        object1 = strtok(NULL, del);
        count++;
    }
    if ((count - 1) == 2) {
        return -3;
    }
    if ((count - 1) != 3) {
        return -4;
    }
    char* object2 = strtok(copystr, "(");
    object2 = strtok(NULL, ",");
    strncpy(mcoord, object2, 50);
    object2 = strtok(NULL, ")");
    strncpy(mrad, object2, 50);
    arr[0] = atof(mrad);
    if (strchr(mcoord, ' ') == NULL) {
        return -5;
    }
    for (i = 0; i < strlen(mcoord); i++) {
        if ((isdigit(mcoord[i]) == 0) && (mcoord[i] != ' ')
            && (mcoord[i] != '.') && (mcoord[i] != '-')) {
            return -6;
        }
    }
    for (i = 0; i < strlen(mcoord); i++) {
        if (isdigit(mcoord[i]) != 0) {
            arr[1] = atof(&(mcoord[i]));
            break;
        }
    }
    for (i = 0; i < strlen(mcoord); i++) {
        if (mcoord[i] == ' ') {
            if (isdigit(mcoord[i + 1]) != 0)
                arr[2] = atof(&(mcoord[i]));
        }
    }

    for (i = 0; i < strlen(mrad); i++) {
        if ((isdigit(mrad[i]) == 0) && (mrad[i] != '.') && (mrad[i] != ' ')
            && (mrad[i] != '-')) {
            return -7;
        }
    }
    return 0;
}
