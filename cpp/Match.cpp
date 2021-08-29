#include "Match.h"
#include <iostream>
Match::Match(long aId, const std::string& aWhitePlayerName, const std::string& aBlackPlayerName)
    : id(aId)
    , whitePlayerName(aWhitePlayerName)
    , blackPlayerName(aBlackPlayerName)
{
}

std::vector<int8_t> Match::InitMatch(int size)
{
    board.Init(size);
    return board.GetBoardState();
}

std::vector<int8_t> Match::PlayBlackStone(int8_t row, int8_t col)
{
    return board.PlayStone(row, col, Board::StoneColor::COLOR_BLACK);
}

std::vector<int8_t> Match::PlayWhiteStone(int8_t row, int8_t col)
{
    return board.PlayStone(row, col, Board::StoneColor::COLOR_WHITE);
}

std::vector<int8_t> Match::GetBoardState() const
{
    return board.GetBoardState();
}