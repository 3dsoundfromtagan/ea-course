#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main () {
	string src = "1.1.1.1";
	stringstream ss;
	ss << src;
	string s1, s2, s3, s4, s;
	getline(ss, s1, '.');
	getline(ss, s2, '.');
	getline(ss, s3, '.');
	getline(ss, s4);
	s = s1 + "[.]" + s2 + "[.]" + s3+ "[.]" + s4;
	cout << s;
	//cout << s1 << "[.]" << s2 << "[.]" << s3 << "[.]" << s4;
	return 0;
}
