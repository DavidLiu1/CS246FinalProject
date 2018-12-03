#pragma once
#include "commendDeco.h"
class sequencecmd :
	public commendDeco
{
	std::string file;
public:
	sequencecmd(absCommend* c,std::string file);
	~sequencecmd();
	Board* execute();
};

