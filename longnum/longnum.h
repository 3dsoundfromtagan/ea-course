/*Have to redo:
*Constructor char*
* ==*/
#pragma once

#include <vector>
#include <string>

//Each element contains 9 digits
#define BASE 1000000000													

class LongNum {
	
	enum Sign {
		POSITIVE,
		NEGATIVE,
		ZERO,
	};	
	
public:
	//Constructors and deconstructor
	LongNum();
	
	//Auxiliary method for numerical constructors
	template < typename T >
	void Init_Num(unsigned long long new_value, T base);
	
	//Auxiliary method for string constructor
	void Init_Str(std:: string new_value);
	
	LongNum(const unsigned long long &new_value);
	LongNum(const long long &new_value);
	LongNum(const int &new_value);
	LongNum(const char* &new_value);
	LongNum(const std::string &new_value);
	~LongNum();
	
	//Getters
	std:: vector<int> getValue() const;
	Sign getSign() const;
	void printSign() const;
	
	//Setters
    void setValue(const std:: vector <int> &new_value);
    void setSign(const Sign &new_sign);
	
	void remove_lead_zeros();
	
	void printLN();
	
	friend std:: ostream& operator << (std:: ostream &os, const LongNum &longnum);
	friend bool operator == (const LongNum &lhs, const LongNum &rhs);
	friend LongNum operator + (const LongNum &lhs, const LongNum &rhs);




private:
	std:: vector<int> value;
	Sign _sign;												
};


template < typename T >
void LongNum:: Init_Num(unsigned long long tmp, T base) {
	std:: cerr << "in unsigned constructor, input data = " << tmp << "\n";
	if (!tmp) {
		std:: cerr << "tmp is equal to zero\n";
		value.clear();
		_sign = ZERO;
	}
	else {
		std:: cerr << "tmp is not equal to zero\n";
		_sign = POSITIVE;
	}
	do {
		value.push_back(tmp % base);
		tmp /= base;
	} while (tmp);
	remove_lead_zeros();
}

void LongNum:: Init_Str(std:: string tmp) {							
	if (!tmp.length()) {
		_sign = POSITIVE;
		value.clear();
	}
	else {
		if (tmp[0] == '-') {
			tmp = tmp.substr(1);
			_sign = NEGATIVE;
		}
		else {
			_sign = POSITIVE;
		}
		for (long long i = (long long)tmp.length(); i > 0; i -= 9) {
			if (i < 9)
				value.push_back (atoi (tmp.substr (0, i).c_str()));
			else
				value.push_back (atoi (tmp.substr (i-9, 9).c_str()));
		}
	}
	remove_lead_zeros();
}

LongNum:: LongNum() {
	value.clear();
	_sign = ZERO;
}

LongNum:: LongNum(const unsigned long long &new_value) {
	unsigned long long tmp = new_value;
	unsigned base = BASE;
	Init_Num(tmp, base);
}

LongNum:: LongNum(const long long &new_value) {
	long long tmp = new_value;
	unsigned base = BASE;
	if (tmp >= 0) {
		std:: cerr << "in long long; tmp = " << tmp << std:: endl;
		Init_Num((unsigned long long)(tmp), base);
	}
	else {
		Init_Num((unsigned long long)(-tmp), base);
		_sign = NEGATIVE;
	}
	
}

LongNum:: LongNum(const int &new_value): LongNum:: LongNum ((const long long)new_value) {}

LongNum:: LongNum(const char* &new_value) {									//DOESN'T WORK
	std:: string tmp = (std::string)new_value;
	Init_Str(tmp);
}

LongNum:: LongNum(const std::string &new_value) {	
	std:: string tmp = new_value;
	Init_Str(tmp);
}

LongNum:: ~LongNum() {
	
}


std::vector<int> LongNum:: getValue() const {
	return value;
}

LongNum:: Sign LongNum:: getSign() const {
		return _sign;
} 

void LongNum:: printSign() const {
	if (_sign == POSITIVE) {
		std:: cerr << "POSITIVE\n";
	}
	if (_sign == NEGATIVE) {
		std:: cerr << "NEGATIVE\n";
	}
	if (_sign == ZERO) {
		std:: cerr << "ZERO\n";
	}
}

void LongNum:: setValue(const std:: vector <int> &new_value) {
	value = new_value;
}

void LongNum:: setSign (const Sign &new_sign) {
	_sign = new_sign;
}

void LongNum:: remove_lead_zeros () {
	while (( value.size() > 1 ) && (value.back() == 0) ) {
		value.pop_back();		
	}
}
	
void LongNum:: printLN() {
	if (_sign == false) {
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
	if (rhs.getSign() == LongNum:: Sign:: NEGATIVE) {
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


