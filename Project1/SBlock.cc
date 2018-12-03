#include "SBlock.h"



SBlock::SBlock(bool h, int l)
	:Block(h,l,"Cyan")
{
	points = { {0,15},{1,15},{1,16},{2,16} };
}


SBlock::~SBlock()
{
}

void SBlock::rotateClock(std::vector<std::vector<bool>> const grid)
{
	int x = base.first;
	int y = base.second;
	if (state == 1) {
		if (!(grid.at(y + 2).at(x) ||
			grid.at(y+1).at(x) ||
			grid.at(y + 1).at(x+1) ||
			grid.at(y).at(x + 1))) {
			points = { {x,y + 2}, {x,y+1}, {x+1, y + 1},{x + 1,y} };
			state = 2;
		}
	}
	else  {
		if (!(grid.at(y ).at(x) ||
			grid.at(y ).at(x + 1) ||
			grid.at(y + 1).at(x + 1) ||
			grid.at(y+1).at(x+2))) {
			points = { {x,y},{x + 1,y},{x + 1,y + 1},{x+2,y+1} };
			state = 1;
		}
	}
}

void SBlock::rotateCounter(std::vector<std::vector<bool>> const grid)
{
	int x = base.first;
	int y = base.second;
	if (state == 1) {
		if (!(grid.at(y + 2).at(x) ||
			grid.at(y + 1).at(x) ||
			grid.at(y + 1).at(x + 1) ||
			grid.at(y).at(x + 1))) {
			points = { {x,y + 2}, {x,y + 1}, {x + 1, y + 1},{x + 1,y} };
			state = 2;
		}
	}
	else {
		if (!(grid.at(y).at(x) ||
			grid.at(y).at(x + 1) ||
			grid.at(y + 1).at(x + 1) ||
			grid.at(y + 1).at(x + 2))) {
			points = { {x,y},{x + 1,y},{x + 1,y + 1},{x + 2,y + 1} };
			state = 1;
		}
	}
}
