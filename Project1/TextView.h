#pragma once
#include <iostream>
#include <string>
#include "View.h"

class TextView : public View{
	void printLevel();
	void printScore();
	void printBoards();
	void printNext();
public:
	TextView(Controller*, Model*);
	~TextView();
	virtual void update() override;

	void print();
	void readInput();
};

