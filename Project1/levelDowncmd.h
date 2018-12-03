#pragma once
#include "commendDeco.h"
class levelDowncmd :
	public commendDeco
{
public:
	levelDowncmd(absCommend* c);
	~levelDowncmd();
	Board* execute();
};

