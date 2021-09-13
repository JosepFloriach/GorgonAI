#pragma once

#include "board/Intersection.h"
#include <vector>

class IMatch
{
    public:

        IMatch() = default;
		virtual ~IMatch() = default;
		
		IMatch(const IMatch&) = delete;
		IMatch(IMatch&&) = delete;
		IMatch& operator=(const IMatch&) = delete;
		IMatch& operator=(IMatch&&) = delete;

        virtual void ResetMatch() = 0;
        virtual const std::vector<Intersection>& InitMatch(int size) = 0;
        virtual const std::vector<Intersection>& PlayBlackStone(int8_t row, int8_t col) = 0;
        virtual const std::vector<Intersection>& PlayWhiteStone(int8_t row, int8_t col) = 0;
        virtual const std::vector<Intersection>& GetBoardState() const = 0;
};
