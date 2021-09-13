#pragma once

#include <vector>

#include "IRulesValidator.h"
#include "BoardData.h"

class RulesValidator : public IRulesValidator
{
	public:
		bool Validate(const IBoardData& data, int8_t row, int8_t col, int8_t color) const override;

};