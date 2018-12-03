#include "window.h"
#include "View.h"
#include <vector>

class WindowView : public View {
	Xwindow *win;
	std::vector <std::pair<int, int>> points;
public:
	WindowView(Xwindow*, Controller*, Model*);
	~WindowView();

	void printScore();
	void printScore();
	void printCurr();
	void eraseCurr();
	void printBlocks();
	void eraseBlocks();

};

