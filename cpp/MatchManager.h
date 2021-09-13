#pragma once

#include "IMatchManager.h"
#include "Match.h"
#include <unordered_map>
#include <string>

class MatchManager : public IMatchManager
{
public:
    IMatch* GetMatchById(long id) override;
    long CreateMatch(const MatchSetup& setup) override;

private:
    std::unordered_map<long, std::unique_ptr<IMatch>> _matches;
    long _currentId = 0;
};