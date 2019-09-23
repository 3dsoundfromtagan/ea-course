#include <iostream>

#include "longnum.h"
#include <stdlib.h>

#define N 0

using namespace std;
int main () {
	string s1 = "-000123456789001";
	string s2 = "1234567890";
	int i1 = -79;
	LongNum a(i1);
	//LongNum b(s2);
	a.printSign();
	cout << "a = " << a << endl;
	//cout << "a = b == " << (a == b) << endl;
	
	return 0;
}
