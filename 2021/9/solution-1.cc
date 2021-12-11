#include <iostream>
using std::cin;
using std::cout;

#include <vector>
using std::vector;

#include <string>
using std::string;

bool is_position_defined(size_t i, size_t j, size_t width, size_t height) {
	return i < width && j < height;
}

bool is_lowest_among_neighbour(string &value, size_t i, size_t j, size_t width, size_t height) {
	auto left   = is_position_defined(i - 1, j, width, height);
	auto right  = is_position_defined(i + 1, j, width, height);
	auto bottom = is_position_defined(i, j + 1, width, height);
	auto top    = is_position_defined(i, j - 1, width, height);

	auto current = value[i + j * width];

	auto result = true;
	if (left) {
		result = result && current < value[(i - 1) + j * width];
	}
	if (right) {
		result = result && current < value[(i + 1) + j * width];
	}
	if (top) {
		result = result && current < value[i + (j - 1) * width];
	}
	if (bottom) {
		result = result && current < value[i + (j + 1) * width];
	}

	return result;

}

size_t find_low_points_risk(string& value, size_t width, size_t height) {
	size_t risk = 0;
	for (size_t i = 0; i < width; i++) {
		for (size_t j = 0; j < height; j++) {
			if (is_lowest_among_neighbour(value, i, j, width, height)) {
				//cout << "Position : " << i << ' ' << j << " value " << value[i + j * width] << '\n';
				auto nb = value[i + j * width] - '0';
				risk += nb + 1;
			}
		}
	}
	return risk;
}

int main(void) {
	string value;
	size_t width = 0;
	size_t height = 0;

	string tmp;
	while (cin >> tmp) {
		value += tmp;
		width = tmp.size();
		height++;
	}

	cout << value << ' ' << width << ' ' << height << std::endl;
	cout << find_low_points_risk(value, width, height) << '\n';
}
