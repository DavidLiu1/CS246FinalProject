#pragma once
#include <Block.h>
class SBlock
	: public Block
{
public:
	SBlock(bool h);
	~SBlock();
	virtual void rotateClock(std::vector <std::vector<bool>> const grid);
	virtual void rotateCounter(std::vector <std::vector<bool>> const grid);
};

