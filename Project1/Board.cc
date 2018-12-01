#include "Board.h"


class Block; //*********************

Board::Board()
{
	for (int i = 0; i < 18; i++) {
		std::vector<bool> temp(11, false);
		grid.push_back(temp);
	}
}
Board::~Board()
{
}
int Board::getLvl() {
	return lvl;
}
int Board::getScore() {
	return score;
}
Block* Board::getCurrBlock() {
	return currBlock;
}
void Board::moveLeft() {
	currBlock->moveLeft(grid);
}
void Board::moveRight() {
	currBlock->moveRight(grid);
}
bool Board::moveDown() {
	return currBlock->moveDown(grid);
}

//deals with scoring
void Board::drop() {
	currBlock->drop(grid);
	blocks.push_back(currBlock);
	std::vector <std::pair<int, int>> points = currBlock->getPointes();
	for (int i = 0; i < points.size(); i++) {
		grid.at(points.at(i).second).at(points.at(i).first) = true;
	}
	int numCleared = 0;
	bool isCleared = true;
	for (int i = 0; i < grid.size(); i++) {
		for (int j = 0; j < grid.at(i).size; j++) {
			if (!grid.at(i).at(j)) {
				isCleared = false;
			}
		}
		if (isCleared) {
			grid.erase(grid.begin() + i );
			numCleared++;
			isCleared = true;
			i--;
			for (int k = 0; k < blocks.size(); k++) {
				if (blocks.at(k)->removeRow(i)) {
					score += (blocks.at(k)->getLevel + 1)*(blocks.at(k)->getLevel + 1);
				}
			}
		}
	}
	score += (numCleared + lvl.getLevel())*(numCleared + lvl.getLevel());
	for (int i = 0; i < numCleared; i++) {
		std::vector<bool>  temp(11, false);
		grid.push_back(temp);
	}
	currBlock = nextBlock;
	nextBlock = lvl.getBlock();
}
void Board::rotateClock() {
	currBlock->rotateClock(grid);
}
void Board::rotateCounter() {
	currBlock->rotateCounter(grid);
}