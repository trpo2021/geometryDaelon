#include "geometry.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

static double sqr(double v)
{
    return v * v;
}

int main()
{
    const int max_symb = 40;
    FILE* input;
    char result[150];
    input = fopen("input.txt", "r");
    if (input == NULL) {
        printf("Error open file\n");
        return 1;
    }
    char source_str[max_symb];

    struct TCircle* lst[100];
    int cnt = 0;
    struct TCircle *c, *c2;

    while (!feof(input)) {
        source_str[0] = 0;

        fgets(source_str, sizeof(source_str), input);
        if (source_str[0] == 0)
            break;

        fputs(source_str, stdout);

        c = (struct TCircle*)malloc(100);

        Correct_Writing(source_str, c, result);

        if (result[0] != 0)
            printf("%s\n", result);

        Calculate_area_and_perimeter(c);

        lst[cnt++] = c;
    }

    printf("Total %d circles\n", cnt);
    fclose(input);

    for (int i = 0; i < cnt; i++) {
        c = lst[i];

        for (int j = i + 1; j < cnt; j++) {
            c2 = lst[j];

            if (sqr(c->x - c2->x) + sqr(c->y - c2->y)
                <= abs((int)(c->r - c2->r)))
                printf("Circle %d and %d intersects\n", i, j);
        }
    }
    getchar();
    return 0;
}