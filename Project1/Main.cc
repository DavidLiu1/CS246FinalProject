#include "Model.h"
#include "Controller.h"
#include "TextView.h"
//#include "WindowView.h"

int main(int argc, char * argv[]) {
	Model m = Model("Sequence1","Sequence2");
	Controller controller(&m);  
	TextView view(&controller, &m);

	//WindowView view(&controller, &m);
}