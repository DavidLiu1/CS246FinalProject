#include "levelUpcmd.h"



levelUpcmd::levelUpcmd(absCommend* c)
	:commendDeco(c)
{
}


levelUpcmd::~levelUpcmd()
{
}
Board* levelUpcmd::execute() {
	Board* b = commend->execute();
	b->levelUp();
	return b;
}