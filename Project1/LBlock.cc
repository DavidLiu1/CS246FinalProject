#include "LBlock.h"



LBlock::LBlock(bool h, int l)
	:Block(h,l,"Yellow")
{
	points = { {0,14},{1,14},{2,14},{2,14} };
}


LBlock::~LBlock()
{
}

void LBlock::rotateClock(std::vector<std::vector<bool>> const grid)
{
	int x = base.first;
	int y = base.second;
	if (state == 1) {
		if (!(grid.at(y + 1).at(x) ||
			grid.at(y).at(x) ||
			grid.at(y + 2).at(x) ||
			grid.at(y).at(x + 1))) {
			points = { {x,y + 1}, {x,y}, {x, y + 2},{x + 1,y} };
			state = 2;
		}
	}
	else if (state == 2) {
		if (!(grid.at(y + 1).at(x) ||
			grid.at(y + 1).at(x + 1) ||
			grid.at(y + 1).at(x + 2) ||
			grid.at(y).at(x))) {
			points = { {x,y + 1},{x + 1,y + 1},{x + 2,y + 1},{x,y} };
			state = 3;
		}
	}
	else if (state == 3) {
		if (!(grid.at(y+2).at(x) ||
			grid.at(y).at(x + 1) ||
			grid.at(y + 1).at(x + 1) ||
			grid.at(y + 2).at(x + 1))) {
			points = { {x,y+2},{x + 1,y},{x + 1,y + 1},{x + 1 ,y + 2} };
			state = 4;
		}
	}
	else {
		if (!(grid.at(y + 1).at(x+2) ||
			grid.at(y).at(x) ||
			grid.at(y).at(x + 1) ||
			grid.at(y).at(x + 2))) {
			points = { {x+2,y + 1},{x,y},{x + 1,y},{x + 2,y} };
			state = 1;
		}
	}
}

void LBlock::rotateCounter(std::vector<std::vector<bool>> const grid)
{
	int x = base.first;
	int y = base.second;
	if (state == 3) {
		if (!(grid.at(y + 1).at(x) ||
			grid.at(y).at(x) ||
			grid.at(y + 2).at(x) ||
			grid.at(y).at(x + 1))) {
			points = { {x,y + 1}, {x,y}, {x, y + 2},{x + 1,y} };
			state = 2;
		}
	}
	else if (state == 4) {
		if (!(grid.at(y + 1).at(x) ||
			grid.at(y + 1).at(x + 1) ||
			grid.at(y + 1).at(x + 2) ||
			grid.at(y).at(x))) {
			points = { {x,y + 1},{x + 1,y + 1},{x + 2,y + 1},{x,y} };
			state = 3;
		}
	}
	else if (state == 1) {
		if (!(grid.at(y + 2).at(x) ||
			grid.at(y).at(x + 1) ||
			grid.at(y + 1).at(x + 1) ||
			grid.at(y + 2).at(x + 1))) {
			points = { {x,y + 2},{x + 1,y},{x + 1,y + 1},{x + 1 ,y + 2} };
			state = 4;
		}
	}
	else {
		if (!(grid.at(y + 1).at(x + 2) ||
			grid.at(y).at(x) ||
			grid.at(y).at(x + 1) ||
			grid.at(y).at(x + 2))) {
			points = { {x + 2,y + 1},{x,y},{x + 1,y},{x + 2,y} };
			state = 1;
		}
	}
}

std::string LBlock::getText()
{
	return "L";
}
