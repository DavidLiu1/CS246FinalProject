#include <iostream>
#include "Subject.h"
#include "Observer.h"

void Subject::subscribe(Observer *o) {
	observers_.push_back(o);
}

void Subject::notify() {
	Observers::iterator i;
	//std::cout << "notify" << std::endl;
	for (i = observers_.begin(); i != observers_.end(); ++i)
		(*i)->update();
}
