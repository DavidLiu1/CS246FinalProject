#include "ZBlock.h"



ZBlock::ZBlock(bool h, int l)
	:Block(h,l,"Magenta")
{
	points = { {0,16},{1,16},{1,15},{2,15} };
}


ZBlock::~ZBlock()
{
}

void ZBlock::rotateClock(std::vector<std::vector<bool>> const grid)
{
	int x = base.first;
	int y = base.second;
	if (state == 1) {
		if (!(grid.at(y + 2).at(x+1) ||
			grid.at(y + 1).at(x) ||
			grid.at(y + 1).at(x + 1) ||
			grid.at(y).at(x))) {
			points = { {x+1,y + 2}, {x,y + 1}, {x + 1, y + 1},{x ,y} };
			state = 2;
		}
	}
	else {
		if (!(grid.at(y+1).at(x) ||
			grid.at(y).at(x + 1) ||
			grid.at(y + 1).at(x + 1) ||
			grid.at(y ).at(x + 2))) {
			points = { {x,y+1},{x + 1,y},{x + 1,y + 1},{x + 2,y} };
			state = 1;
		}
	}
}

void ZBlock::rotateCounter(std::vector<std::vector<bool>> const grid)
{
	int x = base.first;
	int y = base.second;
	if (state == 1) {
		if (!(grid.at(y + 2).at(x + 1) ||
			grid.at(y + 1).at(x) ||
			grid.at(y + 1).at(x + 1) ||
			grid.at(y).at(x))) {
			points = { {x + 1,y + 2}, {x,y + 1}, {x + 1, y + 1},{x ,y} };
			state = 2;
		}
	}
	else {
		if (!(grid.at(y + 1).at(x) ||
			grid.at(y).at(x + 1) ||
			grid.at(y + 1).at(x + 1) ||
			grid.at(y).at(x + 2))) {
			points = { {x,y + 1},{x + 1,y},{x + 1,y + 1},{x + 2,y} };
			state = 1;
		}
	}
}

std::string ZBlock::getText()
{
	return "Z";
}
