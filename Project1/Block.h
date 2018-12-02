#pragma once
#include <utility>
#include <vector>
#include <string>
class Block
{
protected:
	int level;
	int state;
	bool heavy;
	std::pair<int, int> base;
	std::vector <std::pair<int, int>> points;
	std::string color;
public:
	Block(bool h, int l, std::string c);
	//return true if after remove theres no points left
	bool removeRow(int i);
	virtual ~Block();
	int getLevel();
	void moveLeft(std::vector <std::vector<bool>> const grid);
	void moveRight(std::vector <std::vector<bool>> const grid);
	bool moveDown(std::vector <std::vector<bool>> const grid);
	bool filled(std::vector <std::vector<bool>> const grid);
	void drop(std::vector <std::vector<bool>> const grid);
	virtual void rotateClock(std::vector <std::vector<bool>> const grid) = 0;
	virtual void rotateCounter(std::vector <std::vector<bool>> const grid) = 0;
	std::vector <std::pair<int, int>> getPointes();
	bool isHeavy();
	virtual std::string getColor() = 0;
	//commend function
	void getComment(std::string s) {
		int index = 0;
		int mult = 0;
		while (s.at(index) < '9'&&s.at(index) > '0') {
			mult = mult * 10 + (int)(s.at(index) - '0');
			s = s.substr(1, s.size() - 1);
		}
		if (s.substr(0, 3) == "lef") {
			if (isPreixOf(s, "left")) {

			}
		}
		else if (s.substr(0.2) == "ri") {
			if (isPreixOf(s, "right")) {

			}
		}
		else if (s.substr(0, 2) == "do") {
			if (isPreixOf(s, "down")) {

			}
		}
		else if (s.substr(0, 2) == "cl") {
			if (isPreixOf(s, "clockwise")) {

			}
		}
		else if (s.substr(0, 2) == "co") {
			if (isPreixOf(s, "counterclockwise")) {

			}
		}
		else if (s.substr(0, 2) == "dr") {
			if (isPreixOf(s, "drop")) {

			}
		}
		else if (s.substr(0, 6) == "levelu") {
			if (isPreixOf(s, "levelup")) {

			}
		}
		else if (s.substr(0, 6) == "leveld") {
			if (isPreixOf(s, "leveldown")) {

			}
		}
		else if (s.substr(0, 1) == "n") {
			if (isPreixOf(s, "nonrandom")) {

			}
		}
		else if (s.substr(0, 1) == "ra") {
			if (isPreixOf(s, "random")) {

			}
		}
		else if (s.substr(0, 2) == "se") {
			if (isPreixOf(s, "sequence")) {

			}
		}
		else if (s.substr(0, 1) == "i") {
			if (isPreixOf(s, "i")) {

			}
		}
		else if (s.substr(0, 1) == "j") {
			if (isPreixOf(s, "j")) {

			}
		}
		else if (s.substr(0, 1) == "l") {
			if (isPreixOf(s, "l")) {

			}
		}
		else if (s.substr(0, 1) == "t") {
			if (isPreixOf(s, "t")) {

			}
		}
		else if (s.substr(0, 1) == "o") {
			if (isPreixOf(s, "o")) {

			}
		}
		else if (s.substr(0, 1) == "s") {
			if (isPreixOf(s, "s")) {

			}
		}
		else if (s.substr(0, 1) == "z") {
			if (isPreixOf(s, "z")) {

			}
		}
	

	}
	bool isPreixOf(std::string cmd, std::string action) {

		if (cmd.size() > action.size()) {
			return false;
		}
		for (int i = 0; i < cmd.size; i++) {
			if (!cmd.at(i) == action.at(i)) {
				return false;
			}
		}
		return true;
	}
};

