#pragma once
#include <Block.h>
class TBlock
	: public Block
{
public:
	TBlock(bool h, int l);
	~TBlock();
	virtual void rotateClock(std::vector <std::vector<bool>> const grid);
	virtual void rotateCounter(std::vector <std::vector<bool>> const grid);
};

