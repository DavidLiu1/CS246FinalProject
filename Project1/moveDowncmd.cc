#include "moveDowncmd.h"



moveDowncmd::moveDowncmd(absCommend* c)
	:commendDeco(c)
{
}


moveDowncmd::~moveDowncmd()
{
}
Board* moveDowncmd::execute() {
	Board* b = commend->execute();
	b->moveDown();
	return b;
}
