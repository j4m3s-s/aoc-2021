#include <iostream>
#include <sstream>
using std::cin;
using std::cout;
using std::stringstream;

#include <vector>
using std::vector;

#include <string>
#include <cstring>
using std::string;
using std::memset;

struct HydrothermalVent {
	int x1 = 0;
	int y1 = 0;
	int x2 = 0;
	int y2 = 0;
};

bool is_right_diagonal_line(int x1, int y1, int x2, int y2) {
	int xdiff = x2 - x1;
	int ydiff = y2 - y1;

	return xdiff == ydiff;
}

bool is_left_diagonal_line(int x1, int y1, int x2, int y2) {
	int xdiff = x2 - x1;
	int ydiff = y2 - y1;

	return (x1 + y1) == (x2 + y2)
		&& (xdiff < 0 || ydiff < 0);
}

int main(void) {
	vector<HydrothermalVent> input;

	string value;
	int x_max = 0;
	int y_max = 0;
	while (1) {
		if (!std::getline(cin, value)) {
			break;
		}

		stringstream strm(value);

		HydrothermalVent vent;
		string tmp;

		strm >> tmp;

		stringstream strmxy(tmp);

		// x1,y1
		string tmp2;

		std::getline(strmxy, tmp2, ',');
		vent.x1 = std::stoi(tmp2);
		if (x_max < vent.x1)
			x_max = vent.x1;

		std::getline(strmxy, tmp2, ',');
		vent.y1 = std::stoi(tmp2);
		if (y_max < vent.y1)
			y_max = vent.y1;

		// ->
		strm >> tmp;
		strm >> tmp;

		// x2,y2
		string tmp3;
		stringstream strmxy2(tmp);

		std::getline(strmxy2, tmp3, ',');
		vent.x2 = std::stoi(tmp3);
		if (x_max < vent.x2)
			x_max = vent.x2;

		std::getline(strmxy2, tmp3, ',');
		vent.y2 = std::stoi(tmp3);
		if (y_max < vent.y2)
			y_max = vent.y2;

		input.push_back(vent);
	}

	//cout << input.size() << ' ' << x_max << ' ' << y_max << '\n';

	const auto ARR_WIDTH = x_max + 1;
	const auto ARR_HEIGHT = y_max + 1;

	int *arr = new int[ARR_HEIGHT * ARR_WIDTH];
	memset(arr, 0, sizeof(arr[0]) * ARR_WIDTH * ARR_HEIGHT);


	// fill array
	for (auto vent : input) {
		if (vent.x1 != vent.x2)
			continue;

		for (int j = vent.y1; j <= vent.y2; j++) {
			arr[vent.x1 + j * ARR_WIDTH] += 1;
		}

		for (int j = vent.y2; j <= vent.y1; j++) {
			arr[vent.x1 + j * ARR_WIDTH] += 1;
		}
	}

	for (auto vent : input) {
		if (vent.y1 != vent.y2)
			continue;

		for (int i = vent.x1; i <= vent.x2; i++) {
			arr[vent.y1 * ARR_WIDTH + i] += 1;
		}

		for (int i = vent.x2; i <= vent.x1; i++) {
			arr[vent.y1 * ARR_WIDTH + i] += 1;
		}

	}

	for (auto vent : input ) {
		if (!is_right_diagonal_line(vent.x1, vent.y1, vent.x2, vent.y2))
			continue;

		int diff = vent.x2 - vent.x1;
		for (int i = 0; i <= diff; i++) {
			arr[vent.x1 + i + ARR_WIDTH * (i + vent.y1)] += 1;
		}

		diff = -diff;
		for (int i = 0; i <= diff; i++) {
			arr[vent.x2 + i + ARR_WIDTH * (i + vent.y2)] += 1;
		}
	}

	for (auto vent : input ) {
		if (!is_left_diagonal_line(vent.x1, vent.y1, vent.x2, vent.y2))
			continue;

		int x = vent.x1;
		int y = vent.y1;

		while (x <= vent.x2) {
			arr[x + y * ARR_WIDTH] += 1;
			x++;
			y--;
		}

		x = vent.x2;
		y = vent.y2;

		while (x <= vent.x1) {
			arr[x + y * ARR_WIDTH] += 1;
			x++;
			y--;
		}
	}


	size_t overlapping_points = 0;
	for (int i = 0; i < ARR_WIDTH; i++) {
		for (int j = 0; j < ARR_HEIGHT; j++) {
			if (arr[i + j * ARR_WIDTH] >= 2)
				overlapping_points++;
		}
	}

	cout << "Overlapping points " << overlapping_points << '\n';

// print array
//for (int j = 0; j < ARR_HEIGHT; j++) {
//	for (int i = 0; i < ARR_WIDTH; i++) {
//		if (arr[i + ARR_WIDTH * j] == 0)
//			cout << '.';
//		else
//			cout << arr[i + ARR_WIDTH * j];
//	}
//	cout << '\n';
//}


	delete[] arr;
}
