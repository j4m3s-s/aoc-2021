#include <iostream>
#include <sstream>
using std::cin;
using std::cout;
using std::stringstream;

#include <vector>
using std::vector;

#include <string>
using std::string;

const auto ARR_SIZE = 25;
const auto ARR_WIDTH = 5;

struct board {
	// designated initializers
	int arr[ARR_SIZE] = { 0 };
	int seen[ARR_SIZE] = { 0 };
};

bool is_board_winning(board& board) {
	int bingo_count = 0;

	// line wise
	for (int i = 0; i < ARR_WIDTH; i++) {
		bingo_count = 0;

		for (int j = 0; j < ARR_WIDTH; j++) {
			bingo_count += board.seen[i + j * 5];
		}

		if (bingo_count == 5)
			return true;
	}

	for (int j = 0; j < ARR_WIDTH; j++) {
		bingo_count = 0;
		for (int i = 0; i < ARR_WIDTH; i++) {
			bingo_count += board.seen[i + j * 5];
		}

		if (bingo_count == 5)
			return true;
	}
	return false;
}

size_t board_score(board& board, int nb) {
	size_t sum = 0;

	for (int i = 0; i < ARR_SIZE; i++) {
		if (!board.seen[i])
			sum += board.arr[i];
	}

	return nb * sum;
}

int main(void) {
	vector<int> bingo_numbers;
	string bingo_line;

	cin >> bingo_line;

	stringstream strm(bingo_line);

	string val;

	while (std::getline(strm, val, ',')) {
		bingo_numbers.push_back(std::stoi(val));
	}

	vector<board> boards;

	int counter = 0;
	board current;

	while (std::getline(cin, val)) {
		if (counter == 0 && val == "")
			continue;
		if (val == "") {
			counter = 0;
			boards.push_back(current);
			continue;
		}

		stringstream number_strm(val);
		int tmp;

		for (int i = 0; i < 5; i++) {
			number_strm >> tmp;
			current.arr[counter++] = tmp;
		}
	}

	for (auto nb : bingo_numbers) {
		cout << "Picking " << nb << '\n';
		for (auto &board : boards) {
			for (int i = 0; i < ARR_SIZE; i++) {
				if (board.arr[i] == nb) {
					board.seen[i] = 1;
					break;
				}
			}

			if (is_board_winning(board)) {
				cout << "Score : " << board_score(board, nb) << '\n';
				return 0;
			}
		}
	}
}
