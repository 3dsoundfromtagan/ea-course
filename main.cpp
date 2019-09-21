#include <iostream>

#include "longnum.h"
#include <stdlib.h>

#define N 0

using namespace std;
int main () {
	string s1 = "-000123456789001";
	string s2 = "-123456789006";
	LongNum a(s1);
	LongNum b(s2);
	cout << (a == b) << endl;
	
	return 0;
}
