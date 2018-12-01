#pragma once
#include "commendDeco.h"
class rotateClockcmd :
	public commendDeco
{
public:
	rotateClockcmd(absCommend* c);
	~rotateClockcmd();
	Board* execute();
};

