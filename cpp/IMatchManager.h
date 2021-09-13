#pragma once

#include "Match.h"
#include <string>

class IMatchManager
{
public:
    struct MatchSetup
    {
        const std::string& whitePlayerName;
        const std::string& blackPlayerName;

        MatchSetup(const std::string& aWhitePlayerName, const std::string& aBlackPlayerName);
    };

    IMatchManager() = default;
    virtual ~IMatchManager() = default;
    
    IMatchManager(const IMatchManager&) = delete;
    IMatchManager(IMatchManager&&) = delete;
    IMatchManager& operator=(const IMatchManager&) = delete;
    IMatchManager& operator=(IMatchManager&&) = delete;


    virtual IMatch* GetMatchById(long id) = 0;
    virtual long CreateMatch(const MatchSetup& setup) = 0;
};