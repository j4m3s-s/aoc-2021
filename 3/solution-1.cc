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

size_t solve(vector<string> &v) {
	size_t sum_bit[NB_BIT];
	memset(sum_bit, 0, NB_BIT * sizeof(sum_bit[0]));

	for (int i = 0; i < v.size(); i++) {
		for (int j = 0; j < NB_BIT; j++) {
			char c = v[i][j];
			sum_bit[j] += (c - '0');
		}
	}

	bitset<NB_BIT> gamma;
	for (int j = 0; j < NB_BIT; j++) {
		gamma[NB_BIT - j - 1] = sum_bit[j] * 2 > v.size();
	}

	bitset<NB_BIT> epsilon = gamma;
	epsilon.flip();

	size_t gamma_i = gamma.to_ulong();
	size_t epsilon_i = epsilon.to_ulong();
	return gamma_i * epsilon_i;
}

int main(void) {
	vector<string> input;

	string value;
	int count = 0;
	while (1) {
		value = "";
		count += 1;
		if (!cin) {
			break;
		}
		cin >> value;
		if(value.length() != NB_BIT) {
			break;
		}
		input.push_back(value);
	}
	cout << solve(input) << std::endl;
}
