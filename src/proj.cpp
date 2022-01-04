#include<climits>
#include<iostream>
#include<unordered_map>
#include<vector>

using namespace std;

int longest_increasing_subsequence_lenght(const vector<int> *v, unsigned long long *num_occ) {
	int len[v->size()];
	int occ[v->size()];

	int len_max = 0;
	int minimum = v->at(0);

	for (size_t i = 0; i < v->size(); i++) {
		len[i] = 1;
		occ[i] = 1;

		minimum = min(v->at(i), minimum);

		for (size_t j = 0; j < i; j++) {
			if (v->at(i) == minimum) {
				break;
			}
			if (i != 0 && v->at(i) == v->at(i-1)) {
				len[i] = len[i-1];
				occ[i] = occ[i-1];
				break;
			}
			if (v->at(i) > v->at(j)) {
				if (len[j] + 1 > len[i]) {
					len[i] = len[j] + 1;
					occ[i] = occ[j];
				} else if (len[j] + 1 == len[i]) {
					occ[i] += occ[j];
				}
			}
		}

		if (len[i] > len_max) {
			len_max = len[i];
			*num_occ = occ[i];
		} else if (len[i] == len_max) {
			*num_occ += occ[i];
		}
	}

	return len_max;
}
int longest_common_increasing_subsequence_lenght(const vector<int> *v1, const vector<int> *v2, int min2) {
   	int lcis[2][v2->size()+1];

	for (size_t i = 0; i < 2; i++) {
		lcis[i][0] = 0;
	}

	for (size_t j = 0; j <= v2->size(); j++) {
		lcis[0][j] = 0;
	}

	int max_length;
	for (size_t i = 1; i <= v1->size(); i++) {
		max_length = 0;
		for (size_t j = 1; j <= v2->size(); j++) {
			lcis[i % 2][j] = lcis[(i-1) % 2][j];
			if (v1->at(i-1) < min2) {
				break;
			}
			if (v1->at(i-1) > v2->at(j-1)) {
				max_length = max(max_length, lcis[(i-1) % 2][j]);
			} else if (v1->at(i-1) == v2->at(j-1)) {
				lcis[i % 2][j] = 1 + max_length;
			}
		}
	}

	int result = 0;
	for (size_t j = 0; j <= v2->size(); j++) {
		result = max(result, lcis[v1->size() % 2][j]);
	}

	return result;
}

void p1() {
	vector<int> v;

	int number;
	char c;
	size_t inc = 0;
	size_t dec = 0;
	size_t eq = 0;

	while (scanf("%d%c", &number, &c)) {
		if (!v.empty()) {
			if (number > v.back()) {
				inc++;
			} else if (number < v.back()) {
				dec++;
			} else if (number == v.back()) {
				eq++;
			}
		}
		v.push_back(number);
		if (c == '\n') {
			break;
		}
	}

	if (inc == v.size() - 1) {
		cout << v.size() << " " << 1 << endl;
		return;
	} else if (dec == v.size() - 1 - eq) {
		cout << 1 << " " << v.size() << endl;
		return;
	}

	unsigned long long occ;
	int len = longest_increasing_subsequence_lenght(&v, &occ);

	cout << len << " " << occ << endl;
}

void p2() {
	vector<int> v1, v2, coms;
	unordered_map<int, bool> commons;

	int number;
	char c;

	int min1 = INT_MIN;
	while (scanf("%d%c", &number, &c)) {
		v1.push_back(number);
		commons[number] = true;
		min1 = min(min1, number);
		if (c == '\n') {
			break;
		}
	}

	int min2 = INT_MIN;
	while (scanf("%d%c", &number, &c)) {
		if (commons[number] == true) {
			v2.push_back(number);
			min2 = min(min2, number);
		}
		if (c == '\n') {
			break;
		}
	}

	if (v1.size() > v2.size()) {
		cout << longest_common_increasing_subsequence_lenght(&v1, &v2, min2) << endl;
	} else {
		cout << longest_common_increasing_subsequence_lenght(&v2, &v1, min1) << endl;
	}
}

int main() {
	short flag;
	cin >> flag;

	if (flag == 1) {
		p1();
	} else if (flag == 2) {
		p2();
	}

	return 0;
}
