#include "MatchManager.h"

MatchManager::MatchSetup::MatchSetup(const std::string& aWhitePlayerName, const std::string& aBlackPlayerName)
    : whitePlayerName(aWhitePlayerName)
    , blackPlayerName(aBlackPlayerName)
{
}

Match* MatchManager::GetMatchById(long id)
{
    auto matchIt = matches.find(id);
    if (matchIt != matches.end())
        return &matchIt->second;
    return nullptr;
}

long MatchManager::CreateMatch(const MatchSetup& setup)
{
    Match match(currentId, setup.blackPlayerName, setup.whitePlayerName);
    std::pair<long, Match> newMatch (currentId, match);
    matches.insert(newMatch);
    return currentId++;
}