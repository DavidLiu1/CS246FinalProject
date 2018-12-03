#include "window.h"
#include "View.h"
#include <vector>

class WindowView : public View {
	Xwindow *win;
	std::vector <std::pair<int, int>> oldCurrPointsOne;
	std::vector <std::pair<int, int>> oldCurrPointsTwo;
public:
	WindowView(Controller*, Model*);
	~WindowView();
	virtual void update() override;

	void printScore();
	void printLevel();
	void printCurr();
	void eraseCurr();
	void printBlocks();
	void eraseRows();
	void restart();
	void printNext();
};

