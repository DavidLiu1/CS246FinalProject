#pragma once
#include "Level.h"
class Level0 :
	public Level
{
	std::string seq;
	int index;
public:
	Level0(std::string file);
	~Level0();
	Block* makeBlock();
	int getLevel();
};

