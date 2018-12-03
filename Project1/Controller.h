#ifndef _CONTROLLER_
#define _CONTROLLER_
#include <string>


class Model;

class Controller {
public:
	Controller(Model*);
	virtual ~Controller();
	void startGame();
	void levelUp(int);
	void levelDown(int);
	void right(int);
	void left(int);
	void down(int);
	void clockwise(int);
	void counterClockwise(int);
	void drop(int);
	void restart();
	void random();
	void nonrandom(std::string);
	void sequence(std::string);
	void test(std::string);
	void switchTurn();

private:
	Model *model;
};

#endif