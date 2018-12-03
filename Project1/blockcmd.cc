#include "blockcmd.h"



blockcmd::blockcmd(absCommend* c, std::string b)
	:commendDeco(c), block{ b }
{
}


blockcmd::~blockcmd()
{
}
Board* blockcmd::execute() {
	Board* b = commend->execute();
	b->setNext(block);
	return b;
}