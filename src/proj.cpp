#include<iostream>
#include<vector>

using namespace std;

void parse_vector(vector<int> *v) {
	int number;
	char c;
	while (scanf("%d%c", &number, &c)) {
		v->push_back(number);
		if (c == '\n') {
			break;
		}
	}
}

void p1() {
	vector<int> v;
	parse_vector(&v);

	int len[v.size()];
	int occ[v.size()];
	for (size_t i = 0; i < v.size(); i++) {
		len[i] = occ[i] = 1;
	}

	int len_max = 0;
	int occ_max = 0;
	for (size_t i = 0; i < v.size(); i++) {
		for (size_t j = 0; j < i; j++) {
			if (v[j] < v[i]) {
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
			occ_max = occ[i];
		} else if (len[i] == len_max) {
			occ_max += occ[i];
		}
	}

	cout << len_max << " " << occ_max << endl;
}

void p2() {
	vector<int> v1, v2;
	parse_vector(&v1);
	parse_vector(&v2);

	int len[v1.size()+1][v2.size()+1];

	int len_max = 0;
	int last_common = -1;
	bool is_last_common = false;

	for (size_t i = 0; i <= v1.size(); i++) {
		for (size_t j = 0; j <= v2.size(); j++) {
			if (i == 0 || j == 0) {
				len[i][j] = 0;
			} else if (v1[i-1] == v2[j-1]) {
				if (is_last_common == true && v1[i-1] > last_common) {
					len[i][j] = len[i-1][j-1] + 1;
				} else if (is_last_common == false) {
					is_last_common = true;
					last_common = v1[i-1];
					len[i][j] = len[i-1][j-1] + 1;
				} else {
					last_common = v1[i-1];
					len[i][j] = len[i-1][j-1];
				}
			} else {
				len[i][j] = max(len[i-1][j], len[i][j-1]);
			}
			if (len[i][j] > len_max) {
				len_max = len[i][j];
			}
		}
	}

	cout << len_max << endl;
}

int main() {
	short opt;
	cin >> opt;

	switch(opt) {
		case 1:
			p1();
			break;
		case 2:
			p2();
			break;
	}

	return 0;
}
