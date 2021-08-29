#include <vector>

class Board
{
	public:
		enum StoneColor
		{
			COLOR_EMPTY,
			COLOR_BLACK,
			COLOR_WHITE
		};
			
		void Init(int size);
		const std::vector<int8_t>& PlayStone(int8_t row, int8_t col, StoneColor color);
		const std::vector<int8_t>& GetBoardState() const;
	private:
	
		int GetFlattenedIndex(int8_t row, int8_t col) const;
	
		std::vector<int8_t> _board;
		int _size;
};