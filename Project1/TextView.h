#pragma once
#include <iostream>
#include <string>
#include "View.h"

class TextView : public View{

public:
	TextView(Controller*, Model*);
	~TextView();
	virtual void update() override;

	void printInfoOne();
	void printInfoTwo();
	void printBoardOne();
	void printBoardTwo();
	void readInput(int boardNum);
};

