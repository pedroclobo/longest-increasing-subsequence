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

	size_t size = v.size();

	vector<int> len(size, 1);
	vector<int> occ(size, 1);

	int max = -1;
	int occ_max = 1;
	for (size_t i = 0; i < size; i++) {
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
		if (len[i] > max) {
			max = len[i];
			occ_max = occ[i];
		} else if (len[i] == max) {
			occ_max += occ[i];
		}
	}

	cout << max << " " << occ_max << endl;
}

void p2() {
	vector<int> v1, v2;
	parse_vector(&v1);
	parse_vector(&v2);
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
