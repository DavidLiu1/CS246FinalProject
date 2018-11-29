#include "OBlock.h"



OBlock::OBlock(bool h)
	:Block(h)
{
	points = { {0,15},{1,15},{0,16},{1,16} };
}


OBlock::~OBlock()
{
}

void OBlock::rotateClock(std::vector<std::vector<bool>> const grid)
{}

void OBlock::rotateCounter(std::vector<std::vector<bool>> const grid)
{}
