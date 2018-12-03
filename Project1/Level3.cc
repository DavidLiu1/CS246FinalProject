#include "Level3.h"



Level3::Level3()
{
}


Level3::~Level3()
{
}
Block * Level3::makeBlock()
{
	int r = rand() % 9;

	if (r == 0 ) {
		return new IBlock(true, 3);
	}
	else if (r == 1) {
		return new JBlock(true, 3);
	}
	else if (r == 2) {
		return new LBlock(true, 3);
	}
	else if (r == 3) {
		return new OBlock(true, 3);
	}
	else if (r == 4||r == 5) {
		return new SBlock(true, 3);
	}
	else if (r == 6 || r ==7) {
		return new ZBlock(true, 3);
	}
	else{
		return new TBlock(true, 3);
	}
}

int Level3::getLevel()
{
	return 3;
}