#include "Board.h"


class Block; //*********************

Board::Board()
{
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
void Board::moveDown() {
	currBlock->moveDown(grid);
}
void Board::drop() {
	currBlock->drop(grid);
}
void Board::rotateClock() {
	currBlock->rotateClock(grid);
}
void Board::rotateCounter() {
	currBlock->rotateCounter(grid);
}