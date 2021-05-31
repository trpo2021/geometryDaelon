#ifndef GEOMETRY_H
#define GEOMETRY_H

struct TCircle {
    double x, y, r;
};

void Correct_Writing(const char* str, struct TCircle* c, char* result);

void Calculate_area_and_perimeter(struct TCircle* c);

#endif
