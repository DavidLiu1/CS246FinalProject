#ifndef _BOARD_H_
#define _BOARD_H_
#include <vector>
#include <string>
#include "Block.h"
#include "Level.h"
#include "Level0.h"
#include "Level1.h"
#include "Level2.h"
#include "Level3.h"
#include "Level4.h"
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
	void checkFull(bool b);
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
	void levelUp();
	void levelDown();
	void setLevel(int i);
	void setSeq(std::string f);
	void setNext(std::string b);
	std::string getNextType();
	std::string getType(int x, int y);
	std::vector <std::pair<int, int>> getPointes();
	void newBlock();

};

#endif