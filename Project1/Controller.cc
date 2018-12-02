#include "Controller.h"
#include "Model.h"

Controller::Controller(Model* m) {
	this->model = m;
};

Controller::~Controller() {}

void Controller::startGame() {
	model->newGame();
}