#include "TextView.h"
#include "Model.h"
#include <iostream>
#include <vector>

using namespace std;

TextView::TextView(Controller*c, Model*m) : View(c, m) {};

TextView::~TextView() {};
void TextView::update() {
	//print both boards;
}
void TextView::printBoardOne() {
	for (int i = 0; i < 15; i++) {
		for (int j = 0; j < 11; j++) {
			cout << model_->getBoardOne()->getColor(i, j);
		}
		cout << endl;
	}
}
void TextView::printBoardTwo() {
	for (int i = 0; i < 15; i++) {
		for (int j = 0; j < 11; j++) {
			cout << model_->getBoardTwo()->getColor(i, j);
		}
		cout << endl;
	}
}
void TextView::printInfoOne() {
	cout << model_->getBoardOne()->getLvl << endl;
}
void TextView::printInfoTwo() {
	cout << model_->getBoardTwo()->getLvl << endl;
}