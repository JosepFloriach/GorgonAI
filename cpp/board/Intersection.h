#pragma once

#include <vector>

struct Intersection
{
    int8_t Row;    
    int8_t Col;
    int8_t Color;

    Intersection(int8_t row, int8_t col)
    : Row(row)
    , Col(col)
    , Color(0)
    {
    }
};