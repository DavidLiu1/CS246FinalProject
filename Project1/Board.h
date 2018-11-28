#include <vector>
#include <string>
#include "Block.h"

class Board {
	int score;
	std::vector<Block*> blocks;
	std::vector<std::vector<bool>> grid;
	Block currBlock;
	Block nextBlock;

public:
	Board();
	~Board();
	int getScore();
	int getLvl();
	Block getCurrBlock();
	std::vector<std::vector<bool>> getGrid();
};

