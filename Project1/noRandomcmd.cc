#include "noRandomcmd.h"



noRandomcmd::noRandomcmd(absCommend* c)
	:commendDeco(c)
{
}


noRandomcmd::~noRandomcmd()
{
}
Board* noRandomcmd::execute() {
	Board* b = commend->execute();
	b->setLevel(0);
	return b;
}