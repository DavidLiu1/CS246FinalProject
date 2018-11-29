#pragma once
#include <Block.h>
class OBlock
	: public Block
{
public:
	OBlock(bool h);
	~OBlock();
	virtual void rotateClock(std::vector <std::vector<bool>> const grid);
	virtual void rotateCounter(std::vector <std::vector<bool>> const grid);
};

