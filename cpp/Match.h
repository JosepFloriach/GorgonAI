#pragma once

#include "IMatch.h"
#include "board/Board.h"
#include "board/Intersection.h"

#include <string>
#include <vector>

class Match : public IMatch
{
    public:
        Match(long aId, const std::string& aWhitePlayerName, const std::string& aBLackPlayerName);

        void ResetMatch() override;
        const std::vector<Intersection>& InitMatch(int size) override;
        const std::vector<Intersection>& PlayBlackStone(int8_t row, int8_t col) override;
        const std::vector<Intersection>& PlayWhiteStone(int8_t row, int8_t col) override;
        const std::vector<Intersection>& GetBoardState() const override;

    private:
        long _id;
        const std::string& _whitePlayerName;
        const std::string& _blackPlayerName;
        std::unique_ptr<IBoard> _board;
};
