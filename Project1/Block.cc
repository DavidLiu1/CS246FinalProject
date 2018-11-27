#include "Block.h"

int Block::getX() {
	return coord.first;
}
int Block::getY() {
	return coord.second;
}
bool Block::ifCleared() {
	return isCleared;
}