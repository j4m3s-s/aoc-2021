#include <iostream>
using std::cin;
using std::cout;

#include <vector>
using std::vector;

#include <string>
using std::string;

void print_lanternfish(size_t *arr) {
	for (int i = 0; i < 9; i++) {
		cout << arr[i] << ',';
	}
	cout << '\n';
}

int main(void) {

	size_t lantern_count[9];
	for (int i = 0; i < 9; i++) {
		lantern_count[i] = 0;
	}

	string tmp;
	while (std::getline(cin, tmp, ',')) {
		lantern_count[std::stoi(tmp)] += 1;
	}

	const int TOTAL_DAY = 256;
	for (int day_count = 0; day_count < TOTAL_DAY; day_count++) {
		//print_lanternfish(lantern_count);
		size_t new_lantern = lantern_count[0];
		for (int i = 0; i < 8; i++) {
			lantern_count[i] = lantern_count[i + 1];
		}
		lantern_count[8] = new_lantern;
		lantern_count[6] += new_lantern;
	}

	size_t sum = 0;
	for (int i = 0; i < 9; i++) {
		sum += lantern_count[i];
	}

	cout << "Result " << sum << '\n';
}
