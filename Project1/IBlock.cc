#include "IBlock.h"



IBlock::IBlock(bool h, int l)
	:Block(h,l,"Red")
{
	points = { {0,15},{1,15},{2,15},{3,15} };
}


IBlock::~IBlock()
{
}

void IBlock::rotateClock(std::vector<std::vector<bool>> const grid)
{
	int x = base.first;
	int y = base.second;
	if (state == 1) {
		if (!(grid.at(y).at(x) ||
			grid.at(y+3).at(x) ||
			grid.at(y + 1).at(x) ||
			grid.at(y + 2).at(x))) {
			points = { {x,y + 1}, {x,y}, {x, y + 2},{x,y + 3} };
			state = 2;
		}
	}
	else {
		if (!(grid.at(y).at(x) ||
			grid.at(y).at(x + 1) ||
			grid.at(y).at(x + 2) ||
			grid.at(y).at(x + 3))) {
			points = { {x,y},{x + 1,y},{x + 2,y},{x + 3,y} };
			state = 1;
		}
	}
}

void IBlock::rotateCounter(std::vector<std::vector<bool>> const grid)
{
	int x = base.first;
	int y = base.second;
	if (state == 1) {
		if (!(grid.at(y).at(x) ||
			grid.at(y + 3).at(x) ||
			grid.at(y + 1).at(x) ||
			grid.at(y + 2).at(x))) {
			points = { {x,y + 1}, {x,y}, {x, y + 2},{x,y + 3} };
			state = 2;
		}
	}
	else {
		if (!(grid.at(y).at(x) ||
			grid.at(y).at(x + 1) ||
			grid.at(y).at(x + 2) ||
			grid.at(y).at(x + 3))) {
			points = { {x,y},{x + 1,y},{x + 2,y},{x + 3,y} };
			state = 1;
		}
	}
}
