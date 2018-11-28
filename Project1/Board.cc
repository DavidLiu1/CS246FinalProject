#include "Board.h"



Board::Board()
{
}
Board::~Board()
{
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