#include "randomcmd.h"



randomcmd::randomcmd(absCommend* c)
	:commendDeco(c)
{
}


randomcmd::~randomcmd()
{
}
Board* randomcmd::execute() {
	Board* b = commend->execute();
	b->setLevel(3);
	return b;
}