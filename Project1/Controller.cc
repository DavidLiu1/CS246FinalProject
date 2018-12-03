#include "Controller.h"
#include "Model.h"
#include <string>
using namespace std;
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
	model->restart();
}
void Controller::switchTurn() {
	model->switchTurn();
}
void Controller::random() {
	model->random();
}
void Controller::nonrandom(string s) {
	model->nonrandom(s);
}
void Controller::sequence(string s) {
	model->sequence(s);
}
void Controller::test(string s) {
	model->test(s);
}
