#include "WindowView.h"
#include "Model.h"
#include "Controller.h"

WindowView::WindowView(Controller*c, Model*m) : View(c, m) {
	win = new Xwindow(625,650);
}
WindowView::~WindowView(){}

void WindowView::update() {
	Model::State state = model->state();
	if (state == Model::State::NEW_GAME) {
		//print boards
		controller->startGame();
	}
	else if (state == Model::State::CURR_BLOCK) {
		eraseCurr();
		printCurr();
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
		eraseCurr();
		printCurr();
		printNext();
	}
	else if (state == Model::State::RESTART) {
		restart();
	}

}
