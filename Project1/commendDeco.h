#pragma once
#include "absCommend.h"
#include "Board.h"
class commendDeco :
	public absCommend
{
protected:
	absCommend *commend;
public:
	commendDeco(absCommend *commend);
	virtual ~commendDeco();
};

