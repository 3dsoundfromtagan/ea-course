#pragma once

#include <vector>
#include <string>

//Each element contains 9 digits
#define BASE 1000000000													

class LongNum {
public:
	//Constructors and deconstructor
	LongNum();
	LongNum(int &new_value);
	LongNum(long long &new_value);
	LongNum(unsigned long long &new_value);
	LongNum(char* &new_value);
	LongNum(std::string &new_value);
	~LongNum();
	
	//Getters
	std:: vector<int> getValue() const;
	bool getSign() const;
	
	//Setters
    void setValue(const std:: vector <int> &new_value);
    void setSign(const bool &new_sign);
	
	void remove_lead_zeros();
	
	void printLN();
	
	friend std:: ostream& operator << (std:: ostream &os, const LongNum &longnum);
	friend bool operator == (const LongNum &lhs, const LongNum &rhs);
	friend LongNum operator + (const LongNum &lhs, const LongNum &rhs);




private:
	std:: vector<int> value;
	//TRUE is positive, FALSE is negative
	bool sign;															
};

LongNum:: LongNum() {
	value.clear();
	sign = true;
}

LongNum:: LongNum(int &new_value) {
	if (!new_value) {
		value.clear();
		sign = true;
	}
	if (new_value < 0) {
		sign = false;
		new_value = -new_value;
	}
	else {
		sign = true;
	}
	do {
		value.push_back(new_value % BASE);
		new_value /= BASE;
	} while (new_value);
	remove_lead_zeros();
}

LongNum:: LongNum(unsigned long long &new_value) {
	if (!new_value) {
		value.clear();
		sign = true;
	}
	else {
		sign = true;
	}
	do {
		value.push_back(new_value % BASE);
		new_value /= BASE;
	} while (new_value);
	remove_lead_zeros();
}

LongNum:: LongNum(long long &new_value) {
	if (!new_value) {
		value.clear();
		sign = true;
	}
	if (new_value < 0) {
		sign = false;
		new_value = -new_value;
	}
	else {
		sign = true;
	}
	do {
		value.push_back(new_value % BASE);
		new_value /= BASE;
	} while (new_value);
	remove_lead_zeros();
}

/*LongNum:: LongNum(char* &new_value) {									//DOESN'T WORK
	const int ASIZE = sizeof(new_value) / sizeof (*new_value);
	std:: cout << ASIZE;
	if (new_value == NULL){
		sign = true;
		value.clear();
	}
	
	remove_lead_zeros();
}*/

LongNum:: LongNum(std::string &new_value) {								
	if (!new_value.length()) {
		sign = true;
		value.clear();
	}
	else {
		if (new_value[0] == '-') {
			new_value = new_value.substr(1);
			sign = false;
		}
		else {
			sign = true;
		}
		for (long long i = (long long)new_value.length(); i > 0; i -= 9) {
			if (i < 9)
				value.push_back (atoi (new_value.substr (0, i).c_str()));
			else
				value.push_back (atoi (new_value.substr (i-9, 9).c_str()));
		}
	}
	remove_lead_zeros();
}

LongNum:: ~LongNum() {
	
}


std::vector<int> LongNum:: getValue() const {
	return value;
}

bool LongNum:: getSign() const {
		return sign;
} 

void LongNum:: setValue(const std:: vector <int> &new_value) {
	value = new_value;
}

void LongNum:: setSign (const bool &new_sign) {
	sign = new_sign;
}

void LongNum:: remove_lead_zeros () {
	while (( value.size() > 1 ) && (value.back() == 0) ) {
		value.pop_back();		
	}
}
	
void LongNum:: printLN() {
	if (sign == false) {
		std:: cout << "-";
	}
	if (getValue().empty()) {
		std:: cout << 0;
	}
	else {
		std:: cout << getValue().back();
	}
	for (int i=(int)getValue().size() - 2; i >= 0; --i) {
		printf ("%09d", getValue()[i]);
	}
	return;
}

std:: ostream& operator << (std:: ostream &os, const LongNum &rhs) {
	if (rhs.getSign() == false) {
		os << "-";
	}
	if (rhs.getValue().empty()) {
		os << 0;
	}
	else {
		os << rhs.getValue().back();
	}
	
	for (int i=(int)rhs.getValue().size() - 2; i >= 0; --i) {
		printf ("%09d", rhs.getValue()[i]);
	}
	return os;
}

bool operator == (const LongNum &lhs, const LongNum &rhs) {
	if (lhs.getSign()!= rhs.getSign()) {
		return false;
	}
	
	//Two forms of zero
	if (rhs.value.empty()) {
		if (lhs.value.empty() || (lhs.value.size() == 1 && lhs.value[0] == 0)) {
			return true;
		}
		else {
			return false;
		}
	}
	if (lhs.value.empty()) {
		if (rhs.value.empty() || (rhs.value.size() == 1 && rhs.value[0] == 0)) {
			return true;
		}
		else {
			return false;
		}
	}

	if (lhs.value.size() != rhs.value.size()) {
		return false;
	}
	for (long long i = 0; i < (long long)lhs.value.size(); i++) {
		if (lhs.value[i] != rhs.value[i]) {
			return false;
		}
	}
	return true;
}

/*LongNum operator + (const LongNum &lhs, const LongNum &rhs) {
		
}*/


