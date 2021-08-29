#include "Match.h"
#include <unordered_map>
#include <string>

class MatchManager
{
public:
    struct MatchSetup
    {
        const std::string& whitePlayerName;
        const std::string& blackPlayerName;

        MatchSetup(const std::string& aWhitePlayerName, const std::string& aBlackPlayerName);
    };

    Match* GetMatchById(long id);
    long CreateMatch(const MatchSetup& setup);

private:
    std::unordered_map<long, Match> matches;
    long currentId = 0;
};