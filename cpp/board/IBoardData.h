#pragma once

#include <vector>
#include "Intersection.h"

class IBoardData
{
	public:

		IBoardData() = default;
		virtual ~IBoardData() = default;
		IBoardData(const IBoardData&) = delete;
		IBoardData(IBoardData&&) = delete;
		IBoardData& operator=(const IBoardData&) = delete;
		IBoardData& operator=(IBoardData&&) = delete;

		virtual void PlaceStoneAndUpdateBoard(int8_t row, int8_t col, int8_t val) = 0;
		virtual const std::vector<Intersection>& GetBoardState() const = 0;	
		virtual void Init(int size) = 0;
		virtual void Clear() = 0;
		virtual int GetSize() const = 0;
		virtual int GetLibertiesCount(int8_t row, int8_t col) const = 0;
};