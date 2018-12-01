#include "moveLeftcmd.h"



moveLeftcmd::moveLeftcmd(absCommend* c)
	:commendDeco(c)
{
}


moveLeftcmd::~moveLeftcmd()
{
}
Board* moveLeftcmd::execute() {
	Board* b = commend->execute();
	b->moveLeft();
	return b;
}
