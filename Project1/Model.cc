#include <string>
#include "Model.h"
#include "emptyCommend.h"
#include "levelDowncmd.h"
#include "levelUpcmd.h"
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
Model::Model(string s1, string s2) : boardOne{ new Board(s1) }, boardTwo{ new Board(s2) }{};
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
	notify();
}
void Model::drop(int num) {//	hewfu	wefhu	hweihfhuh
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
	state_ = State::DROP;
	notify();
}
void Model::restart() {
	if (turn_ == Model::Turn::PLAYER_ONE) {
		getBoardOne()->restart();
	}
	else {
		getBoardTwo()->restart();
	}
	state_ = State::RESTART;
	notify();
}
void Model::switchTurn() {
	if (turn_ == Model::Turn::PLAYER_ONE) {
		turn_ = Model::Turn::PLAYER_TWO;
	}
	else {
		turn_ = Model::Turn::PLAYER_ONE;
	}
}
