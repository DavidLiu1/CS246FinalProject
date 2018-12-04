#pragma once
#include "Block.h"
class JBlock
	: public Block
{
public:
	JBlock(bool h, int l);
	~JBlock();
	virtual void rotateClock(std::vector <std::vector<bool>> const grid);
	virtual void rotateCounter(std::vector <std::vector<bool>> const grid);
	std::string getText();
};

