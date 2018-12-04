#include "window.h"
#include "View.h"
#include <vector>
#include <string>

class WindowView : public View {
	Xwindow *win;
	std::vector <std::pair<int, int>> oldCurrPointsOne;
	std::vector <std::pair<int, int>> oldCurrPointsTwo;
	
	public:
	WindowView(Controller*, Model*);
	~WindowView();
	virtual void update() override;

	void printNewGame();

	void printScore();
	void printLevel();
	void printCurr(int board);
	void eraseCurr();
	void printBlocks();
	void eraseRows();
	void restart();
	void eraseNext();
	void drawNext(int board, std::string type);

	char getColor(std::string c);
};

