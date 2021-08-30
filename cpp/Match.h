#include "board/Board.h"
#include <string>
#include <vector>

class Match
{
    public:
        Match(long aId, const std::string& aWhitePlayerName, const std::string& aBLackPlayerName);

        void ResetMatch();

        std::vector<int8_t> InitMatch(int size);
        std::vector<int8_t> PlayBlackStone(int8_t row, int8_t col);
        std::vector<int8_t> PlayWhiteStone(int8_t row, int8_t col);
        std::vector<int8_t> GetBoardState() const;
    private:
        long id;
        const std::string& whitePlayerName;
        const std::string& blackPlayerName;
        Board board;
};
