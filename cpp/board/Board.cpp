#include "Board.h"
#include "../Utils/Utils.h"

const std::vector<int8_t>& Board::PlayStone(int8_t row, int8_t col, StoneColor color)
{	
	if (_rulesValidator.Validate(_data, row, col, color))
	{		
		_data.PlaceStoneAndUpdateBoard(row, col, (int) color);
	}
	return _data.GetBoardState();
}

const std::vector<int8_t>& Board::GetBoardState() const
{
	return _data.GetBoardState();
}

void Board::Init(int size)
{
	_data.Init(size);	
}

void Board::Reset()
{
	_data.Clear();
}