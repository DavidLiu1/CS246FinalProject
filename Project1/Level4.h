#pragma once
#include "Level.h"
class Level4 :
	public Level
{
public:
	Level4();
	~Level4();
	Block* makeBlock();
	int getLevel();
};

