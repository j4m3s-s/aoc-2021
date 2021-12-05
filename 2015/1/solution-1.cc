#include <iostream>
using std::cin;
using std::cout;

#include <vector>
using std::vector;

#include <string>
using std::string;

int main(void) {
	string value;
	cin >> value;

	int floor = 0;
	for (auto &c : value) {
		if (c == '(') {
			floor++;
		} else if (c == ')') {
			floor--;
		}
	}
	cout << "Floor : " << floor << '\n';
}
