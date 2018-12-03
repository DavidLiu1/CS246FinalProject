#ifndef _CONTROLLER_
#define _CONTROLLER_


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
	void restart(int);
	void random(int);
	void nonrandom(int);
	void sequence(int);
	void test(int, char);

private:
	Model *model;
};

#endif