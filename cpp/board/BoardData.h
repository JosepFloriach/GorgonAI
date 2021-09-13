#pragma once

#include <vector>

#include "IBoardData.h"
#include "Snake.h"
#include "Intersection.h"


class BoardData : public IBoardData
{
	public:	
		void PlaceStoneAndUpdateBoard(int8_t row, int8_t col, int8_t val) override;
		const std::vector<Intersection>& GetBoardState() const override;
		void Init(int size) override;
		void Clear() override;
		int GetSize() const override;
		int GetLibertiesCount(int8_t row, int8_t col) const override;

	private:

		const Intersection& GetIntersectionAt(int8_t row, int8_t col) const;

		std::vector<const Intersection*> GetNeighbours(int8_t row, int8_t col) const; 
		std::vector<const Intersection*> GetSameColorNeighbours(int8_t row, int8_t col) const;
		std::vector<const Intersection*> GetDifferentColorNeighbours(int8_t row, int8_t col) const;
		std::vector<const Intersection*> GetEmptyNeighbours(int8_t row, int8_t col) const;

		std::vector<Intersection> _board;
		std::vector<Snake> _snakes;
		int _size;

};