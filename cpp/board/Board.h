#pragma once

#include <vector>
#include <memory>

#include "IBoard.h"
#include "RulesValidator.h"
#include "BoardData.h"
#include "Intersection.h"

class Board : public IBoard
{
	public:

		Board();

		void Reset() override;
		void Init(int size) override;
		const std::vector<Intersection>& PlayStone(int8_t row, int8_t col, StoneColor color) override;
		const std::vector<Intersection>& GetBoardState() const override;

	private:
		std::unique_ptr<IRulesValidator> _rulesValidator;
		std::unique_ptr<IBoardData> _data;
};