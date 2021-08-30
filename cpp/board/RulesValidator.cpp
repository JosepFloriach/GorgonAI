#include "RulesValidator.h"
#include "../Utils/Utils.h"

bool RulesValidator::Validate(const BoardData& data, int8_t row, int8_t col, int8_t color) const
{
    const auto board = data.GetBoardState();
    int size = data.GetSize();
    int index = Utils::Flatten2DCell(size, row, col);
    
	bool isEmpty = board[index] == 0;
	bool hasLiberties = true;
	bool koRule = true; 
	
	return isEmpty && hasLiberties && koRule;
}