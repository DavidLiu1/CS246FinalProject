#pragma once
#include "commendDeco.h"
class dropcmd :
	public commendDeco
{
public:
	dropcmd(absCommend* c);
	~dropcmd();
	Board* execute();
};

