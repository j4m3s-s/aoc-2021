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
	for (int i = 0; i < value.size(); i++) {
		if (value[i] == '(') {
			floor++;
		} else if (value[i] == ')') {
			floor--;
		}
		if (floor == -1) {
			cout << "Value : " << i + 1 << '\n';
		}
	}
	cout << "Floor : " << floor << '\n';
}
