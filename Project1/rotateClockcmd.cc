#include "rotateClockcmd.h"



rotateClockcmd::rotateClockcmd(absCommend* c)
	:commendDeco(c)
{
}


rotateClockcmd::~rotateClockcmd()
{
}
Board* rotateClockcmd::execute() {
	Board* b = commend->execute();
	b->rotateClock();
	return b;
}
