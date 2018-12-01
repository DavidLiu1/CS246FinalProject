#pragma once
#include "absCommend.h"
class Board;
class emptyCommend :
	public absCommend
{
	Board* board;
public:
	emptyCommend(Board* b);
	~emptyCommend();
	Board* execute();
};

