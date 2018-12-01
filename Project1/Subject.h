#ifndef _SUBJECT_
#define _SUBJECT_

#include <vector>
class Observer;

class Subject {
public:
	void subscribe(Observer*);

protected:
	void notify();

private:
	typedef std::vector<Observer*> Observers;
	Observers observers_;
};

#endif