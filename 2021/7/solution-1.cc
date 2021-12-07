#include <iostream>
using std::cin;
using std::cout;

#include <vector>
using std::vector;

#include <string>
using std::string;

#include <numeric>
#include <algorithm>

int abs(int a) {
	if (a < 0)
		return -a;
	return a;
}

size_t fuel_needed_to_align(vector<int>& vec) {
	std::sort(vec.begin(), vec.end());

	auto best = 1000000000;
	auto position = 0;

	for (int current_target_position = vec[0]; current_target_position < vec[vec.size() - 1]; current_target_position++) {
		auto fuel = 0;
		for (auto elt : vec) {
			fuel += abs(elt - current_target_position);
		}

		if (fuel < best) {
			best = fuel;
			position = current_target_position;
		}
	}

	cout << "Position " << position << '\n';

	return best;
}

int main(void) {
	vector<int> input;

	string tmp;
	while (std::getline(cin, tmp, ',')) {
		input.push_back(std::stoi(tmp));
	}

	cout << fuel_needed_to_align(input) << '\n';
}
