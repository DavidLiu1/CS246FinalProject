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
	void moveLeft(std::vector <std::vector<bool>> const grid);
	void moveRight(std::vector <std::vector<bool>> const grid);
	bool moveDown(std::vector <std::vector<bool>> const grid);
	bool filled(std::vector <std::vector<bool>> const grid);
	void drop(std::vector <std::vector<bool>> const grid);
	virtual void rotateClock(std::vector <std::vector<bool>> const grid) = 0;
	virtual void rotateCounter(std::vector <std::vector<bool>> const grid) = 0;
	std::vector <std::pair<int, int>> getPointes();
	bool isHeavy();
	virtual char getColor(); //david add this
};

