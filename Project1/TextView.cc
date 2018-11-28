#include "TextView.h"
#include "Model.h"
#include <iostream>

using namespace std;

TextView::TextView(){
}
TextView::~TextView()
{
}
void TextView::printBoard() {

}
void TextView::printInfo() {
	cout << model_->getBoardOne()->getLvl << endl;
	cout << model_->getBoardOne()->getLvl << endl;
}