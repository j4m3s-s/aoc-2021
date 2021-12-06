#include <iostream>
using std::cin;
using std::cout;

#include <vector>
using std::vector;

#include <string>
using std::string;

void print_lanternfish(vector<int>& vec) {
	for (auto a : vec) {
		cout << a << ',';
	}
	cout << '\n';
}

int main(void) {
	vector<int> input;

	string tmp;
	while (std::getline(cin, tmp, ',')) {
		input.push_back(std::stoi(tmp));
	}

	const int TOTAL_DAY = 80;
	for (int day_count = 0; day_count < TOTAL_DAY; day_count++) {
		cout << "Day " << day_count << " : ";
		print_lanternfish(input);

		const int size = input.size();
		for (int i = 0; i < size; i++) {
			if (input[i] == 0) {
				input.push_back(8);
				input[i] = 7;
			}
			input[i] -= 1;
		}
	}

	cout << "Result " << input.size() << '\n';
}
