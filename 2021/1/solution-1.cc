#include <iostream>
using std::cin;
using std::cout;

#include <vector>
using std::vector;

int solve(vector<int> &v) {
	int total_increase = 0;
	int previous = v[0];

	for (int i = 1; i < v.size(); i++) {
		int current = v[i];

		if (current > previous)
			total_increase++;

		previous = current;
	}

	return total_increase;
}

int main(void) {
	vector<int> input;

	int value;
	while (cin >> value) {
		input.push_back(value);
	}

	cout << solve(input) << std::endl;
}
