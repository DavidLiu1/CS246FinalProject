#include "sequencecmd.h"



sequencecmd::sequencecmd(absCommend* c, std::string file)
	:commendDeco(c), file{ file }
{
}


sequencecmd::~sequencecmd()
{
}
Board* sequencecmd::execute() {
	Board* b = commend->execute();
	b->setSeq(file);
	return b;
}