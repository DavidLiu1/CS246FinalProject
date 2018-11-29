#include "JBlock.h"



JBlock::JBlock(bool h)
	:Block(h)
{
	points = { {0,15},{1,15},{2,15},{0,16} };
}


JBlock::~JBlock()
{
}

void JBlock::rotateClock(std::vector<std::vector<bool>> const grid)
{
	int x = base.first;
	int y = base.second;
	if (state == 1) {
		if (!(grid.at(y + 1).at(x) ||
			grid.at(y).at(x) ||
			grid.at(y + 2).at(x ) ||
			grid.at(y + 2).at(x + 1))) {
			points = { {x,y + 1}, {x,y}, {x, y + 2},{x + 1,y + 2} };
			state = 2;
		}
	}
	else if (state == 2) {
		if (!(grid.at(y+1).at(x) ||
			grid.at(y+1).at(x + 1) ||
			grid.at(y + 1).at(x + 2) ||
			grid.at(y).at(x + 2))) {
			points = { {x,y+1},{x + 1,y+1},{x + 2,y + 1},{x + 2,y} };
			state = 3;
		}
	}
	else if (state == 3) {
		if (!(grid.at(y).at(x) ||
			grid.at(y ).at(x+1) ||
			grid.at(y+1).at(x + 1) ||
			grid.at(y + 2).at(x+1))) {
			points = { {x,y},{x+1,y},{x + 1,y + 1},{x+1 ,y + 2} };
			state = 4;
		}
	}
	else {
		if (!(grid.at(y + 1).at(x) ||
			grid.at(y).at(x) ||
			grid.at(y).at(x + 1) ||
			grid.at(y).at(x + 2))) {
			points = { {x,y + 1},{x,y},{x + 1,y},{x + 2,y} };
			state = 1;
		}
	}
}

void JBlock::rotateCounter(std::vector<std::vector<bool>> const grid)
{
	int x = base.first;
	int y = base.second;
	if (state == 3) {
		if (!(grid.at(y + 1).at(x) ||
			grid.at(y).at(x) ||
			grid.at(y + 2).at(x) ||
			grid.at(y + 2).at(x + 1))) {
			points = { {x,y + 1}, {x,y}, {x, y + 2},{x + 1,y + 2} };
			state = 2;
		}
	}
	else if (state == 4) {
		if (!(grid.at(y + 1).at(x) ||
			grid.at(y + 1).at(x + 1) ||
			grid.at(y + 1).at(x + 2) ||
			grid.at(y).at(x + 2))) {
			points = { {x,y + 1},{x + 1,y + 1},{x + 2,y + 1},{x + 2,y} };
			state = 3;
		}
	}
	else if (state == 1) {
		if (!(grid.at(y).at(x) ||
			grid.at(y).at(x + 1) ||
			grid.at(y + 1).at(x + 1) ||
			grid.at(y + 2).at(x + 1))) {
			points = { {x,y},{x + 1,y},{x + 1,y + 1},{x + 1 ,y + 2} };
			state = 4;
		}
	}
	else {
		if (!(grid.at(y + 1).at(x) ||
			grid.at(y).at(x) ||
			grid.at(y).at(x + 1) ||
			grid.at(y).at(x + 2))) {
			points = { {x,y + 1},{x,y},{x + 1,y},{x + 2,y} };
			state = 1;
		}
	}
}
