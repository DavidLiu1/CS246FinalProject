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
//helper
bool isPreixOf(std::string cmd, std::string action) {

	if (cmd.size() > action.size()) {
		return false;
	}
	for (int i = 0; i < cmd.size; i++) {
		if (!cmd.at(i) == action.at(i)) {
			return false;
		}
	}
	return true;
}
void TextView::readInput(int boardNum) {
	string s;
	cin >> s;
	int index = 0;
	int mult = 0;
	while (s.at(index) < '9'&&s.at(index) > '0') {
		mult = mult * 10 + (int)(s.at(index) - '0');
		s = s.substr(1, s.size() - 1);
	}
	if (s.substr(0, 3) == "lef") {
		if (isPreixOf(s, "left")) {
			controller->left(boardNum);
		}
	}
	else if (s.substr(0, 2) == "ri") {
		if (isPreixOf(s, "right")) {
			controller->right(boardNum);
		}
	}
	else if (s.substr(0, 2) == "do") {
		if (isPreixOf(s, "down")) {
			controller->down(boardNum);
		}
	}
	else if (s.substr(0, 2) == "cl") {
		if (isPreixOf(s, "clockwise")) {
			controller->clockwise(boardNum);
		}
	}
	else if (s.substr(0, 2) == "co") {
		if (isPreixOf(s, "counterclockwise")) {
			controller->counterClockwise(boardNum);
		}
	}
	else if (s.substr(0, 2) == "dr") {
		if (isPreixOf(s, "drop")) {
			controller->drop(boardNum);
		}
	}
	else if (s.substr(0, 6) == "levelu") {
		if (isPreixOf(s, "levelup")) {
			controller->levelUp(boardNum);
		}
	}
	else if (s.substr(0, 6) == "leveld") {
		if (isPreixOf(s, "leveldown")) {
			controller->levelDown(boardNum);
		}
	}
	else if (s.substr(0, 1) == "n") {
		if (isPreixOf(s, "nonrandom")) {
			controller->nonrandom(boardNum);
		}
	}
	else if (s.substr(0, 1) == "ra") {
		if (isPreixOf(s, "random")) {
			controller->random(boardNum);
		}
	}
	else if (s.substr(0, 2) == "se") {
		if (isPreixOf(s, "sequence")) {
			controller->left(boardNum);
		}
	}
	else if (s.substr(0, 1) == "i") {
		if (isPreixOf(s, "i")) {
			controller->test(boardNum,'i');
		}
	}
	else if (s.substr(0, 1) == "j") {
		if (isPreixOf(s, "j")) {
			controller->test(boardNum, 'j');
		}
	}
	else if (s.substr(0, 1) == "l") {
		if (isPreixOf(s, "l")) {
			controller->test(boardNum, 'l');
		}
	}
	else if (s.substr(0, 1) == "t") {
		if (isPreixOf(s, "t")) {
			controller->test(boardNum, 't');
		}
	}
	else if (s.substr(0, 1) == "o") {
		if (isPreixOf(s, "o")) {
			controller->test(boardNum, 'o');
		}
	}
	else if (s.substr(0, 1) == "s") {
		if (isPreixOf(s, "s")) {
			controller->test(boardNum, 's');
		}
	}
	else if (s.substr(0, 1) == "z") {
		if (isPreixOf(s, "z")) {
			controller->test(boardNum, 'z');
		}
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
	else if (state == Model::State::DROP) {

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