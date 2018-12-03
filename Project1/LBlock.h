#pragma once
#include <Block.h>
class LBlock
	: public Block
{
public:
	LBlock(bool h, int l);
	~LBlock();
	virtual void rotateClock(std::vector <std::vector<bool>> const grid);
	virtual void rotateCounter(std::vector <std::vector<bool>> const grid);
	std::string getText();
};

