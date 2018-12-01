#include "View.h"
#include "Model.h"
#include "Controller.h"

View::View(Controller*c, Model*m) : model(m), controller(c) {
	model->subscribe(this);
};

View::~View() {};
