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
	vector<int> v1;
	parse_vector(&v1);
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
