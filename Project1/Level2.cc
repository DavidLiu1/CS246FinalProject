#include "Level2.h"



Level2::Level2()
{
}


Level2::~Level2()
{
}
Block * Level2::makeBlock()
{
	int r = rand() % 14;

	if (r == 0 || r == 2) {
		return new IBlock(false, 2);
	}
	else if (r == 2 || r == 3) {
		return new JBlock(false, 2);
	}
	else if (r == 4 || r == 5) {
		return new LBlock(false, 2);
	}
	else if (r == 6 || r == 7) {
		return new OBlock(false, 2);
	}
	else if (r == 8|| r == 13) {
		return new SBlock(false, 2);
	}
	else if (r == 9 || r ==11) {
		return new ZBlock(false, 2);
	}
	else  {
		return new TBlock(false, 2);
	}
}

int Level2::getLevel()
{
	return 2;
}