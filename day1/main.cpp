#include <iostream>
#include "MyInt.h"

using namespace std;

int main() {
	MyInt m1, m2(5), m3(6);
	cout << m1 << " " << m2 << endl;
	cout << ++m1 << " " << m2++ << endl;
	cout << m1 << " " << m2 << endl;
	cout << (m2 + m3) << " " << m2 * m3 << endl;
	cout << m1 << " " << m2 << endl;
	cout << m1 / m2 << " " << m1 % m2 << endl;
	cout << (m1 < m2) << endl;
	cout << (m1 <= m2) << endl;
	cout << (m1 > m2) << endl;
	cout << (m1 >= m2) << endl;
	cout << (m1 == m2) << endl;
	cout << (m1 != m2) << endl;
	
	return 0;
}
