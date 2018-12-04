#include <string>
#include "Model.h"
#include "emptyCommend.h"
#include "levelDowncmd.h"
#include "levelupcmd.h"
#include "blockcmd.h"
#include "dropcmd.h"
#include "moveDowncmd.h"
#include "moveLeftcmd.h"
#include "moveRightcmd.h"
#include "noRandomcmd.h"
#include "randomcmd.h"
#include "rotateClockcmd.h"
#include "rotateCountercmd.h"
#include "sequencecmd.h"

using namespace std;
Model::Model(string s1, string s2) : boardOne{ new Board(s1) }, boardTwo{ new Board(s2) }, h1{ 0 }, h2{ 0 } {};
Model::~Model() {
	delete boardOne;
	delete boardTwo;
}
Board* Model::getBoardOne() {
	return boardOne;
}
Board* Model::getBoardTwo() {
	return boardTwo;
}
Model::State Model::state() const {
	return state_;
}
Model::Turn Model::turn() const {
	return turn_;
}
void Model::newGame() {
	state_ = State::NEW_GAME;
	//std::cout << "sad" << std::endl;
	notify();
}
void Model::playerOneInput() {
	state_ = State::BOARD_ONE_INPUT;
	notify();
}
void Model::levelUp(int num) {
	if (turn_ == Model::Turn::PLAYER_ONE) {
		absCommend * c = new emptyCommend(boardOne);
		for (int i = 0; i < num; i++) {
			c = new levelUpcmd(c);
		}
		c->execute();
	}
	else {
		absCommend * c = new emptyCommend(boardTwo);
		for (int i = 0; i < num; i++) {
			c = new levelUpcmd(c);
		}
		c->execute();
	}
	state_ = State::LVL_CHANGE;
	notify();
}
void Model::levelDown(int num) {
	if (turn_ == Model::Turn::PLAYER_ONE) {
		absCommend * c = new emptyCommend(boardOne);
		for (int i = 0; i < num; i++) {
			c = new levelDowncmd(c);
		}
		c->execute();
	}
	else {
		absCommend * c = new emptyCommend(boardTwo);
		for (int i = 0; i < num; i++) {
			c = new levelDowncmd(c);
		}
		c->execute();
	}
	state_ = State::LVL_CHANGE;
	notify();
}
void Model::right(int num) {
	//cout << boardOne->isHeavy() << endl;
	if (turn_ == Model::Turn::PLAYER_ONE) {
		absCommend * c = new emptyCommend(boardOne);
		for (int i = 0; i < num; i++) {
			c = new moveRightcmd(c);
		}
		c->execute();
	}
	else {
		absCommend * c = new emptyCommend(boardTwo);
		for (int i = 0; i < num; i++) {
			c = new moveRightcmd(c);
		}
		c->execute();
	}
	state_ = State::CURR_BLOCK;

	//cout << boardOne->isHeavy() << endl;
	if (boardOne->isHeavy()) {
		if (boardOne->moveDown()) {
			boardOne->drop();
			state_ = State::DROP;
		}
	}
	notify();
}
void Model::left(int num) {
	if (turn_ == Model::Turn::PLAYER_ONE) {
		absCommend * c = new emptyCommend(boardOne);
		for (int i = 0; i < num; i++) {
			c = new moveLeftcmd(c);
		}
		c->execute();
	}
	else {
		absCommend * c = new emptyCommend(boardTwo);
		for (int i = 0; i < num; i++) {
			c = new moveLeftcmd(c);
		}
		c->execute();
	}
	state_ = State::CURR_BLOCK;
	if (boardOne->isHeavy()) {
		if (boardOne->moveDown()) {
			boardOne->drop();
			state_ = State::DROP;
		}
	}
	notify();
}
void Model::down(int num) {
	if (turn_ == Model::Turn::PLAYER_ONE) {
		absCommend * c = new emptyCommend(boardOne);
		for (int i = 0; i < num; i++) {
			c = new moveDowncmd(c);
		}
		c->execute();
	}
	else {
		absCommend * c = new emptyCommend(boardTwo);
		for (int i = 0; i < num; i++) {
			c = new moveDowncmd(c);
		}
		c->execute();
	}
	state_ = State::CURR_BLOCK;
	if (boardOne->isHeavy()) {
		if (boardOne->moveDown()) {
			boardOne->drop();
			state_ = State::DROP;
		}
	}
	notify();
}
void Model::clockwise(int num) {
	if (turn_ == Model::Turn::PLAYER_ONE) {
		absCommend * c = new emptyCommend(boardOne);
		for (int i = 0; i < num; i++) {
			c = new rotateClockcmd(c);
		}
		c->execute();
	}
	else {
		absCommend * c = new emptyCommend(boardTwo);
		for (int i = 0; i < num; i++) {
			c = new rotateClockcmd(c);
		}
		c->execute();
	}
	state_ = State::CURR_BLOCK;
	if (boardOne->isHeavy()) {
		if (boardOne->moveDown()) {
			boardOne->drop();
			state_ = State::DROP;
		}
	}
	notify();
}
void Model::counterClockwise(int num) {
	if (turn_ == Model::Turn::PLAYER_ONE) {
		absCommend * c = new emptyCommend(boardOne);
		for (int i = 0; i < num; i++) {
			c = new rotateCountercmd(c);
		}
		c->execute();
	}
	else {
		absCommend * c = new emptyCommend(boardTwo);
		for (int i = 0; i < num; i++) {
			c = new rotateCountercmd(c);
		}
		c->execute();
	}
	state_ = State::CURR_BLOCK;
	if (boardOne->isHeavy()) {
		if (boardOne->moveDown()) {
			boardOne->drop();
			state_ = State::DROP;
		}
	}
	notify();
}
void Model::drop(int num) {
	if (turn_ == Model::Turn::PLAYER_ONE) {
		absCommend * c = new emptyCommend(boardOne);
		for (int i = 0; i < num; i++) {
			c = new dropcmd(c);
		}
		c->execute();
	}
	else {
		absCommend * c = new emptyCommend(boardTwo);
		for (int i = 0; i < num; i++) {
			c = new dropcmd(c);
		}
		c->execute();
	}
	
	if (boardOne->lost() || boardTwo->lost()) {
		if (h1 < (boardOne->getScore())) {
			h1 = boardOne->getScore();
		}
		if (h2 < (boardTwo->getScore())) {
			h2 = boardTwo->getScore();
		}
		restart();
	}
	else {
		state_ = State::DROP;
		notify();
		state_ = State::NEXT_BLOCK;
		notify();
	}
}
void Model::restart() {
	delete boardOne;
	boardOne = new Board("Sequence1.txt");
	delete boardTwo;
	boardTwo = new Board("Sequence2.txt");
	state_ = State::RESTART;
	notify();
}
void Model::switchTurn() {
	if (turn_ == Model::Turn::PLAYER_ONE) {
		turn_ = Model::Turn::PLAYER_TWO;
		state_ = State::BOARD_TWO_INPUT;
	}
	else {
		turn_ = Model::Turn::PLAYER_ONE;
		state_ = State::BOARD_ONE_INPUT;
	}
	notify();
}
void Model::random() {
	if (turn_ == Model::Turn::PLAYER_ONE) {
		absCommend * c = new emptyCommend(boardOne);
	    c = new randomcmd(c);
		c->execute();
	}
	else {
		absCommend * c = new emptyCommend(boardTwo);
		c = new randomcmd(c);
		c->execute();
	}
}
void Model::nonrandom(string s) {
	if (turn_ == Model::Turn::PLAYER_ONE) {
		absCommend * c = new emptyCommend(boardOne);
		c = new sequencecmd(c,s);
		c->execute();
	}
	else {
		absCommend * c = new emptyCommend(boardTwo);
		c = new sequencecmd(c, s);
		c->execute();
	}
}
void Model::sequence(string s) {
	if (turn_ == Model::Turn::PLAYER_ONE) {
		absCommend * c = new emptyCommend(boardOne);
		c = new sequencecmd(c, s);
		c->execute();
	}
	else {
		absCommend * c = new emptyCommend(boardTwo);
		c = new sequencecmd(c, s);
		c->execute();
	}
}
void Model::test(string s) {
	if (turn_ == Model::Turn::PLAYER_ONE) {
		absCommend * c = new emptyCommend(boardOne);
		c = new blockcmd(c,s);
		c->execute();
	}
	else {
		absCommend * c = new emptyCommend(boardTwo);
		c = new blockcmd(c,s);
		c->execute();
	}
}
