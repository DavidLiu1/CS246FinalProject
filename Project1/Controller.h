#ifndef _CONTROLLER_
#define _CONTROLLER_


class Model;

class Controller {
public:
	Controller(Model*);
	virtual ~Controller();
	void startGame();
	void levelup();
	void leveldown();
	void right();
	void left();
	void down();
	void clockwise();
	void counterClockWise();
	void drop();
	void restart();

private:
	Model *model;
};

#endif