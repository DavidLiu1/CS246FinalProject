
#include <vector>
class Observer;

class Subject {
public:
	void subscribe(Observer*);
	void unsubscribe(Observer*);

protected:
	void notify();

private:
	typedef std::vector<Observer*> Observers;
	Observers observers_;
};