#pragma once
#include <Block.h>
class IBlock
	: public Block
{
public:
	IBlock(bool h);
	~IBlock();
	virtual void rotateClock(std::vector <std::vector<bool>> const grid);
	virtual void rotateCounter(std::vector <std::vector<bool>> const grid);
};