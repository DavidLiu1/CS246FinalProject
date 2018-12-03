#include "OBlock.h"



OBlock::OBlock(bool h, int l)
	:Block(h,l,"Green")
{
	points = { {0,14},{1,14},{0,15},{1,15} };
}


OBlock::~OBlock()
{
}

void OBlock::rotateClock(std::vector<std::vector<bool>> const grid)
{}

void OBlock::rotateCounter(std::vector<std::vector<bool>> const grid)
{}

std::string OBlock::getText()
{
	return "O";
}
