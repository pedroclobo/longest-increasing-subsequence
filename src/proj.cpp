#include<iostream>
#include<unordered_map>
#include<vector>

using namespace std;

void longest_increasing_subsequence_lenght(vector<int> *v) {
	size_t size = v->size();

	int len[size], occ[size];
	int len_max = 0;
	unsigned long long occ_max = 0;

	int len_i;
	int occ_i;

	for (size_t i = 0; i < size; i++) {
		len_i = 1;
		occ_i = 1;

		for (size_t j = 0; j < i; j++) {
			if ((*v)[i] > (*v)[j]) {
				if (len[j] + 1 > len_i ) {
					len_i = len[j] + 1;
					occ_i = occ[j];
				} else if (len[j] + 1 == len_i) {
					occ_i += occ[j];
				}
			}
		}

		if (len_i > len_max) {
			len_max = len_i;
			occ_max = occ_i;
		} else if (len_i == len_max) {
			occ_max += occ_i;
		}

		len[i] = len_i;
		occ[i] = occ_i;
	}

	cout << len_max << " " << occ_max << endl;
}

void longest_common_increasing_subsequence_lenght(const vector<int> *v1, const vector<int> *v2) {
	int len[2][v2->size()+1];

	for (size_t i = 0; i < 2; i++) {
		len[i][0] = 0;
	}

	for (size_t j = 0; j <= v2->size(); j++) {
		len[0][j] = 0;
	}

	int local_length;

	for (size_t i = 1; i <= v1->size(); i++) {
		local_length = 0;
		for (size_t j = 1; j <= v2->size(); j++) {
			len[i % 2][j] = len[(i-1) % 2][j];
			if (v1->at(i-1) > v2->at(j-1)) {
				local_length = max(local_length, len[(i-1) % 2][j]);
			} else if (v1->at(i-1) == v2->at(j-1)) {
				len[i % 2][j] = 1 + local_length;
			}
		}
	}

	int len_max = 0;
	for (size_t j = 0; j <= v2->size(); j++) {
		len_max = max(len_max, len[v1->size() % 2][j]);
	}

	cout << len_max << endl;
}

void p1() {
	vector<int> v;

	int number;
	char c;

	while (scanf("%d%c", &number, &c)) {
		v.push_back(number);
		if (c == '\n') {
			break;
		}
	}

	longest_increasing_subsequence_lenght(&v);
}

void p2() {
	vector<int> v1, v2;
	unordered_map<int, bool> commons;

	int number;
	char c;

	while (scanf("%d%c", &number, &c)) {
		v1.push_back(number);
		commons[number] = true;
		if (c == '\n') {
			break;
		}
	}

	while (scanf("%d%c", &number, &c)) {
		if (commons[number] == true) {
			v2.push_back(number);
		}
		if (c == '\n') {
			break;
		}
	}

	if (v1.size() > v2.size()) {
		longest_common_increasing_subsequence_lenght(&v1, &v2);
		return;
	} else {
		longest_common_increasing_subsequence_lenght(&v2, &v1);
		return;
	}
}

int main() {
	int flag;
	cin >> flag;

	if (flag == 1) {
		p1();
	} else if (flag == 2) {
		p2();
	}

	return 0;
}
