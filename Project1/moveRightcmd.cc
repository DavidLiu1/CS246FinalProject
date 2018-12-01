#include "moveRightcmd.h"



moveRightcmd::moveRightcmd(absCommend* c)
	:commendDeco(c)
{
}


moveRightcmd::~moveRightcmd()
{
}
Board* moveRightcmd::execute() {
	Board* b = commend->execute();
	b->moveRight();
	return b;
}
