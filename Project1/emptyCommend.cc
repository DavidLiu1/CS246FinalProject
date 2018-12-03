#include "emptyCommend.h"
#include "Board.h"


emptyCommend::emptyCommend(Board* b)
	:board{ b }
{
}


emptyCommend::~emptyCommend()
{
}
Board* emptyCommend::execute() {

	return board;
}
