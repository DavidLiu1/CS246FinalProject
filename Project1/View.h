#include "Observer.h"

class Controller;
class Model;

class View : public Observer {
public:
	View(Controller*, Model*);
	virtual ~View();
	virtual void update() = 0;

protected:
	Model *model;
	Controller *controller;
};