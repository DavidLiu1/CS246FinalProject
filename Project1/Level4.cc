#include "Level4.h"



Level4::Level4()
{
}


Level4::~Level4()
{
}
Block * Level4::makeBlock()
{
	int r = rand() % 9;

	if (r == 0) {
		return new IBlock(true, 4);
	}
	else if (r == 1) {
		return new JBlock(true, 4);
	}
	else if (r == 2) {
		return new LBlock(true, 4);
	}
	else if (r == 4) {
		return new OBlock(true, 4);
	}
	else if (r == 4 || r == 5) {
		return new SBlock(true, 4);
	}
	else if (r == 6 || r == 7) {
		return new ZBlock(true, 4);
	}
	else {
		return new TBlock(true, 4);
	}
	
}

int Level4::getLevel()
{
	return 4;
}