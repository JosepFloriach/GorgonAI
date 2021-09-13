#include "BoardData.h"

#include "../Utils/Utils.h"
#include <array>
#include <iostream>

void BoardData::PlaceStoneAndUpdateBoard(int8_t row, int8_t col, int8_t color)
{
    int index = Utils::Flatten2DCell(_size, row, col);
    auto& intersection = _board[index];
    intersection.Color = color;
}

const Intersection& BoardData::GetIntersectionAt(int8_t row, int8_t col) const
{
    int index = Utils::Flatten2DCell(_size, row, col);
    return _board[index];
}

const std::vector<Intersection>& BoardData::GetBoardState() const
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
    if (size == -1)
    {
        throw std::invalid_argument("Size must be greater than 0");
    }

    Clear();
    _size = size;
	for(int row = 0; row < size; ++row)    
	{
        for (int col = 0; col < size; ++col)
        {
            Intersection intersection(row, col);
            _board.push_back(intersection);
        }
	}
}

int BoardData::GetLibertiesCount(int8_t row, int8_t col) const
{
    return 1;
}

std::vector<const Intersection*> BoardData::GetNeighbours(int8_t row, int8_t col) const
{
    std::array<int8_t, 4> verticalDirections {-1, 0, 0, 1};
    std::array<int8_t, 4> horizontalDirections {0, -1, 1, 0};
    std::vector<const Intersection*> neighbours;

    for (int idx = 0; idx < verticalDirections.size(); ++idx)
    {
        int neighbourRow = row + verticalDirections[idx];
        int neighbourCol = col + horizontalDirections[idx];
        if (neighbourRow >= 0 && neighbourRow < _size && 
            neighbourCol >= 0 && neighbourCol < _size)
        {
            const auto& intersection = GetIntersectionAt(neighbourRow, neighbourCol);
            neighbours.push_back(&intersection);
        }
    }
    return neighbours;
}

std::vector<const Intersection*> BoardData::GetSameColorNeighbours(int8_t row, int8_t col) const
{
    std::array<int8_t, 4> verticalDirections {-1, 0, 0, 1};
    std::array<int8_t, 4> horizontalDirections {0, -1, 1, 0};
    std::vector<const Intersection*> neighbours;

    int originalColor = GetIntersectionAt(row, col).Color;

    for (int idx = 0; idx < verticalDirections.size(); ++idx)
    {
        int neighbourRow = row + verticalDirections[idx];
        int neighbourCol = col + horizontalDirections[idx];       
        if (neighbourRow >= 0 && neighbourRow < _size && 
            neighbourCol >= 0 && neighbourCol < _size)
        {
            const auto& currNeighbour = GetIntersectionAt(neighbourRow, neighbourCol);
            if (currNeighbour.Color == originalColor && currNeighbour.Color != 0)
            {
                neighbours.push_back(&currNeighbour);
            }
        }
    }
    return neighbours;
}

std::vector<const Intersection*> BoardData::GetDifferentColorNeighbours(int8_t row, int8_t col) const
{
    std::array<int8_t, 4> verticalDirections {-1, 0, 0, 1};
    std::array<int8_t, 4> horizontalDirections {0, -1, 1, 0};
    std::vector<const Intersection*> neighbours;

    int originalColor = GetIntersectionAt(row, col).Color;

    for (int idx = 0; idx < verticalDirections.size(); ++idx)
    {
        int neighbourRow = row + verticalDirections[idx];
        int neighbourCol = col + horizontalDirections[idx];       
        if (neighbourRow >= 0 && neighbourRow < _size && 
            neighbourCol >= 0 && neighbourCol < _size)
        {
            const auto& currNeighbour = GetIntersectionAt(neighbourRow, neighbourCol);
            if (currNeighbour.Color != originalColor && currNeighbour.Color != 0)
            {
                neighbours.push_back(&currNeighbour);
            }
        }
    }
    return neighbours;
}

std::vector<const Intersection*> BoardData::GetEmptyNeighbours(int8_t row, int8_t col) const
{
    std::array<int8_t, 4> verticalDirections {-1, 0, 0, 1};
    std::array<int8_t, 4> horizontalDirections {0, -1, 1, 0};
    std::vector<const Intersection*> neighbours;

    for (int idx = 0; idx < verticalDirections.size(); ++idx)
    {
        int neighbourRow = row + verticalDirections[idx];
        int neighbourCol = col + horizontalDirections[idx];       
        if (neighbourRow >= 0 && neighbourRow < _size && 
            neighbourCol >= 0 && neighbourCol < _size)
        {
            const auto& currNeighbour = GetIntersectionAt(neighbourRow, neighbourCol);
            if (currNeighbour.Color == 0)
            {
                neighbours.push_back(&currNeighbour);
            }
        }
    }
    return neighbours;
}