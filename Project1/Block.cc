#include "Block.h"



Block::Block(bool h)
	: heavy{ h }
{
	std::pair<int, int> p(0, 14);
	base = p;

}


Block::~Block()
{
}

void Block::moveLeft(std::vector<std::vector<bool>> grid)
{
	bool canMove = true;
	for (unsigned i = 0; i < points.size(); i++) {
		if (points.at(i).first != 0 && grid.at(points.at(i).second).at(points.at(i).first - 1)) {
			canMove = false;
		}
	}
	if (canMove) {
		for (unsigned i = 0; i < points.size(); i++) {
			points.at(i).first--;
		}
	}
}

void Block::moveRight(std::vector<std::vector<bool>> grid)
{
	bool canMove = true;
	for (unsigned i = 0; i < points.size(); i++) {
		if (points.at(i).first != 10 && grid.at(points.at(i).second).at(points.at(i).first + 1)) {
			canMove = false;
		}
	}
	if (canMove) {
		for (unsigned i = 0; i < points.size(); i++) {
			points.at(i).first++;
		}
	}
}

void Block::moveDown(std::vector<std::vector<bool>> grid)
{
}

void Block::moveBottem(std::vector<std::vector<bool>> grid)
{
}

void Block::rotateClock(std::vector<std::vector<bool>> grid)
{
}

void Block::rotateCounter(std::vector<std::vector<bool>> grid)
{
}

std::vector<std::pair<int, int>> Block::getPointes()
{
	return std::vector<std::pair<int, int>>();
}

bool Block::isHeavy()
{
	return false;
}
