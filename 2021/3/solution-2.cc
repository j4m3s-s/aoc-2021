#include <iostream>
using std::cin;
using std::cout;

#include <vector>
using std::vector;

#include <string.h>
#include <string>
using std::string;

#include <assert.h>

#include <bitset>
using std::bitset;

const auto NB_BIT = 12;

using NUMBER = bitset<NB_BIT>;

size_t solve_least_present(vector<NUMBER> &v, int bit_position) {
	if (bit_position == NB_BIT) {
		return v[0].to_ulong();
	}
	if (v.size() == 1) {
		return v[0].to_ulong();
	}

	size_t number_of_1bit = 0;

	for (auto elt : v) {
		if (elt.test(NB_BIT - bit_position - 1)) {
			number_of_1bit += 1;
		}
	}

	size_t bit_to_keep = 0;
	if (number_of_1bit * 2 >= v.size())
		bit_to_keep = 0;
	else
		bit_to_keep = 1;


	vector<NUMBER> sub;

	for (auto elt : v) {
		if (elt.test(NB_BIT - bit_position - 1) == bit_to_keep) {
			sub.push_back(elt);
		}
	}

	return solve_least_present(sub, bit_position + 1);
}

size_t solve_most_present(vector<NUMBER> &v, int bit_position) {
	if (bit_position == NB_BIT) {
		return v[0].to_ulong();
	}
	if (v.size() == 1) {
		return v[0].to_ulong();
	}

	size_t counter = 0;

	for (auto elt : v) {
		counter += elt[NB_BIT - bit_position - 1];
	}

	size_t bit_to_keep = counter * 2 > v.size();
	if (counter * 2 == v.size())
		bit_to_keep = 1;

	vector<NUMBER> sub;

	for (auto elt : v) {
		if (elt[NB_BIT - bit_position - 1] == bit_to_keep)
			sub.push_back(elt);
	}

	return solve_most_present(sub, bit_position + 1);
}

NUMBER str_to_number(string& str) {
	NUMBER ret;
	for (int i = 0; i < NB_BIT; i++) {
		ret[NB_BIT - 1 - i] = str[i] - '0';
	}
	return ret;
}

int main(void) {
	vector<NUMBER> input;

	string value;
	while (1) {
		value = "";
		if (!cin) {
			break;
		}
		cin >> value;
		if(value.length() != NB_BIT) {
			break;
		}
		input.push_back(str_to_number(value));
	}

	auto oxygen = solve_most_present(input, 0);
	auto co2 = solve_least_present(input, 0);

	cout << oxygen << ' ' << co2 << std::endl;
	cout << oxygen * co2 << '\n';
}
