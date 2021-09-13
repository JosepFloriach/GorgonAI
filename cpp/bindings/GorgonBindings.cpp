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

std::vector<int> GetRawState(const std::vector<Intersection>& state)
{
	std::vector<int> rawState;
	for(auto intersection: state)
	{
		rawState.push_back(intersection.Color);
	}
	return rawState;
}

emscripten::val resize_board(long instanceId, int squaredSize)
{
	auto match = matchManager.GetMatchById(instanceId);
	if (match)
	{
		auto& state = match->InitMatch(squaredSize);
		auto rawState = GetRawState(state);
		return emscripten::val(emscripten::typed_memory_view(rawState.size(), rawState.data()));
	}
	return emscripten::val(nullptr);
}

emscripten::val play_white_stone(long instanceId, int row, int col)
{
	auto match = matchManager.GetMatchById(instanceId);
	if (match)
	{
		auto& state = match->PlayWhiteStone(row, col);
		auto rawState = GetRawState(state);
		return emscripten::val(emscripten::typed_memory_view(rawState.size(), rawState.data()));
	}
	return emscripten::val(nullptr);
}

emscripten::val play_black_stone(long instanceId, int row, int col)
{
	auto match = matchManager.GetMatchById(instanceId);
	if (match)
	{
		auto& state = match->PlayBlackStone(row, col);
		auto rawState = GetRawState(state);
		return emscripten::val(emscripten::typed_memory_view(rawState.size(), rawState.data()));
	}
	return emscripten::val(nullptr);
}

emscripten::val get_board_state(long instanceId)
{
	auto match = matchManager.GetMatchById(instanceId);
	if (match)
	{
		auto& state = match->GetBoardState();
		auto rawState = GetRawState(state);
		return emscripten::val(emscripten::typed_memory_view(rawState.size(), rawState.data()));
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

#ifdef __cplusplus
}
#endif