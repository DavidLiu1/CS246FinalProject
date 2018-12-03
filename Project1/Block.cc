#include "Block.h"



Block::Block(bool h,int l,std::string c)
	: heavy{ h }, level{ l }, color{ c }
{
	std::pair<int, int> p(0, 14);
	base = p;
}

bool Block::removeRow(int row)
{

	for (int i = 0; i < points.size(); i++) {
		if (points.at(i).second == row) {
			points.erase(points.begin() + i);
			i--;
		}
		else if (points.at(i).second > row) {
			points.at(i).second--;
		}
	}
	if (points.size() == 0) {
		return true;

	}
	else {
		return false;
	}
}


Block::~Block()
{
}

int Block::getLevel(){
	return level;
}
//in grid, true means theres is a block
void Block::moveLeft(std::vector<std::vector<bool>> const grid)
{
	bool canMove = true;
	for (unsigned i = 0; i < points.size(); i++) {
		if (points.at(i).first == 0 || grid.at(points.at(i).second).at(points.at(i).first - 1)) {
			canMove = false;
		}
	}
	if (canMove) {
		for (unsigned i = 0; i < points.size(); i++) {
			points.at(i).first--;
		}
		base.first--;
	}
}



void Block::moveRight(std::vector<std::vector<bool>> const grid)
{
	bool canMove = true;
	for (unsigned i = 0; i < points.size(); i++) {
		if (points.at(i).first == 10 || grid.at(points.at(i).second).at(points.at(i).first + 1)) {
			canMove = false;
		}
	}
	if (canMove) {
		for (unsigned i = 0; i < points.size(); i++) {
			points.at(i).first++;
		}
		base.first++;
	}
}

//return true  if it is at bottom after move
bool Block::moveDown(std::vector<std::vector<bool>> const grid)
{
	bool canMove = true;
	for (unsigned i = 0; i < points.size(); i++) {
		if (points.at(i).second == 0 || grid.at(points.at(i).second-1).at(points.at(i).first)) {
			canMove = false;
		}
	}
	if (canMove) {
		for (unsigned i = 0; i < points.size(); i++) {
			points.at(i).second--;
		}
		base.second--;
	}
	else {
		return true;
	}
	bool aIBottom = false;
	for (unsigned i = 0; i < points.size(); i++) {
		if (points.at(i).second == 0 || grid.at(points.at(i).second - 1).at(points.at(i).first)) {
			aIBottom = true;
		}
	}
	return aIBottom;
}

bool Block::filled(std::vector<std::vector<bool>> const grid)
{
	bool fill = false;
	for (unsigned i = 0; i < points.size(); i++) {
		if (grid.at(points.at(i).second).at(points.at(i).first)) {
			fill = true;
		}
	}
	return fill;
}

void Block::drop(std::vector<std::vector<bool>> const grid)
{
	while (!moveDown(grid));
}


std::vector<std::pair<int, int>> Block::getPointes()
{
	return points;
}

bool Block::isHeavy()
{
	return heavy;
}

std::string Block::getColor()
{
	return color;
}


