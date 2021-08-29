#include "../MatchManager.h"

#include <vector>
#include <emscripten/emscripten.h>
#include <emscripten/bind.h>
#include <emscripten/val.h>
#include <string>
#include <iostream>

#ifdef __cplusplus
extern "C" {
#endif

MatchManager matchManager;

long create_match()
{
	MatchManager::MatchSetup setup(std::string("player1"), std::string("player2"));
	return matchManager.CreateMatch(setup);
}

emscripten::val resize_board(long instanceId, int squaredSize)
{
	auto match = matchManager.GetMatchById(instanceId);
	if (match)
	{
		auto state = match->InitMatch(squaredSize);
		return emscripten::val(emscripten::typed_memory_view(state.size(), state.data()));
	}
	return emscripten::val(nullptr);
}

emscripten::val play_white_stone(long instanceId, int row, int col)
{
	auto match = matchManager.GetMatchById(instanceId);
	if (match)
	{
		auto state = match->PlayWhiteStone(row, col);
		return emscripten::val(emscripten::typed_memory_view(state.size(), state.data()));	
	}
	return emscripten::val(nullptr);
}

emscripten::val play_black_stone(long instanceId, int row, int col)
{
	auto match = matchManager.GetMatchById(instanceId);
	if (match)
	{
		auto state = match->PlayBlackStone(row, col);
		return emscripten::val(emscripten::typed_memory_view(state.size(), state.data()));
	}
	return emscripten::val(nullptr);
}

emscripten::val get_board_state(long instanceId)
{
	auto match = matchManager.GetMatchById(instanceId);
	if (match)
	{
		auto state = match->GetBoardState();
		return emscripten::val(emscripten::typed_memory_view(state.size(), state.data()));
	}
	return emscripten::val(nullptr);
}

EMSCRIPTEN_BINDINGS() 
{
	emscripten::function("create_match", &create_match);
	emscripten::function("resize_board", &resize_board);
	emscripten::function("play_white_stone", &play_white_stone);
	emscripten::function("play_black_stone", &play_black_stone);
}

/*EMSCRIPTEN_KEEPALIVE const int8_t* InitEmptyBoard(long instanceId, int squaredSize) {	
	//board.clear();
	//boardSize = squaredSize;
	for(int idx = 0; idx < squaredSize*squaredSize; ++idx)
	{
		board.push_back(0);
	}
	//auto boardPtr = &board[0];
	Board board;
	board.Init(squaredSize);
	auto boardPtr = &board.GetBoardState()[0];
	return boardPtr;
}*/
/*
EMSCRIPTEN_KEEPALIVE int8_t* AddWhiteStone(long instanceId, int row, int col)
{
	int index = (boardSize * row) + col;
	board[index] = 2;
	auto boardPtr = &board[0];
	return boardPtr;
}

EMSCRIPTEN_KEEPALIVE int8_t* AddBlackStone(long instanceId, int row, int col)
{
	int index = (boardSize * row) + col;
	board[index] = 1;
	auto boardPtr = &board[0];
	return boardPtr;
}

EMSCRIPTEN_KEEPALIVE int8_t GetAffectedPositionsByLastPlayCount()
{
	return 8;
}

EMSCRIPTEN_KEEPALIVE int8_t* GetAffectedPositionsByLastPlay()
{
	std::vector<int8_t> affectedStones;
	for(int idx = 0; idx < 8; ++idx)
	{
		affectedStones.push_back(6);
	}
	
	auto boardPtr = &affectedStones[0];
	return boardPtr;
}*/

#ifdef __cplusplus
}
#endif