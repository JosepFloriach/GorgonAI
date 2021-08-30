#pragma once

#include <vector>

#include "Snake.h"

class BoardData
{
	public:	
		void PlaceStoneAndUpdateBoard(int8_t row, int8_t col, int8_t val);
		const std::vector<int8_t>& GetBoardState() const;		
		void Init(int size);
		void Clear();
		int GetSize() const;
	private:	
		std::vector<int8_t> _board;
		std::vector<Snake> _snakes;
		int _size;

};