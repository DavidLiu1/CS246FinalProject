#include "Level1.h"

Level1::Level1()
	
{
}


Level1::~Level1()
{
}

Block * Level1::makeBlock()
{
	int r = rand() % 12;
	
	if (r ==0||r ==1) {
		return new IBlock(false, 1);
	}
	else if (r == 2 || r == 3) {
		return new JBlock(false, 1);
	}
	else if (r == 4 || r == 5) {
		return new LBlock(false, 1);
	}
	else if (r == 6 || r == 7) {
		return new OBlock(false, 1);
	}
	else if (r == 8) {
		return new SBlock(false, 1);
	}
	else if (r == 9) {
		return new ZBlock(false, 1);
	}
	else{
		return new TBlock(false, 1);
	}
}

int Level1::getLevel()
{
	return 1;
}
