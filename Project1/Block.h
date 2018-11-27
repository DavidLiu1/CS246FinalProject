#include <utility>
#include <vector>
#include <cstdlib>


class Block{
	std::pair<int, int> coord;
	bool isCleared;

public:
	Block();
	int getX();
	int getY();
	bool ifCleared();
};