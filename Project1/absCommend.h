#pragma once
class Board;
class absCommend
{
public:
	absCommend();
	virtual ~absCommend();
	virtual Board* execute()=0;
};

