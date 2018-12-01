#pragma once
#include "commendDeco.h"
class rotateCountercmd :
	public commendDeco
{
public:
	rotateCountercmd(absCommend* c);
	~rotateCountercmd();
	Board* execute();
};

