#include "Subject.h"
#include "Board.h"

class Model : public Subject {
	Board *boardOne;
	Board *boardTwo;
public:
	Model();
	~Model();
};