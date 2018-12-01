#include "Model.h"


Model::Model() : boardOne{ new Board() }, boardTwo{ new Board() }{};
Model::~Model() {
	delete boardOne;
	delete boardTwo;
}
Board* Model::getBoardOne() {
	return boardOne;
}
Board* Model::getBoardTwo() {
	return boardTwo;
}