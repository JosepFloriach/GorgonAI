#include "BoardData.h"

#include "../Utils/Utils.h"

void BoardData::PlaceStoneAndUpdateBoard(int8_t row, int8_t col, int8_t color)
{
    int index = Utils::Flatten2DCell(_size, row, col);
    _board[index] = color;
}

const std::vector<int8_t>& BoardData::GetBoardState() const
{
    return _board;
}

int BoardData::GetSize() const
{
    return _size;
}

void BoardData::Clear()
{
    _board.clear();
    _snakes.clear();
}

void BoardData::Init(int size)
{
    Clear();
    _size = size;
	for(int idx = 0; idx < size * size; ++idx)
	{
		_board.push_back(0);
	}
}