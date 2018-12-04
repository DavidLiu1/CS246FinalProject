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
		controller->playerOneInput();
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
		saveCurr();
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
		printNewGame();
	}
}

void WindowView::printNewGame() {
	win->drawString(25, 25, "Level: 0", Xwindow::Black);
	win->drawString(25, 50, "Score: 0", Xwindow::Black);
	win->drawString(375, 25, "Level: 0", Xwindow::Black);
	win->drawString(375, 50, "Score: 0", Xwindow::Black);
	win->fillRectangle(25, 75, 625, 400, win->White);
	win->drawLine(25, 75, 25, 525);
	win->drawLine(25, 75, 300, 75);
	win->drawLine(300, 75, 300, 525);
	win->drawLine(25, 525, 300, 525);
	win->drawLine(375, 75, 375, 525);
	win->drawLine(375, 75, 650, 75);
	win->drawLine(650, 75, 650, 525);
	win->drawLine(375, 525, 650, 525);
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
			win->fillRectangle(coords.at(i).first, coords.at(i).second+525, 25,25, getColor(model->getBoardOne()->getNextColor()));
		} else {
			win->fillRectangle(coords.at(i).first+ 375, coords.at(i).second + 525, 25, 25,getColor(model->getBoardOne()->getNextColor()));
		}
	}
}
void WindowView::eraseNext() {
	if (model->turn() == Model::Turn::PLAYER_ONE) {
			win->fillRectangle(10, 525, 125, 75, win->White);
	}
	else {
			win->fillRectangle(375, 525, 125, 75, win->White);
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
void WindowView::eraseCurr() {
	if (model->turn() == Model::Turn::PLAYER_ONE) {
		for (int i = 0; i < oldCurrPointsOne.size(); i++) {
			win->fillRectangle(17 - oldCurrPointsOne.at(i).first * 25 + 25, oldCurrPointsOne.at(i).second * 25 + 25, 25,25, win->White);
		}
	}
	else {
		for (int i = 0; i < oldCurrPointsTwo.size(); i++) {
			win->fillRectangle(17 - oldCurrPointsTwo.at(i).first * 25 + 25 + 350, oldCurrPointsOne.at(i).second * 25 + 25, 25, 25, win->White);
		}
	}
}

char WindowView::getColor(string c) {
	if (c == "Red") {
		return win->Red;
	}
	else if (c == "Green") {
		return win->Green;
	}
	else if (c == "Blue") {
		return win->Blue;
	}
	else if (c == "Cyan") {
		return win->Cyan;
	}
	else if (c == "Yellow") {
		win->Yellow;
	}
	else if (c == "Magenta") {
		win->Magenta;
	}
	else if (c == "White") {
		win->White;
	}
	else {
		return win->Orange;
	}
}

void WindowView::saveCurr() {
	if (model->turn() == Model::Turn::PLAYER_ONE) {
		oldCurrPointsOne.clear();
		for (int i = 0; i < model->getBoardOne()->getCurrBlock()->getPointes().size(); i++) {
			oldCurrPointsOne.push_back(model->getBoardOne()->getCurrBlock()->getPointes().at(i));
		}
	}
	else {
		oldCurrPointsTwo.clear();
		for (int i = 0; i < model->getBoardTwo()->getCurrBlock()->getPointes().size(); i++) {
			oldCurrPointsTwo.push_back(model->getBoardTwo()->getCurrBlock()->getPointes().at(i));
		}
	}
}

void WindowView::printBlocks() {
	if (model->turn() == Model::Turn::PLAYER_ONE) {
		for (int i = 0; i < 18; i++) {
			for (int j = 0; j < 11; j++) {
				win->fillRectangle(25 + j * 25, 75 + i * 25, 25, 25, getColor(model->getBoardOne()->getColor(j, 17 - i)));
			}
		}
	}
	else {
		for (int i = 0; i < 18; i++) {
			for (int j = 0; j < 11; j++) {
				win->fillRectangle(25 + j * 25+350, 75 + i * 25, 25, 25, getColor(model->getBoardTwo()->getColor(j, 17 - i)));
			}
		}
	}
}