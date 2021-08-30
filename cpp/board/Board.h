#pragma once

#include <vector>

#include "RulesValidator.h"
#include "BoardData.h"

class Board
{
	public:
		enum StoneColor
		{
			COLOR_EMPTY,
			COLOR_BLACK,
			COLOR_WHITE
		};
			
		void Reset();
		void Init(int size);
		const std::vector<int8_t>& PlayStone(int8_t row, int8_t col, StoneColor color);
		const std::vector<int8_t>& GetBoardState() const;

	private:
		RulesValidator _rulesValidator;
		BoardData _data;

};