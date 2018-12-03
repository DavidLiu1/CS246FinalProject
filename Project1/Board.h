#include <vector>
#include <string>
#include "Block.h"
#include "Level.h"
class Board {
	int score;
	Level lvl;
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

	//return true  if it is at bottom after move
	bool moveDown();
	//deals with scoring
	int drop();
	void rotateClock();
	void rotateCounter();
};

