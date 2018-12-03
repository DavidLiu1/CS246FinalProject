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
Model::Turn Model::turn() const {
	return turn_;
}
void Model::newGame() {
	state_ = State::NEW_GAME;
	notify();
}
void Model::levelUp(int num) {
	if (turn_ == Model::Turn::PLAYER_ONE) {
		getBoardOne()->levelUp();
	}
	else {
		getBoardTwo()->levelUp();
	}
	state_ = State::LVL_CHANGE;
	notify();
}
void Model::levelDown(int num) {
	if (turn_ == Model::Turn::PLAYER_ONE) {
		getBoardOne()->levelDown();
	}
	else {
		getBoardTwo()->levelDown();
	}
	state_ = State::LVL_CHANGE;
	notify();
}
void Model::right(int num) {
	if (turn_ == Model::Turn::PLAYER_ONE) {
		getBoardOne()->moveRight();
	}
	else {
		getBoardTwo()->moveRight();
	}
	state_ = State::CURR_BLOCK;
	notify();
}
void Model::left(int num) {
	if (turn_ == Model::Turn::PLAYER_ONE) {
		getBoardOne()->moveLeft();
	}
	else {
		getBoardTwo()->moveLeft();
	}
	state_ = State::CURR_BLOCK;
	notify();
}
void Model::down(int num) {
	if (turn_ == Model::Turn::PLAYER_ONE) {
		if (getBoardOne()->moveDown()) {
			getBoardOne()->drop();
		}
	}
	else {
		if (getBoardTwo()->moveDown()) {
			getBoardTwo()->drop();
		}
	}
	state_ = State::CURR_BLOCK;
	notify();
}
void Model::clockwise(int num) {
	if (turn_ == Model::Turn::PLAYER_ONE) {
		getBoardOne()->rotateClock();
	}
	else {
		getBoardTwo()->rotateClock();
	}
	state_ = State::CURR_BLOCK;
	notify();
}
void Model::counterClockwise(int num) {
	if (turn_ == Model::Turn::PLAYER_ONE) {
		getBoardOne()->rotateCounter();
	}
	else {
		getBoardTwo()->rotateCounter();
	}
	state_ = State::CURR_BLOCK;
	notify();
}
void Model::drop(int num) {//	hewfu	wefhu	hweihfhuh
	if (turn_ == Model::Turn::PLAYER_ONE) {
		getBoardOne()->drop();
	}
	else {
		getBoardTwo()->drop();
	}
	state_ = State::DROP;
	notify();
}
void Model::restart() {
	if (turn_ == Model::Turn::PLAYER_ONE) {
		getBoardOne()->restart();
	}
	else {
		getBoardTwo()->restart();
	}
	state_ = State::RESTART;
	notify();
}
void Model::switchTurn() {
	if (turn_ == Model::Turn::PLAYER_ONE) {
		turn_ = Model::Turn::PLAYER_TWO;
	}
	else {
		turn_ = Model::Turn::PLAYER_ONE;
	}
}
