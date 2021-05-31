#include "geometry.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int Skip_Space(const char* str, int i)
{
    while (str[i] == ' ')
        i++;
    return i;
}

static int Convert_String(char* str, double* r)
{
    if (sscanf(str, "%lf", r) == 0)
        return 0;
    return 1;
}

static int Get_Parametr(const char* str, int i, char* sx)
{
    int j = 0;
    char s[10] = "";
    while ((str[i] != ' ') && (str[i] != ',') && (str[i] != ')')) {
        s[j] = str[i];
        i++;
        j++;
        if (j > 30) {
            return -1;
        }
    }
    s[j] = '\0';
    strcpy(sx, s);
    return i;
}

void Correct_Writing(const char* str, struct TCircle* circle, char* result)
{
    char check_str[] = "circle";
    size_t i;
    size_t j = -1;
    char sx[10] = "", sy[10] = "", sr[10] = "";

    if (strncmp(str, check_str, strlen(check_str)) != 0) {
        sprintf(result,
                "Mistake! Invalid input\n \"%s\" Not found \nDid you mean "
                "\"circle\"?\n",
                str);
        return;
    }
    i = strlen(check_str);

    i = Skip_Space(str, i);
    if (str[i] != '(') {
        sprintf(result, "Mistake! Invalid input\nNot found '('\n");
        return;
    }
    i++;

    i = Skip_Space(str, i);
    i = Get_Parametr(str, i, sx);
    if (i == j) {
        sprintf(result,
                "Mistake! Invalid input\nNot found parametr X function\n");
        return;
    }

    i = Skip_Space(str, i);
    i = Get_Parametr(str, i, sy);
    if (i == j) {
        sprintf(result,
                "Mistake! Invalid input\nNot found parametr Y function\n");
        return;
    }

    if (str[i] != ',') {
        sprintf(result, "Mistake! Invalid input\nNot found ','\n");
        return;
    }
    i++;

    i = Skip_Space(str, i);
    i = Get_Parametr(str, i, sr);
    if (i == j) {
        sprintf(result,
                "Mistake! Invalid input\nNot found parametr R function\n");
        return;
    }

    if (str[i] != ')') {
        sprintf(result, "Mistake! Invalid input\nNot found ')'\n");
        return;
    }

    if (i >= strlen(str)) {
        sprintf(result, "Mistake! Invalid input\nNot found ')'\n");
        return;
    }
    i++;

    i = Skip_Space(str, i);
    if ((i + 1) < strlen(str)) {
        sprintf(result, "Mistake! Invalid input\nUnexpected token\n");
        return;
    }

    if (!Convert_String(sx, &circle->x)) {
        sprintf(result, "Mistake! Invalid input\nParametr X\n");
        return;
    }
    if (!Convert_String(sy, &circle->y)) {
        sprintf(result, "Mistake! Invalid input\nParametr Y\n");
        return;
    }
    if (!Convert_String(sr, &circle->r)) {
        sprintf(result, "Mistake! Invalid input\nParametr R\n");
        return;
    }

    result[0] = 0;
}

void Calculate_area_and_perimeter(struct TCircle* c)
{
    const double pi = 3.141592;
    double p = 2 * pi * c->r;
    double s = pi * c->r * c->r;
    printf("perimetr=%f\narea=%f\n", p, s);
}
