#include "Board.h"


class Block; //*********************

Board::Board(std::string f)
	:file{ f }, lastCleard{ 0 }, blockPlaced{ 0 }
{
	for (int i = 0; i < 18; i++) {
		std::vector<bool> temp(11, false);
		grid.push_back(temp);
	}
	lvl = new Level0(file);

}
Board::~Board()
{
	delete currBlock;
	delete nextBlock;
	for (int i = 0; i < blocks.size(); i++) {
		delete blocks.at(i);
	}
}
int Board::getLvl() {
	return lvl->getLevel();
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


void Board::drop() {
	currBlock->drop(grid);
	blocks.push_back(currBlock);
	std::vector <std::pair<int, int>> points = currBlock->getPointes();
	for (int i = 0; i < points.size(); i++) {
		grid.at(points.at(i).second).at(points.at(i).first) = true;
	}
	checkFull(true);

	if (lvl->getLevel == 4) {
		if (blockPlaced % 5 == 0) {
			int index = rand() % 11;
			for (int i = 0; i < 11; i++) {
				if (!grid.at(7).at((i + index) % 11)) {
					grid.at(7).at((i + index) % 11) = true;
				}
			}
		}
	}
	checkFull(false);
}
bool Board::checkFull(bool b) {
	int row = 18;
	int numCleared = 0;
	bool isCleared = true;
	for (int i = 0; i < grid.size(); i++) {
		for (int j = 0; j < grid.at(i).size; j++) {
			if (!grid.at(i).at(j)) {
				isCleared = false;
			}
		}
		if (isCleared) {
			if (i < row) {
				row = i;
			}
			grid.erase(grid.begin() + i);
			numCleared++;
			isCleared = true;
			i--;
			for (int k = 0; k < blocks.size(); k++) {
				if (blocks.at(k)->removeRow(i)) {
					score += (blocks.at(k)->getLevel + 1)*(blocks.at(k)->getLevel + 1);
					delete blocks.at(k);
					blocks.erase(blocks.begin + k);
					k--;
				}
			}
		}
	}
	score += (numCleared + lvl->getLevel())*(numCleared + lvl->getLevel());
	for (int i = 0; i < numCleared; i++) {
		std::vector<bool>  temp(11, false);
		grid.push_back(temp);
	}

	if (numCleared == 0) {
		lastCleard = -1;
		if (b) { blockPlaced++; }
	}
	else {
		lastCleard = row;
		blockPlaced = 0;
	}
}
void Board::rotateClock() {
	currBlock->rotateClock(grid);
}
void Board::rotateCounter() {
	currBlock->rotateCounter(grid);
}
std::string Board::getColor(int x, int y) {
	if (!grid.at(x).at(y)) return "White";
	for (auto const& block : blocks) {
		for (auto const& coord : block->getPointes()) {
			if (x == coord.first && y == coord.second) {
				return block->getColor();
			}
		}
	}
	return "Brown";
}
int Board::getLastCleared() {
	return lastCleard;
}
void Board::changeBlocks() {
	currBlock = nextBlock;
	nextBlock = lvl->makeBlock();
}