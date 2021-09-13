#pragma once

#include <vector>

#include "RulesValidator.h"
#include "BoardData.h"
#include "Intersection.h"

class IBoard
{
	public:
		enum StoneColor
		{
			COLOR_EMPTY,
			COLOR_BLACK,
			COLOR_WHITE
		};
			
		IBoard() = default;
		virtual ~IBoard() = default;
		
		IBoard(const IBoard&) = delete;
		IBoard(IBoard&&) = delete;
		IBoard& operator=(const IBoard&) = delete;
		IBoard& operator=(IBoard&&) = delete;

		virtual void Reset() = 0;
		virtual void Init(int size) = 0;
		virtual const std::vector<Intersection>& PlayStone(int8_t row, int8_t col, StoneColor color) = 0;
		virtual const std::vector<Intersection>& GetBoardState() const = 0;
};