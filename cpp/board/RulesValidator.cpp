#include "RulesValidator.h"
#include "Intersection.h"
#include "../Utils/Utils.h"

bool RulesValidator::Validate(const IBoardData& data, int8_t row, int8_t col, int8_t color) const
{
    const auto board = data.GetBoardState();
    int size = data.GetSize();
    int index = Utils::Flatten2DCell(size, row, col);
    
	bool isEmpty = board[index].Color == 0;
	bool hasLiberties = data.GetLibertiesCount(row, col) > 0;
	bool koRule = true; 
	
	return isEmpty && hasLiberties && koRule;
}