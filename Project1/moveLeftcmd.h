#pragma once
#include "commendDeco.h"
class moveLeftcmd :
	public commendDeco
{
public:
	moveLeftcmd(absCommend* c);
	~moveLeftcmd();
	Board* execute();
};

