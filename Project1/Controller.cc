#include "Controller.h"
#include "Model.h"

Controller::Controller(Model* m) {
	this->model = m;
};

Controller::~Controller() {}

void Controller::startGame() {
	model->newGame();
}
void Controller::levelUp(int board) {
	if (board == 0) {
		model->getBoardOne()->levelUp();
	}
	else {
		model->getBoardTwo()->levelUp();
	}
}
void Controller::levelDown(int board) {
	if (board == 0) {
		model->getBoardOne()->levelDown();
	}
	else {
		model->getBoardTwo()->levelDown();
	}
}
void Controller::right(int board) {
	if (board == 0) {
		model->getBoardOne()->right();
	}
	else {
		model->getBoardTwo()->right();
	}
}
void Controller::left(int board) {
	if (board == 0) {
		model->getBoardOne()->left();
	}
	else {
		model->getBoardTwo()->left();
	}
}
void Controller::down(int board) {
	if (board == 0) {
		model->getBoardOne()->down();
	}
	else {
		model->getBoardTwo()->down();
	}
}
void Controller::clockwise(int board) {
	if (board == 0) {
		model->getBoardOne()->clockwise();
	}
	else {
		model->getBoardTwo()->clockwise();
	}
}
void Controller::counterClockwise(int board) {
	if (board == 0) {
		model->getBoardOne()->counterClockwise();
	}
	else {
		model->getBoardTwo()->counterClockwise();
	}
}
void Controller::drop(int board) {
	if (board == 0) {
		model->getBoardOne()->drop();
	}
	else {
		model->getBoardTwo()->drop();
	}
}
void Controller::restart(int board) {
	if (board == 0) {
		model->getBoardOne()->restart();
	}
	else {
		model->getBoardTwo()->restart();
	}
}
