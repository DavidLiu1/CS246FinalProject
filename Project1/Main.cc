#include "Model.h"
#include "Controller.h"
#include "TextView.h"

int main(int argc, char * argv[]) {
	Model m = Model();
	Controller controller(&m);  
	TextView view(&controller, &m);
}