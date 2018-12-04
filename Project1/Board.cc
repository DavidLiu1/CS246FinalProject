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
	currBlock = lvl->makeBlock();
	nextBlock = lvl->makeBlock();
	//std::cout << currBlock->getPointes().at(1).first << std::endl;
	//std::cout << currBlock->getPointes().at(1).second << std::endl;
}
Board::~Board()
{
	delete currBlock;
	delete nextBlock;

	for (int i = 0; i < blocks.size(); i++) {
		delete blocks.at(i);
	}
	delete lvl;
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

	if (lvl->getLevel() == 4) {
		if (blockPlaced % 5 == 0) {
			int index = rand() % 11;
			for (int i = 0; i < 11; i++) {
				if (!grid.at(7).at((i + index) % 11)) {
					grid.at(7).at((i + index) % 11) = true;
					goto afterloop;
				}
			}
			afterloop:
			checkFull(false);
		}
	}
	newBlock();
}
void Board::checkFull(bool b) {
	int row = 18;
	int numCleared = 0;
	bool isCleared = true;
	for (int i = 0; i < grid.size(); i++) {
		for (int j = 0; j < grid.at(i).size(); j++) {
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
					score += (blocks.at(k)->getLevel() + 1)*(blocks.at(k)->getLevel() + 1);
					delete blocks.at(k);
					blocks.erase(blocks.begin() + k);
					k--;
				}
			}
		}
		isCleared = true;
	}
	score += (numCleared == 0) ? 0: (numCleared + lvl->getLevel())*(numCleared + lvl->getLevel());
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
	for (int i = 0; i < currBlock->getPointes().size(); i++) {
		if (currBlock->getPointes().at(i).first == x && currBlock->getPointes().at(i).second == y) {
			return currBlock->getColor();
		}
	}
	if (!grid.at(y).at(x)) return "White";
	for (int i = 0; i < blocks.size(); i++) {
		for (int j = 0; j < blocks.at(i)->getPointes().size(); j++) {
			if (blocks.at(i)->getPointes().at(j).first == x && blocks.at(i)->getPointes().at(j).second == y) {
				return blocks.at(i)->getColor();
			}
		}
	}
	
	return "Brown";
}
int Board::getLastCleared() {
	return lastCleard;
}
void Board::levelUp()
{
	int level = lvl->getLevel();
	level++;
	if (level == -1) { return; }
	//can"t cheat lvl 5 penalty by lvl up
	if (level == 5) { return; }
	delete lvl;
	if (level == 0) {
		lvl = new Level0(file);
	}
	else if(level == 1) {
		lvl = new Level1();
	}
	else if(level == 2) {
		lvl = new Level2();
	}
	else if(level == 3) {
		lvl = new Level3();
	}
	else if(level == 4) {
		lvl = new Level4();
	}
}
void Board::levelDown()
{
	int level = lvl->getLevel()-1;
	if (level == -1) { return; }
	//can"t cheat lvl 4 penalty by lvl up
	if (level == 5) { return; }
	delete lvl;
	if (level == 0) {
		lvl = new Level0(file);
	}
	else if (level == 1) {
		lvl = new Level1();
	}
	else if (level == 2) {
		lvl = new Level2();
	}
	else if (level == 3) {
		lvl = new Level3();
	}
	else if (level == 4) {
		lvl = new Level4();
	}
}
void Board::setLevel(int level)
{
	if (lvl->getLevel() == level) {
		return;
	}
	if (level == 0) {
		lvl = new Level0(file);
	}
	else if (level == 1) {
		lvl = new Level1();
	}
	else if (level == 2) {
		lvl = new Level2();
	}
	else if (level == 3) {
		lvl = new Level3();
	}
	else if (level == 4) {
		lvl = new Level4();
	}
}
void Board::setSeq(std::string f)
{
	lvl = new Level0(f);
}
void Board::setNext(std::string b)
{
	delete nextBlock;
	if (b == "I") {
		nextBlock = new IBlock(false, 0);
	}
	else if (b == "J") {
		nextBlock = new JBlock(false, 0);
	}
	else if (b == "L") {
		nextBlock = new LBlock(false, 0);
	}
	else if (b == "O") {
		nextBlock = new OBlock(false, 0);
	}
	else if (b == "S") {
		nextBlock = new SBlock(false, 0);
	}
	else if (b == "Z") {
		nextBlock = new ZBlock(false, 0);
	}
	else if (b == "T") {
		nextBlock = new TBlock(false, 0);
	}
}
std::string Board::getNextType()
{
	return nextBlock->getText();
}
std::string Board::getNextColor()
{
	return nextBlock->getColor();
}
std::string Board::getType(int x, int y)
{
	//std::cout << "get ty st" << std::endl;
	for (int i = 0; i < currBlock->getPointes().size(); i++) {
		if (currBlock->getPointes().at(i).first == x && currBlock->getPointes().at(i).second == y) {
			return currBlock->getText();
		}
	}
	if (!grid.at(y).at(x)) { return " "; }
	//std::cout << "sad" << std::endl;
	//std::cout << blocks.size() << std::endl;
	for (int i = 0; i < blocks.size(); i++) {
		for (int j = 0; j < blocks.at(i)->getPointes().size(); j++) {
			if (blocks.at(i)->getPointes().at(j).first == x && blocks.at(i)->getPointes().at(j).second == y) {
				return blocks.at(i)->getText();
			}
		}
	}
	
	return "X";
	
}
std::vector<std::pair<int, int>> Board::getPointes()
{
	return currBlock->getPointes();
}
void Board::newBlock()
{
	currBlock = nextBlock;
	nextBlock = lvl->makeBlock();
}
bool Board::lost()
{
	for (int i = 0; i < 4; i++) {
		if (grid.at(currBlock->getPointes().at(i).second).at(currBlock->getPointes().at(i).first)) {
			return true;
		}
	}
	return false;
}
bool Board::isHeavy()
{
	return currBlock->isHeavy();
}
void Board::changeBlocks() {
	currBlock = nextBlock;
	nextBlock = lvl->makeBlock();
}