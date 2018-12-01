#include "Subject.h"
#include "Observer.h"

void Subject::subscribe(Observer *o) {
	observers_.push_back(o);
}

void Subject::notify() {
	Observers::iterator i;
	for (i = observers_.begin(); i != observers_.end(); ++i)
		(*i)->update();
}
