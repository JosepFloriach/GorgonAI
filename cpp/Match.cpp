#include "Match.h"
#include <iostream>
Match::Match(long aId, const std::string& aWhitePlayerName, const std::string& aBlackPlayerName)
    : _id(aId)
    , _whitePlayerName(aWhitePlayerName)
    , _blackPlayerName(aBlackPlayerName)
    , _board(std::make_unique<Board>())
{
}

const std::vector<Intersection>& Match::InitMatch(int size)
{
    _board->Init(size);
    return _board->GetBoardState();
}

const std::vector<Intersection>& Match::PlayBlackStone(int8_t row, int8_t col)
{
    return _board->PlayStone(row, col, Board::StoneColor::COLOR_BLACK);
}

const std::vector<Intersection>& Match::PlayWhiteStone(int8_t row, int8_t col)
{
    return _board->PlayStone(row, col, Board::StoneColor::COLOR_WHITE);
}

const std::vector<Intersection>& Match::GetBoardState() const
{
    return _board->GetBoardState();
}

void Match::ResetMatch()
{
    _board->Reset();
}