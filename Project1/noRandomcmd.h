#pragma once
#include "commendDeco.h"
class noRandomcmd :
	public commendDeco
{
public:
	noRandomcmd(absCommend* c);
	~noRandomcmd();
	Board* execute();
};

