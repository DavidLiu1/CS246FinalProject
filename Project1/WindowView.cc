#include "WindowView.h"
#include "Model.h"
#include "Controller.h"
#include "window.h"

using namespace std;
WindowView::WindowView(Controller*c, Model*m) : View(c, m) {
win = new Xwindow(675,650);
}
WindowView::~WindowView(){}

void WindowView::update() {
	Model::State state = model->state();
	if (state == Model::State::NEW_GAME) {
		printNewGame();
	}
	else if (state == Model::State::CURR_BLOCK) {
		eraseCurr();
		if (model->turn() == Model::Turn::PLAYER_ONE) {
			printCurr(0);
		}
		else {
			printCurr(1);
		}
	}
	else if (state == Model::State::DROP) {
		eraseRows();
		printBlocks();
	}
	else if (state == Model::State::LVL_CHANGE) {
		printLevel();
	}
	else if (state == Model::State::SCORE_CHANGE) {
		printScore();
	}
	else if (state == Model::State::NEXT_BLOCK) {
		eraseNext();
		if (model->turn() == Model::Turn::PLAYER_ONE) {
			drawNext(0, model->getBoardOne()->getNextType());
		}
		else {
			drawNext(1, model->getBoardTwo()->getNextType());
		}
	}
	else if (state == Model::State::RESTART) {
		restart();
	}
}

void WindowView::printNewGame() {
	win->drawString(25, 25, "Level: 0", Xwindow::Black);
	win->drawString(25, 50, "Score: 0", Xwindow::Black);
	win->drawString(375, 25, "Level: 0", Xwindow::Black);
	win->drawString(375, 50, "Score: 0", Xwindow::Black);
	win->drawLine(25, 75, 25, 475);
	win->drawLine(25, 75, 300, 75);
	win->drawLine(300, 75, 300, 475);
	win->drawLine(25, 475, 300, 475);

	win->drawLine(375, 75, 375, 475);
	win->drawLine(375, 75, 650, 75);
	win->drawLine(650, 75, 650, 475);
	win->drawLine(375, 475, 650, 475);
	drawNext(0, model->getBoardOne()->getNextType());
	drawNext(1, model->getBoardTwo()->getNextType());
}
void WindowView::drawNext(int boardNum, string type) {
	vector <pair<int, int>> coords;
	if (type == "I") {
		pair<int, int> p1(10, 25);
		coords.push_back(p1);
		pair<int, int> p2(35, 25);
		coords.push_back(p2);
		pair<int, int> p3(60, 25);
		coords.push_back(p3);
		pair<int, int> p4(85, 25);
		coords.push_back(p4);
	}
	else if (type == "J") {
		pair<int, int> p1(10, 12);
		coords.push_back(p1);
		pair<int, int> p2(10, 37);
		coords.push_back(p2);
		pair<int, int> p3(35, 37);
		coords.push_back(p3);
		pair<int, int> p4(60, 37);
		coords.push_back(p4);
	}
	else if (type == "L") {
		pair<int, int> p1(60, 12);
		coords.push_back(p1);
		pair<int, int> p2(10, 37);
		coords.push_back(p2);
		pair<int, int> p3(35, 37);
		coords.push_back(p3);
		pair<int, int> p4(60, 37);
		coords.push_back(p4);
	}
	else if (type == "O") {
		pair<int, int> p1(10, 12);
		coords.push_back(p1);
		pair<int, int> p2(35, 12);
		coords.push_back(p2);
		pair<int, int> p3(10, 37);
		coords.push_back(p3);
		pair<int, int> p4(35, 37);
		coords.push_back(p4);
	}
	else if (type == "Z") {
		pair<int, int> p1(10, 12);
		coords.push_back(p1);
		pair<int, int> p2(35, 12);
		coords.push_back(p2);
		pair<int, int> p3(35, 37);
		coords.push_back(p3);
		pair<int, int> p4(60, 37);
		coords.push_back(p4);
	}
	else if (type == "S") {
		pair<int, int> p1(35, 12);
		coords.push_back(p1);
		pair<int, int> p2(60, 12);
		coords.push_back(p2);
		pair<int, int> p3(10, 37);
		coords.push_back(p3);
		pair<int, int> p4(35, 37);
		coords.push_back(p4);
	}
	else { //t
		pair<int, int> p1(10, 12);
		coords.push_back(p1);
		pair<int, int> p2(35, 12);
		coords.push_back(p2);
		pair<int, int> p3(60, 12);
		coords.push_back(p3);
		pair<int, int> p4(35, 37);
		coords.push_back(p4);
	}
	for (int i = 0; i < coords.size(); i++) {
		if (boardNum == 0) {
			win->fillRectangle(coords.at(i).first, coords.at(i).second+475, 25,25, getColor(model->getBoardOne()->getNextColor()));
		} else {
			win->fillRectangle(coords.at(i).first+ 375, coords.at(i).second + 475, 25, 25,getColor(model->getBoardOne()->getNextColor()));
		}
	}
}
void WindowView::printLevel() {
	if (model->turn() == Model::Turn::PLAYER_ONE) {
		win->fillRectangle(25, 25, 100, 25, win->White);
		string s = "Level: " + to_string(model->getBoardOne()->getLvl());
		win->drawString(25, 25, s, Xwindow::Black);
	}
	else {
		win->fillRectangle(375, 25, 100, 25, win->White);
		string s = "Level: " + to_string(model->getBoardTwo()->getLvl());
		win->drawString(375, 25, s, Xwindow::Black);
	}
}
void WindowView::printScore() {
	if (model->turn() == Model::Turn::PLAYER_ONE) {
		win->fillRectangle(25, 50, 100, 25, win->White);
		string s = "Score: " + to_string(model->getBoardOne()->getScore());
		win->drawString(25, 50, s, Xwindow::Black);
	}
	else {
		win->fillRectangle(375, 50, 100, 25, win->White);
		string s = "Score: " + to_string(model->getBoardTwo()->getScore());
		win->drawString(375, 50, s, Xwindow::Black);
	}
}
void WindowView::printCurr(int board) {
	if (board == 0) {
		for (int i = 0; i < model->getBoardOne()->getCurrBlock()->getPointes().size(); i++) {
			win->fillRectangle(17 - model->getBoardOne()->getCurrBlock()->getPointes().at(i).first + 25, model->getBoardOne()->getCurrBlock()->getPointes().at(i).second+25, 25, 25, getColor(model->getBoardOne()->getCurrBlock()->getColor()));
		}
	}
	else {
		for (int i = 0; i < model->getBoardTwo()->getCurrBlock()->getPointes().size(); i++) {
			win->fillRectangle(17- model->getBoardTwo()->getCurrBlock()->getPointes().at(i).first + 25 + 375, model->getBoardTwo()->getCurrBlock()->getPointes().at(i).second + 25, 25, 25, getColor(model->getBoardOne()->getCurrBlock()->getColor()));
		}
	}
}

char WindowView::getColor(string c) {
	if (c == "red") {
		return win->Red;
	}
	else if (c == "green") {
		return win->Green;
	}
	else if (c == "blue") {
		return win->Blue;
	}
	else if (c == "cyan") {
		return win->Cyan;
	}
	else if (c == "yellow") {
		win->Yellow;
	}
	else if (c == "magenta") {
		win->Magenta;
	}
	else {
		return win->Orange;
	}
}