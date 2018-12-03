#include "Level0.h"

Level0::Level0(std::string file)
	:index{ 0 }
{
	std::string str;
	seq = "";
	std::ifstream in;
	in.open(file);
	while (in >> str) {
		seq = seq + str;
	}
	in.close();
}


Level0::~Level0()
{
}

Block * Level0::makeBlock()
{
	if (index == seq.size()) {
		index = 0;
	}
	if (seq.at(index) == 'I') {
		index++;
		return new IBlock (false, 0);
	}else if (seq.at(index) == 'J') {
		index++;
		return new JBlock(false, 0);
	}
	else if (seq.at(index) == 'L') {
		index++;
		return new LBlock(false, 0);
	}
	else if (seq.at(index) == 'O') {
		index++;
		return new OBlock(false, 0);
	}
	else if (seq.at(index) == 'S') {
		index++;
		return new SBlock(false, 0);
	}
	else if (seq.at(index) == 'Z') {
		index++;
		return new ZBlock(false, 0);
	}
	else{
		index++;
		return new TBlock(false, 0);
	}
	
}

int Level0::getLevel()
{
	return 0;
}
