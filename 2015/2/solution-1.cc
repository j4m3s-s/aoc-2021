#include <iostream>
#include <sstream>
using std::stringstream;
using std::cin;
using std::cout;

#include <vector>
using std::vector;

#include <string>
using std::string;

#include <algorithm>

int smallest_side_area(int lwh[3]) {
	std::sort(lwh, lwh +3);
	return lwh[0] * lwh[1];
}

int main(void) {
	string value;

	size_t paper_total_size = 0;

	while (cin >> value) {
		if (!cin)
			break;
		if (value.size() == 0)
			break;

		stringstream strm(value);
		string tmp;
		int counter = 0;
		int lwh[3] = { 0 };

		while (std::getline(strm, tmp, 'x')) {
			lwh[counter++] = std::stoi(tmp);
		}
		int l = lwh[0];
		int w = lwh[1];
		int h = lwh[2];
		paper_total_size += 2 * l * w + 2 * w * h + 2 * h * l;
		paper_total_size += smallest_side_area(lwh);
	}

	cout << "Size of paper needed : " << paper_total_size << '\n';
}
