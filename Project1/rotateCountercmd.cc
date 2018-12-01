#include "rotateCountercmd.h"



rotateCountercmd::rotateCountercmd(absCommend* c)
	:commendDeco(c)
{
}


rotateCountercmd::~rotateCountercmd()
{
}
Board* rotateCountercmd::execute() {
	Board* b = commend->execute();
	b->rotateCounter();
	return b;
}
