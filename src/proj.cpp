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

int longest_increasing_subsequence_lenght(vector<int> *v, int *num_occ) {
	vector<int> len;
	vector<int> occ;
	int len_max = 0;

	for (size_t i = 0; i < v->size(); i++) {
		len.push_back(1);
		occ.push_back(1);

		for (size_t j = 0; j < i; j++) {
			if (v->at(j) < v->at(i)) {
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

int longest_common_increasing_subsequence_lenght(vector<int> *v1, vector<int> *v2) {
   	int aux[v2->size()];
	for (size_t i = 0; i < v2->size(); i++) {
		aux[i] = 0;
	}

	int len_max = 0;
	for (size_t i = 0; i < v1->size(); i++) {
		int lcis = 0;
		for (size_t j = 0; j < v2->size(); j++) {
			if (v1->at(i) == v2->at(j)) {
				aux[j] = max(lcis + 1, aux[j]);
				len_max = max(aux[j], len_max);
			} else if (v1->at(i) > v2->at(j)) {
				lcis = max(lcis, aux[j]);
			}
		}
	}

	return len_max;
}

void p1() {
	vector<int> v;
	parse_vector(&v);

	int occ;
	int len = longest_increasing_subsequence_lenght(&v, &occ);

	cout << len << " " << occ << endl;
}

void p2() {
	vector<int> v1, v2;
	parse_vector(&v1);
	parse_vector(&v2);

	int len;
	if (v1.size() > v2.size()) {
		len = longest_common_increasing_subsequence_lenght(&v2, &v1);
	} else {
		len = longest_common_increasing_subsequence_lenght(&v1, &v2);
	}

	cout << len << endl;
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
