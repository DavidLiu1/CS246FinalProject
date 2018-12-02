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
Model::State Model::state() const {
	return state_;
}
void Model::newGame() {
	state_ = State::NEW_GAME;
	notify();
}