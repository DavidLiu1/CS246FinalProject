#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include "Block.h"
#include "IBlock.h"
#include "JBlock.h"
#include "LBlock.h"
#include "OBlock.h"
#include "SBlock.h"
#include "TBlock.h"
#include "ZBlock.h"
class Level
{
protected:
	int level;
	
public:
	Level();
	virtual ~Level();
	virtual Block* makeBlock()=0;
	virtual int getLevel() = 0;
};

