#pragma once
#include "commendDeco.h"
class blockcmd :
	public commendDeco
{
	std::string block;
public:
	blockcmd(absCommend* c, std::string string);
	~blockcmd();
	Board* execute();
};

