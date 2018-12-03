#include "Controller.h"
#include "Model.h"

Controller::Controller(Model* m) {
	this->model = m;
};

Controller::~Controller() {}

void Controller::startGame() {
	model->newGame();
}
void Controller::levelUp(int mult) {
	model->levelUp(mult);
}
void Controller::levelDown(int mult) {
	model->levelDown(mult);
}
void Controller::right(int mult) {
	model->right(mult);
}
void Controller::left(int mult) {
	model->left(mult);
}
void Controller::down(int mult) {
	model->down(mult);
}
void Controller::clockwise(int mult) {
	model->clockwise(mult);
}
void Controller::counterClockwise(int mult) {
	model->counterClockwise(mult);
}
void Controller::drop(int mult) {
	model->drop(mult);
}
void Controller::restart() {

}
void Controller::switchTurn() {
	model->switchTurn();
}
