#pragma once
#include "commendDeco.h"
class moveDowncmd :
	public commendDeco
{
public:
	moveDowncmd(absCommend* c);
	~moveDowncmd();
	Board* execute();
};

