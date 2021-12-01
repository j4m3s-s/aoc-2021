#include <iostream>
using std::cin;
using std::cout;

#include <vector>
using std::vector;

#include <map>
using std::map;

int vector_count_increase(vector<int> &v) {
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

vector<int> get_3sliding_window(vector<int> &v) {
	map<int, int> m;
	int counter = 0;

	int a = v[0] + v[1];
	int b = v[1];
	int c = 0;

	for (int i = 2; i < v.size(); i++) {
		a += v[i];
		b += v[i];
		c += v[i];

		if ((i + 1) % 3 == 0) {
			m[counter++] = a;
			a = 0;
		} else if ((i + 1) % 3 == 1) {
			m[counter++] = b;
			b = 0;
		} else if ((i + 1) % 3 == 2) {
			m[counter++] = c;
			c = 0;
		}
	}

	vector<int> res;
	for (auto it : m) {
		res.push_back(std::get<1>(it));
	}

	return res;
}

int main(void) {
	vector<int> input;

	int value;
	while (cin >> value) {
		input.push_back(value);
	}

	auto sliding_win = get_3sliding_window(input);
	cout << vector_count_increase(sliding_win) << std::endl;
}
