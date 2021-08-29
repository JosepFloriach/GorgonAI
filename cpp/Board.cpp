#include "Board.h"
#include <iostream>

const std::vector<int8_t>& Board::PlayStone(int8_t row, int8_t col, StoneColor color)
{	
	int index = GetFlattenedIndex(row, col);
	if (_board[index] == 0)
	{
		_board[index] = (int) color;
	}
	return _board;
}

const std::vector<int8_t>& Board::GetBoardState() const
{
	return _board;
}

void Board::Init(int size)
{
	_size = size;
	_board.clear();
	for(int idx = 0; idx < size * size; ++idx)
	{
		_board.push_back(0);
	}
}

int Board::GetFlattenedIndex(int8_t row, int8_t col) const
{	
	return (_size * row) + col;
}
