#include "Model.h"
#include "Controller.h"
#include "TextView.h"
#include "WindowView.h"

int main(int argc, char * argv[]) {
	Model m = Model("Sequence1.txt","Sequence2.txt");
	Controller controller(&m);  
	TextView tView(&controller, &m);
	WindowView wView(&controller, &m);
	controller.startGame();
}