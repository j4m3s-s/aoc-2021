#include <iostream>
using std::cin;
using std::cout;

#include <vector>
using std::vector;

#include <string>
using std::string;

enum class ActionType {
	Forward,
	Down,
	Up,
};

struct Action {
	ActionType type;
	int value;
};

int solve(vector<Action>& input) {
	int aim = 0;
	int depth = 0;
	int horizontal_position = 0;

	for (auto v : input) {
		if (v.type == ActionType::Forward) {
			horizontal_position += v.value;
			depth += aim * v.value;
		} else if (v.type == ActionType::Up) {
			aim -= v.value;
		} else if (v.type == ActionType::Down) {
			aim += v.value;
		} else {
			cout << "ABORT\n";
		}
	}

	return depth * horizontal_position;
}

int main(void) {
	vector<Action> input;

	while (1) {
		if (!cin)
			break;

		Action action;

		string tmp;
		cin >> tmp;
		if (tmp == "forward")
			action.type = ActionType::Forward;
		else if (tmp == "down")
			action.type = ActionType::Down;
		else if (tmp == "up")
			action.type = ActionType::Up;
		else
			break; // last line is '\n'

		cin >> action.value;

		input.push_back(action);
		cout << tmp << ' ' << action.value << '\n';
	}

	cout << solve(input) << std::endl;
}
