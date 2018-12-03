#include "Subject.h"
#include "Board.h"
#include <string>

class Model : public Subject {
public:
	Model(std::string s1, std::string s2);
	~Model();
	Board* getBoardOne();
	Board* getBoardTwo();
	enum class State {
		NEW_GAME,
		BOARD_ONE_INPUT,
		BOARD_TWO_INPUT,
		CURR_BLOCK,
		DROP,
		LVL_CHANGE,
		SCORE_CHANGE,
		NEXT_BLOCK,
		RESTART
	};
	enum class Turn {
		PLAYER_ONE,
		PLAYER_TWO
	};
	void newGame();
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
	void nonrandom();
	void sequence();
	void test(char);
	void switchTurn();
	State state() const;
	Turn turn() const;
private:
	State state_;
	Turn turn_;
	Board *boardOne;
	Board *boardTwo;


};