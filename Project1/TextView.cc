#include "TextView.h"
#include "Model.h"
#include "Controller.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

TextView::TextView(Controller*c, Model*m) : View(c, m) {};

TextView::~TextView() {};

//helper
bool isPreixOf(std::string cmd, std::string action) {

	if (cmd.size() > action.size()) {
		return false;
	}
	for (int i = 0; i < cmd.size(); i++) {
		if (!cmd.at(i) == action.at(i)) {
			return false;
		}
	}
	return true;
}
void TextView::readInput() {
	string s;
	cin >> s;
	int index = 0;
	int mult = 0;
	bool hasNum = false;
	while (s.at(index) < '9'&&s.at(index) > '0') {
		hasNum = true;
		mult = mult * 10 + (int)(s.at(index) - '0');
		s = s.substr(1, s.size() - 1);
	}
	if (!hasNum) { mult = 1; }
	if (s.substr(0, 3) == "lef") {
		if (isPreixOf(s, "left")) {
			controller->left(mult);
		}
	}
	else if (s.substr(0, 2) == "ri") {
		if (isPreixOf(s, "right")) {
			controller->right(mult);
		}
	}
	else if (s.substr(0, 2) == "do") {
		if (isPreixOf(s, "down")) {
			controller->down(mult);
		}
	}
	else if (s.substr(0, 2) == "cl") {
		if (isPreixOf(s, "clockwise")) {
			controller->clockwise(mult);
		}
	}
	else if (s.substr(0, 2) == "co") {
		if (isPreixOf(s, "counterclockwise")) {
			controller->counterClockwise(mult);
		}
	}
	else if (s.substr(0, 2) == "dr") {
		if (isPreixOf(s, "drop")) {
			controller->drop(mult);
		}
	}
	else if (s.substr(0, 6) == "levelu") {
		if (isPreixOf(s, "levelup")) {
			controller->levelUp(mult);
		}
	}
	else if (s.substr(0, 6) == "leveld") {
		if (isPreixOf(s, "leveldown")) {
			controller->levelDown(mult);
		}
	}
	else if (s.substr(0, 1) == "n") {
		if (isPreixOf(s, "nonrandom")) {
			cin >> s;
			controller->nonrandom(s);
		}
	}
	else if (s.substr(0, 1) == "ra") {
		if (isPreixOf(s, "random")) {
			controller->random();
		}
	}
	else if (s.substr(0, 2) == "se") {
		if (isPreixOf(s, "sequence")) {
			cin >> s;
			controller->sequence(s);
		}
	}
	else if (s.substr(0, 1) == "i") {
		if (isPreixOf(s, "i")) {
			controller->test("i");
		}
	}
	else if (s.substr(0, 1) == "j") {
		if (isPreixOf(s, "j")) {
			controller->test("j");
		}
	}
	else if (s.substr(0, 1) == "l") {
		if (isPreixOf(s, "l")) {
			controller->test("l");
		}
	}
	else if (s.substr(0, 1) == "t") {
		if (isPreixOf(s, "t")) {
			controller->test("t");
		}
	}
	else if (s.substr(0, 1) == "o") {
		if (isPreixOf(s, "o")) {
			controller->test("o");
		}
	}
	else if (s.substr(0, 1) == "s") {
		if (isPreixOf(s, "s")) {
			controller->test("s");
		}
	}
	else if (s.substr(0, 1) == "z") {
		if (isPreixOf(s, "z")) {
			controller->test("z");
		}
	}
}
void TextView::print() {
	printLevel();
	printScore();
	cout << "-----------   -----------" << endl;
	printBoards();
	cout << "-----------   -----------" << endl;
	printNext();
}
//helper
void TextView::printLevel() {
	cout << "Level: " << model->getBoardOne()->getLvl();
	cout << "      ";
    cout << "Level: " << model->getBoardTwo()->getLvl() << endl;
}
void TextView::printScore() {
	cout << "Score: " << model->getBoardOne()->getScore();
	cout << "      ";
	cout << "Score: " << model->getBoardTwo()->getScore() << endl;
}
void TextView::printBoards() {
	for (int i = 0; i < 18; i++) {
		for (int j = 0; j < 25; j++) {
			if (j < 11) {
				cout << model->getBoardOne()->getColor(i, j);
			}
			else if (j < 14) {
				cout << " ";
			}
			else {
				cout << model->getBoardTwo()->getColor(i, j-14);
			}
		}
	}
}
void TextView::printNext() {
	cout << "Next:         Next:" << endl;
	cout << model->getBoardOne()->getNextType();
	cout << "    " << model->getBoardTwo()->getNextType() << endl;
}
void TextView::update() {
	Model::State state = model->state();
	if (state == Model::State::NEW_GAME) {
		print();
		controller->startGame();
	}
	else if (state == Model::State::BOARD_ONE_INPUT) {
		cout << "Player One: ";
		readInput();
		controller->switchTurn();
	}
	else if (state == Model::State::BOARD_TWO_INPUT) {
		cout << "Player Two: ";
		readInput();
		controller->switchTurn();
	}
	else if (state == Model::State::RESTART) {

	}
}