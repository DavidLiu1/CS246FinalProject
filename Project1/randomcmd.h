#pragma once
#include "commendDeco.h"
class randomcmd :
	public commendDeco
{
public:
	randomcmd(absCommend* c);
	~randomcmd();
	Board* execute();
};

