#pragma once
#include <utility>
#include <vector>
class Block
{
protected:
	int state;
	bool heavy;
	std::pair<int, int> base;
	std::vector <std::pair<int, int>> points;
public:
	Block(bool h);
	virtual ~Block();
	void moveLeft(std::vector <std::vector<bool>> grid);
	void moveRight(std::vector <std::vector<bool>> grid);
	void moveDown(std::vector <std::vector<bool>> grid);
	void drop(std::vector <std::vector<bool>> grid);
	virtual void rotateClock(std::vector <std::vector<bool>> grid) = 0;
	virtual void rotateCounter(std::vector <std::vector<bool>> grid) = 0;
	std::vector <std::pair<int, int>> getPointes();
	bool isHeavy();

};

