#include "dropcmd.h"



dropcmd::dropcmd(absCommend* c)
	:commendDeco(c)
{
}


dropcmd::~dropcmd()
{
}
Board* dropcmd::execute() {
	Board* b = commend->execute();
	b->drop();
	return b;
}
