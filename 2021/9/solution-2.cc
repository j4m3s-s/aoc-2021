#include <iostream>
using std::cin;
using std::cout;

#include <vector>
using std::vector;

#include <string>
using std::string;

#include <queue>
using std::queue;

#include <algorithm>

#include <set>
using std::set;


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

struct position {
	size_t i, j;

	bool has_left(size_t width, size_t height);
	bool has_right(size_t width, size_t height);
	bool has_bottom(size_t width, size_t height);
	bool has_top(size_t width, size_t height);

	position get_left();
	position get_right();
	position get_bottom();
	position get_top();

	auto operator<=>(const position&) const = default;
};

position position::get_left() {
	return {i - 1, j };
}

position position::get_right() {
	return {i + 1, j };
}

position position::get_bottom() {
	return {i, j + 1};
}

position position::get_top() {
	return {i, j - 1 };
}

bool position::has_left(size_t width, size_t height) {
	return this->i != 0;
}

bool position::has_right(size_t width, size_t height) {
	return this->i + 1 <= width;
}

bool position::has_bottom(size_t width, size_t height) {
	return this->j + 1 <= height;
}

bool position::has_top(size_t width, size_t height) {
	return this->j != 0;
}

char get_value(string& value, position pos, size_t width) {
	return value[pos.i + pos.j * width] - '0';
}

size_t find_basins(string& value, size_t width, size_t height) {
	vector<position> lowest_points_positions;
	for (size_t i = 0; i < width; i++) {
		for (size_t j = 0; j < height; j++) {
			if (is_lowest_among_neighbour(value, i, j, width, height)) {
				lowest_points_positions.push_back({i, j});
			}
		}
	}

	vector<size_t> basins_size;
	for (auto current_pos : lowest_points_positions) {
		size_t size = 1;
		queue<position> q;
		set<position> set;

		q.push(current_pos);
		while (!q.empty()) {
			auto pos = q.front();
			q.pop();

			auto current = value[pos.i + pos.j * width] - '0';

			// iterate over neighbour_positions
			if (pos.has_left(width, height)
				&& current + 1 == get_value(value, pos.get_left(), width)
				&& current + 1 != 9
				&& set.find(pos.get_left()) == set.end()) {
				q.push(pos.get_left());
				size++;
				set.insert(pos.get_left());
			}

			if (pos.has_right(width, height)
				&& current + 1 == get_value(value, pos.get_right(), width)
				&& current + 1 != 9
				&& set.find(pos.get_right()) == set.end()) {
				q.push(pos.get_right());
				size++;
				set.insert(pos.get_right());
			}


			if (pos.has_top(width, height)
				&& current + 1 == get_value(value, pos.get_top(), width)
				&& current + 1 != 9
				&& set.find(pos.get_top()) == set.end()) {
				q.push(pos.get_top());
				size++;
				set.insert(pos.get_top());
			}

			if (pos.has_bottom(width, height)
				&& current + 1 == get_value(value, pos.get_bottom(), width)
				&& current + 1 != 9
				&& set.find(pos.get_bottom()) == set.end()) {
				q.push(pos.get_bottom());
				size++;
				set.insert(pos.get_bottom());
			}
		}

		basins_size.push_back(size);
	}


	std::sort(basins_size.begin(), basins_size.end());
	cout << "Len " << basins_size.size() << '\n';
	auto len = basins_size.size();
	auto res = basins_size[len - 3] * basins_size[len - 2] * basins_size[len - 1];
	cout << "-res-: " << basins_size[len - 3] << ' ' << basins_size[len - 2] << ' ' << basins_size[len - 1] << '\n';
	cout << "res " << res << '\n';
	return res;
}

int main() {
	string value;
	size_t width = 0;
	size_t height = 0;

	string tmp;
	while (cin >> tmp) {
		value += tmp;
		width = tmp.size();
		height++;
	}

	cout << width << ' ' << height << std::endl;
	cout << find_basins(value, width, height) << '\n';
}
