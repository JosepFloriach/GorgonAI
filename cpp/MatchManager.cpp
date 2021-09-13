#include "MatchManager.h"

MatchManager::MatchSetup::MatchSetup(const std::string& aWhitePlayerName, const std::string& aBlackPlayerName)
    : whitePlayerName(aWhitePlayerName)
    , blackPlayerName(aBlackPlayerName)
{
}

IMatch* MatchManager::GetMatchById(long id)
{
    auto matchIt = _matches.find(id);
    if (matchIt != _matches.end())
    {
        auto match = matchIt->second.get();
        return match;
    }        
    return nullptr;
}

long MatchManager::CreateMatch(const MatchSetup& setup)
{
    auto match = std::make_unique<Match>(_currentId, setup.blackPlayerName, setup.whitePlayerName);
    _matches.insert({_currentId, std::move(match)});
    return _currentId++;
}