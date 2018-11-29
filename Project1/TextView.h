#pragma once
#include <iostream>
#include <string>
#include "View.h"

class TextView : public View{

public:
	TextView();
	~TextView();
	void printInfo();
	void printBoard();
};

