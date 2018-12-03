#include "Subject.h"
#include "Board.h"


class Model : public Subject {
public:
	Model();
	~Model();
	Board* getBoardOne();
	Board* getBoardTwo();
	enum class State {
		NEW_GAME,
		BOARD_ONE_INPUT,
		BOARD_TWO_INPUT,
		CURR_BLOCK,
		CLEAR_ROW,
		LVL_UP,
		SCORE_CHANGE,
		NEXT_BLOCK,
		RESTART
	};
	void newGame();

	State state() const;

private:
	State state_;
	Board *boardOne;
	Board *boardTwo;


};