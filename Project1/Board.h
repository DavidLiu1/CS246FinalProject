#include <vector>
#include <string>
#include "Block.h"

class Board {
	int score;
	std::vector<Block*> blocks;
	std::vector<std::vector<bool>> grid;
	Block* currBlock;
	Block* nextBlock;

public:
	Board();
	~Board();
	int getScore();
	int getLvl();
	Block* getCurrBlock();
	void moveLeft();
	void moveRight();
	void moveDown();
	void drop();
	virtual void rotateClock();
	virtual void rotateCounter();
};

