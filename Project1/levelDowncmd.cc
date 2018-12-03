#include "levelDowncmd.h"



levelDowncmd::levelDowncmd(absCommend* c)
	:commendDeco(c)
{
}


levelDowncmd::~levelDowncmd()
{
}
Board* levelDowncmd::execute() {
	Board* b = commend->execute();
	b->levelDown();
	return b;
}