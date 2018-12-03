#include "TextView.h"
#include "Model.h"
#include "Controller.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

TextView::TextView(Controller*c, Model*m) : View(c, m) {};

TextView::~TextView() {};
void TextView::update() {
	//print both boards;
}
void TextView::printBoardOne() {
	for (int i = 0; i < 15; i++) {
		for (int j = 0; j < 11; j++) {
			cout << model->getBoardOne()->getColor(i, j);
		}
		cout << endl;
	}
}
void TextView::printBoardTwo() {
	for (int i = 0; i < 15; i++) {
		for (int j = 0; j < 11; j++) {
			cout << model->getBoardTwo()->getColor(i, j);
		}
		cout << endl;
	}
}
void TextView::printInfoOne() {
	cout << model->getBoardOne()->getLvl << endl;
}
void TextView::printInfoTwo() {
	cout << model->getBoardTwo()->getLvl << endl;
}
void TextView::readInput(int boardNum) {
	string s;
	cin >> s; 
	if (s == "left") {
		controller->left(boardNum);
	}
	else if (s == "right") {
		controller->right(boardNum);
	}
	else if (s == "down") {
		controller->down(boardNum);
	}
	else if (s == "clockwise") {
		controller->clockwise(boardNum);
	}
	else if (s == "counterclockwise") {
		controller->counterClockwise(boardNum);
	}
	else if (s == "drop") {
		controller->drop(boardNum);
	}
	else if (s == "levelup") {
		controller->levelup(boardNum);
	}
	else if (s == "leveldown") {
		controller->leveldown(boardNum);
	}
	else if (s == "norandom") {
		controller->left(boardNum);
	}
	else if (s == "random") {
		controller->left(boardNum);
	}
	else if (s == "sequence") {
		controller->left(boardNum);
	}
	else if (s == "restart") {
		controller->restart(boardNum);
	}
}
void TextView::update() {
	Model::State state = model->state();
	if (state == Model::State::NEW_GAME) {
		//print boards
		controller->startGame();
	}
	else if (state == Model::State::BOARD_ONE_INPUT) {
		cout << "Player One: ";
		readInput(0);
	}
	else if (state == Model::State::BOARD_TWO_INPUT) {
		cout << "Player Two: ";
		readInput(1);
	}
	else if (state == Model::State::CURR_BLOCK) {

	}
	else if (state == Model::State::CLEAR_ROW) {

	}
	else if (state == Model::State::LVL_UP) {

	}
	else if (state == Model::State::SCORE_CHANGE) {

	}
	else if (state == Model::State::NEXT_BLOCK) {

	}
	else if (state == Model::State::RESTART) {

	}


}