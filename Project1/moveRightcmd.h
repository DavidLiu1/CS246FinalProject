#pragma once
#include "commendDeco.h"
class moveRightcmd :
	public commendDeco
{
public:
	moveRightcmd(absCommend* c);
	~moveRightcmd();
	Board* execute();
};

