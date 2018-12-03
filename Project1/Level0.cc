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
	std::cout << seq << std::endl;
	if (index == seq.size()) {
		index = 0;
	}
	std::cout << seq<< std::endl;
	if (seq.at(index) == 'I') {
		std::cout << "2" << std::endl;
		return new IBlock (false, 0);
	}else if (seq.at(index) == 'J') {
		return new JBlock(false, 0);
	}
	else if (seq.at(index) == 'L') {
		return new LBlock(false, 0);
	}
	else if (seq.at(index) == 'O') {
		return new OBlock(false, 0);
	}
	else if (seq.at(index) == 'S') {
		return new SBlock(false, 0);
	}
	else if (seq.at(index) == 'Z') {
		return new ZBlock(false, 0);
	}
	else{
		return new TBlock(false, 0);
	}
	std::cout << "3" << std::endl;
}

int Level0::getLevel()
{
	return 0;
}
