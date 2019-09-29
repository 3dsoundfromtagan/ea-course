#include <iostream>

#include "longnum.h"
#include <cstdlib>

#define N 6

using namespace std;
int main () {
	char* m1 = (char*)malloc(N * sizeof(char));
	m1[0] = '-';
	for (int i = 1; i < N; ++i) {
		m1[i] = '9' - 2*(i - 1);
	}
	string s1 = "-000123456789001";
	string s2 = "1234567890";
	long long i1 = -97531;
	LongNum a(m1);
	LongNum b(i1);
	a.printSign();
	cout << "a = " << a << " , b = " << b << endl;
	cout << "a == b is " << (a == b) << endl;
	free(m1);
	return 0;
}
