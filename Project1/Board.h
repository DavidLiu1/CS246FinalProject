#include <vector>
#include <string>
#include "Block.h"
#include "Level.h"
#include "Level0.h"
class Board {
	int score;
	int lastCleard;
	Level* lvl;
	std::string file;
	std::vector<Block*> blocks;
	std::vector<std::vector<bool>> grid;
	Block* currBlock;
	Block* nextBlock;
	//store how many blocks placed since last clear
	int blockPlaced;
	//check if a row is full and reeacts
	//deals with scoring
	//b is true if block is put in, false if mud is put in
	bool checkFull(bool b);
	void changeBlocks();
public:
	Board(std::string f);
	~Board();
	int getScore();
	int getLvl();
	Block* getCurrBlock();
	void moveLeft();
	void moveRight();

	//return true  if it is at bottom after move
	bool moveDown();
	//deals with scoring
	void drop();
	void rotateClock();
	void rotateCounter();
	std::string getColor(int, int);
	int getLastCleared();
	
};

