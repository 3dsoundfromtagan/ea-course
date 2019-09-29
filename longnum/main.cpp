#include <iostream>

#include "longnum.h"
#include <cstdlib>

#define N 11
#define DEFAULT_EXAMPLE 0

using namespace std;
int main () {
	LongNum long_empty;
	cerr << "long_empty = " << long_empty << endl;
	
	unsigned long long my_ull = DEFAULT_EXAMPLE;
	LongNum long_ull(my_ull);
	cerr << "long_ull = " << long_ull << endl;
	
	long long my_ll = DEFAULT_EXAMPLE;
	LongNum long_ll(my_ll);
	cerr << "long_ll = " << long_ll << endl;
	
	int my_int = DEFAULT_EXAMPLE;
	LongNum long_int(my_int);
	cerr << "long_int = " << long_int << endl;
	
	char* my_char = (char*)malloc(N * sizeof(char));
	my_char[0] = '-';
	for (int i = 1; i < N; ++i) {
		my_char[i] = '9' - (i - 1);
	}
	LongNum long_char(my_char);
	cerr << "long_char = " << long_char << endl;
	
	string my_string = "1234567890";
	LongNum long_string(my_string);
	cerr << "long_string = " << long_string << endl;
	
	cerr << "long_int == long_ll is " << (long_int == long_ll) << endl;
	cerr << "long_empty != long_ull is " << (long_empty != long_ull) << endl;
	
	/*char* m1 = (char*)malloc(N * sizeof(char));
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
	free(m1);*/
	return 0;
}
