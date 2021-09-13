#pragma once

#include <vector>

#include "BoardData.h"

class IRulesValidator
{
	public:

		IRulesValidator() = default;
		virtual ~IRulesValidator() = default;
		IRulesValidator(const IRulesValidator&) = delete;
		IRulesValidator(IRulesValidator&&) = delete;
		IRulesValidator& operator=(const IRulesValidator&) = delete;
		IRulesValidator& operator=(IRulesValidator&&) = delete;

		virtual bool Validate(const IBoardData& data, int8_t row, int8_t col, int8_t color) const = 0;			
};