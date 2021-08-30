#pragma once

#include <vector>

#include "BoardData.h"

class RulesValidator
{
	public:
		bool Validate(const BoardData& data, int8_t row, int8_t col, int8_t color) const;

	private:
			
};