#pragma once
#include <utility>
#include <vector>
#include <string>
class Block
{
protected:
	int level;
	int state;
	bool heavy;
	std::pair<int, int> base;
	std::vector <std::pair<int, int>> points;
	std::string color;

public:
	Block(bool h, int l, std::string c);
	//return true if after remove theres no points left
	bool removeRow(int i);
	virtual ~Block();
	int getLevel();
	void moveLeft(std::vector <std::vector<bool>> const grid);
	void moveRight(std::vector <std::vector<bool>> const grid);
	bool moveDown(std::vector <std::vector<bool>> const grid);
	
	void drop(std::vector <std::vector<bool>> const grid);
	virtual void rotateClock(std::vector <std::vector<bool>> const grid) = 0;
	virtual void rotateCounter(std::vector <std::vector<bool>> const grid) = 0;
	std::vector <std::pair<int, int>> getPointes();
	bool isHeavy();
	std::string getColor();
	virtual std::string getText() = 0;
};

