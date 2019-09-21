#include <iostream>

using namespace std;

class MyNum {
public:	
	MyNum(const int &new_val);
	void print();
	
protected:
	int val;
	
};


MyNum:: MyNum(const int &new_val) {
	val = new_val;
}

void MyNum:: print() {
	cout << val << "\n";
}

int main () {
	MyNum a(5);
	a.print();
	return 0;
}
