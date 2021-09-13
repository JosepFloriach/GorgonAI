#pragma once

#include "../board/Board.h"
#include <string>
#include <vector>

class Utils
{
    public:

        static int Flatten2DCell(int colCount, int row, int col)
        {
            return (colCount * row) + col;
        }        
};
