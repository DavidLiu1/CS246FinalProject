#include "emptyCommend.h"



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
