#pragma once

#include <vector>
#include <cstring>
#include <algorithm>

//Each element contains 9 digits
//Сыпется при изменении. Причины не выяснил
#define BASE 1000000000													

//
#define KARATSUBA_OPTIMAL 1

class LongNum {
	
	enum Sign {
		POSITIVE,
		NEGATIVE,
		ZERO,
	};	
	
public:
	//Constructors and deconstructor
	LongNum();
	LongNum(const LongNum &new_value);
	LongNum(const unsigned long long &new_value);
	LongNum(const long long &new_value);
	LongNum(const int &new_value);
	LongNum(const char* &new_value);
	LongNum(const std::string &new_value);
	~LongNum();
	
	//Copy assignment
	LongNum &operator = (const LongNum & rhs);
	
	//Auxiliary method for numerical constructors
	template < typename T >
	void Init_Num(unsigned long long new_value, T base);
	
	//Auxiliary method for string constructor
	void Init_Str(std:: string new_value);	
	
	//Getters
	std:: vector<int> getValue() const;
	Sign getSign() const;
	long long getSize() const;
	void printSign() const;
	
	//Setters
    void setValue(const std:: vector <int> &new_value);
    void setSign(const Sign &new_sign);
	
	void remove_lead_zeros();
	
	void printLN();
	
	friend std:: ostream& operator << (std:: ostream &os, const LongNum &longnum);
	
	friend bool operator == (const LongNum &lhs, const LongNum &rhs);
	template < typename T >
	friend bool operator == (const LongNum &lhs, const T &rhs);
	template < typename T >
	friend bool operator == (const T &lhs, const LongNum &rhs);
	
	friend bool operator !=(const LongNum &lhs, const LongNum &rhs);
	template < typename T >
	friend bool operator != (const LongNum &lhs, const T &rhs);
	template < typename T >
	friend bool operator != (const T &lhs, const LongNum &rhs);
	
	friend bool operator <(const LongNum &lhs, const LongNum &rhs); 
	template < typename T >
	friend bool operator < (const LongNum &lhs, const T &rhs);
	template < typename T >
	friend bool operator < (const T &lhs, const LongNum &rhs);
	
	friend bool operator <=(const LongNum &lhs, const LongNum &rhs); 
	template < typename T >
	friend bool operator <= (const LongNum &lhs, const T &rhs);
	template < typename T >
	friend bool operator <= (const T &lhs, const LongNum &rhs);
	
	friend bool operator >(const LongNum &lhs, const LongNum &rhs);
	template < typename T >
	friend bool operator > (const LongNum &lhs, const T &rhs);
	template < typename T >
	friend bool operator > (const T &lhs, const LongNum &rhs);
	
	friend bool operator>=(const LongNum &lhs, const LongNum &rhs);
	template < typename T >
	friend bool operator>= (const LongNum &lhs, const T &rhs);
	template < typename T >
	friend bool operator>= (const T &lhs, const LongNum &rhs);
	
	
	LongNum operator+() const;
	
	friend LongNum operator+(const LongNum &lhs, const LongNum &rhs);
	template < typename T >
	friend LongNum operator + (const LongNum &lhs, const T &rhs);
	template < typename T >
	friend LongNum operator + (const T &lhs, const LongNum &rhs);
	
	//Prefix increment
	const friend LongNum& operator++ (LongNum &rhs);
	
	//Postfix increment
	const friend LongNum operator++ (LongNum &rhs, int);
	
	LongNum& operator += (const LongNum &rhs);
	template < typename T >
	LongNum& operator += (const T &rhs);
	
	LongNum operator-() const;
	
	friend LongNum operator-(const LongNum &lhs, const LongNum &rhs);
	template < typename T >
	friend LongNum operator - (const LongNum &lhs, const T &rhs);
	template < typename T >
	friend LongNum operator - (const T &lhs, const LongNum &rhs);

	//Prefix decrement
	const friend LongNum& operator-- (LongNum &rhs);
	
	//Postfix decrement
	const friend LongNum operator-- (LongNum &rhs, int);

	LongNum& operator -= (const LongNum &rhs);
	template < typename T >
	LongNum& operator -= (const T &rhs);
	
	
	friend LongNum operator*(const LongNum &lhs, const LongNum &rhs);
	template < typename T >
	friend LongNum operator * (const LongNum &lhs, const T &rhs);
	template < typename T >
	friend LongNum operator * (const T &lhs, const LongNum &rhs);
	
	LongNum common_mply(const LongNum &lhs, const LongNum &rhs);
	LongNum karatsuba_mply(const LongNum &lhs, const LongNum &rhs);
	
	//BASE multiplication
	void shift_right();
	
	//Naive div using binary search
	friend LongNum operator/(const LongNum &lhs, const LongNum &rhs);
	template < typename T >
	friend LongNum operator / (const LongNum &lhs, const T &rhs);
	template < typename T >
	friend LongNum operator / (const T &lhs, const LongNum &rhs);
	
private:
	std:: vector<int> value;
	Sign _sign;												
};


template < typename T >
void LongNum:: Init_Num(unsigned long long tmp, T base) {
	if (!tmp) {
		value.clear();
		_sign = ZERO;
	}
	else {
		_sign = POSITIVE;
	}
	do {
		value.push_back(tmp % base);
		tmp /= base;
	} while (tmp);
	remove_lead_zeros();
}

void LongNum:: Init_Str(std:: string tmp) {							
	if (!tmp.length() || (tmp.length() == 1 && tmp[0] == '0')) {
		_sign = ZERO;
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

LongNum:: LongNum(const LongNum &new_value) {
	value = new_value.getValue();
	_sign = new_value.getSign();
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
		Init_Num((unsigned long long)(tmp), base);
	}
	else {
		Init_Num((unsigned long long)(-tmp), base);
		_sign = NEGATIVE;
	}
	
}

LongNum:: LongNum(const int &new_value): LongNum:: LongNum ((const long long)new_value) {}

LongNum:: LongNum(const char* &new_value) {								
	std:: string tmp = (std::string)new_value;
	Init_Str(tmp);
}

LongNum:: LongNum(const std::string &new_value) {	
	std:: string tmp = new_value;
	Init_Str(tmp);
}

LongNum:: ~LongNum() {}

LongNum & LongNum:: operator = (const LongNum & rhs) {
	if (this == &rhs) {
        return *this;
    }

    value = rhs.value;
	_sign = rhs._sign;
    return *this;
}


std::vector<int> LongNum:: getValue() const {return value;}

LongNum:: Sign LongNum:: getSign() const {return _sign;} 

long long LongNum:: getSize() const {return value.size();}

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

void LongNum:: setValue(const std:: vector <int> &new_value) {value = new_value;}

void LongNum:: setSign (const Sign &new_sign) {_sign = new_sign;}

void LongNum:: remove_lead_zeros () {
	while (( value.size() > 1 ) && (value.back() == 0) ) {
		value.pop_back();		
	}
}
	
/*void LongNum:: printLN() {
	if (_sign == LongNum:: Sign::NEGATIVE) {
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
}*/

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

template < typename T >
bool operator == (const LongNum &lhs, const T &rhs) {
	return (lhs == LongNum(rhs));
}

template < typename T >
bool operator == (const T &lhs, const LongNum &rhs) {
	return (LongNum(lhs) == rhs);
}
	
	
bool operator !=(const LongNum& lhs, const LongNum& rhs) {return !(lhs == rhs);}

template < typename T >
bool operator != (const LongNum &lhs, const T &rhs) {return !(lhs == LongNum(rhs));}

template < typename T >
bool operator != (const T &lhs, const LongNum &rhs) {return !(LongNum(lhs) == rhs);}


bool operator < (const LongNum& lhs, const LongNum& rhs) {
		if (lhs == rhs) {return false;}
		if ((lhs.getSign() == LongNum:: Sign:: POSITIVE) && (rhs.getSign() == LongNum:: Sign:: POSITIVE)) {
			if (lhs.getSize() != rhs.getSize()) {
				return (lhs.getSize() < rhs.getSize());
			}
			else {
				for (long long i = 0; i < lhs.getSize(); ++i) {
					if (lhs.value[i] != rhs.value[i]) {
						return (lhs.value[i] < rhs.value[i]);
					}
				}
				return true;
			}
		}
		
		if ((lhs.getSign() == LongNum:: Sign:: POSITIVE) && ((rhs.getSign() == LongNum:: Sign:: NEGATIVE) || (rhs.getSign() == LongNum:: Sign:: ZERO))){
			return false;
		}
		
		if (((lhs.getSign() == LongNum:: Sign:: NEGATIVE) || (lhs.getSign() == LongNum:: Sign:: ZERO)) && (rhs.getSign() == LongNum:: Sign:: POSITIVE)) {
			return true;
		}
	   
		if ((lhs.getSign() == LongNum:: Sign:: ZERO) && (rhs.getSign() == LongNum:: Sign:: POSITIVE)) return true;
		if ((lhs.getSign() == LongNum:: Sign:: ZERO) && (rhs.getSign() == LongNum:: Sign:: NEGATIVE)) return false;
		
		else {
			return ((-rhs) < (-lhs));
		}

}

template < typename T >
bool operator < (const LongNum &lhs, const T &rhs) {return (lhs < LongNum(rhs));}

template < typename T >
bool operator < (const T &lhs, const LongNum &rhs) {return (LongNum(lhs) < rhs);}



bool operator <=(const LongNum &lhs, const LongNum &rhs) {
        return (lhs < rhs || lhs == rhs);
}
template < typename T >
bool operator <= (const LongNum &lhs, const T &rhs) {return (lhs <= LongNum(rhs));}

template < typename T >
bool operator <= (const T &lhs, const LongNum &rhs) {return (LongNum(lhs) <= rhs);}



 
bool operator >(const LongNum &lhs, const LongNum &rhs) {
        return !(lhs <= rhs);
}
template < typename T >
bool operator > (const LongNum &lhs, const T &rhs) {return (lhs > LongNum(rhs));}

template < typename T >
bool operator > (const T &lhs, const LongNum &rhs) {return (LongNum(lhs) > rhs);}

 
bool operator >=(const LongNum &lhs, const LongNum &rhs) {
        return !(lhs < rhs);
}
template < typename T >
bool operator >= (const LongNum &lhs, const T &rhs) {return (lhs >= LongNum(rhs));}

template < typename T >
bool operator >= (const T &lhs, const LongNum &rhs) {return (LongNum(lhs) >= rhs);}



LongNum LongNum:: operator +() const{
	return LongNum(*this);
}

LongNum operator +(const LongNum &lhs, const LongNum &rhs) {
	LongNum tmp;
	if ((lhs.getSign() == LongNum:: Sign:: POSITIVE) && (rhs.getSign() == LongNum:: Sign:: POSITIVE)) {
		//carry flag
		int carry = 0;
		//temporary values
		int val_left = 0;
		int val_right = 0;
		for (long long i = 0; (i < (long long)std:: max(lhs.getSize(), rhs.getSize())) || (carry); ++i) {
				if (i == (long long)tmp.getSize()) {tmp.value.push_back(0);}
				if (i < lhs.getSize()) {val_left = lhs.value[i];}
				if (i < rhs.getSize()) {val_right = rhs.value[i];}
				tmp.value[i] = tmp.value[i] + carry + val_left + val_right;
				carry = (tmp.value[i] >= BASE);
				if (carry) {
					tmp.value[i] -= BASE;
				}
				val_left = 0;
				val_right = 0;
		
		}
		tmp._sign = LongNum:: Sign:: POSITIVE;
		return tmp;
	}
	if ((lhs.getSign() == LongNum:: Sign:: NEGATIVE) && (rhs.getSign() == LongNum:: Sign:: NEGATIVE)) { return -(-(lhs) + -(rhs));	}
	if ((lhs.getSign() == LongNum:: Sign:: NEGATIVE) && (rhs.getSign() == LongNum:: Sign:: POSITIVE)) {	return (rhs - (-lhs));}
	if ((lhs.getSign() == LongNum:: Sign:: POSITIVE) && (rhs.getSign() == LongNum:: Sign:: NEGATIVE)) {return (rhs - (-lhs));}
	if ((lhs.getSign() == LongNum:: Sign:: ZERO) && ( (rhs.getSign() == LongNum:: Sign:: NEGATIVE) || (rhs.getSign() == LongNum:: Sign:: ZERO) || (rhs.getSign() == LongNum:: Sign:: POSITIVE))) {return rhs;}
	else {return lhs;}	
	
}

template < typename T >
LongNum operator + (const LongNum &lhs, const T &rhs) {return (lhs + LongNum(rhs));}

template < typename T >
LongNum operator + (const T &lhs, const LongNum &rhs) {return (LongNum(lhs) + rhs);}

const LongNum& operator++ (LongNum &rhs) {
	rhs = rhs + LongNum((int)1);
	return rhs;
}

const LongNum operator++ (LongNum &rhs, int) {
	LongNum tmp(rhs);
	rhs = rhs + LongNum((int)1);
	return tmp;
}

LongNum& LongNum:: operator += (const LongNum &rhs) {
	return *this = (*this + rhs);
}

template < typename T >
LongNum& LongNum:: operator += (const T &rhs) {
	return *this = (*this + LongNum(rhs));
}


LongNum LongNum:: operator -() const{
	LongNum tmp(*this);

	if (tmp.getSign() == LongNum:: Sign:: NEGATIVE) {
		tmp._sign = LongNum:: Sign:: POSITIVE;
		return tmp;
	}
	if (tmp.getSign() == LongNum:: Sign:: POSITIVE) {
		tmp._sign = LongNum:: Sign:: NEGATIVE;
		return tmp;
	}
	else {return tmp;}
}

LongNum operator -(const LongNum &lhs, const LongNum &rhs) {
	if (lhs == rhs) {return LongNum(0);}
	LongNum tmp(lhs);
	if ((lhs.getSign() == LongNum:: Sign:: POSITIVE) && (rhs.getSign() == LongNum:: Sign:: POSITIVE)) {
		if (lhs > rhs) {
			//carry flag
			int carry = 0;
			//temporary values
			int val_right = 0;
			for (long long i = 0; (i < rhs.getSize()) || (carry); ++i) {
				if (i < rhs.getSize()) {val_right = rhs.value[i];}
				tmp.value[i] = tmp.value[i] - (carry + val_right);
				carry = (tmp.value[i] < 0);
				if (carry) {
					tmp.value[i] += BASE;
				}
				val_right = 0;
			}
			tmp._sign = LongNum:: Sign:: POSITIVE;
			tmp.remove_lead_zeros();
			return tmp;
		}
		else {
			return -(rhs - lhs);
		}
	}
	if ((lhs.getSign() == LongNum:: Sign:: NEGATIVE) && (rhs.getSign() == LongNum:: Sign:: NEGATIVE)) { return ((-rhs) - (-lhs));}
	if ((lhs.getSign() == LongNum:: Sign:: NEGATIVE) && (rhs.getSign() == LongNum:: Sign:: POSITIVE)) {	return -((-lhs) + rhs);}
	if ((lhs.getSign() == LongNum:: Sign:: POSITIVE) && (rhs.getSign() == LongNum:: Sign:: NEGATIVE)) {return (lhs + (-rhs));}
	if ((lhs.getSign() == LongNum:: Sign:: ZERO) && ( (rhs.getSign() == LongNum:: Sign:: NEGATIVE) || (rhs.getSign() == LongNum:: Sign:: ZERO) || (rhs.getSign() == LongNum:: Sign:: POSITIVE))) {return (-rhs);}
	//Positive OR Negative - Zero
	else {return lhs;}		
}

template < typename T >
LongNum operator - (const LongNum &lhs, const T &rhs) {return (lhs - LongNum(rhs));}

template < typename T >
LongNum operator - (const T &lhs, const LongNum &rhs) {return (LongNum(lhs) - rhs);}

const LongNum& operator-- (LongNum &rhs) {
	rhs = rhs - LongNum((int)1);
	return rhs;
}

const LongNum operator-- (LongNum &rhs, int) {
	LongNum tmp(rhs);
	rhs = rhs - LongNum((int)1);
	return tmp;
}

LongNum& LongNum:: operator -= (const LongNum &rhs) {
	return *this = (*this - rhs);
}

template < typename T >
LongNum& LongNum:: operator -= (const T &rhs) {
	return *this = (*this - LongNum(rhs));
}

LongNum LongNum:: common_mply(const LongNum& lhs, const LongNum& rhs) {
	this->_sign = LongNum:: Sign:: POSITIVE;
	long long lhs_size = lhs.getSize();
	long long rhs_size = rhs.getSize();
	
	this->value.resize(lhs_size + rhs_size);
	for (long long i = 0; i < lhs_size; ++i) {
		long long carry = 0;
		for (long long j = 0; j < rhs_size || carry != 0; ++j) {
			//Не сразу в ответ, ибо мб переполнение. И простите за тернарный оператор
			long long cur = this->value[i + j] + carry + (long long)lhs.value[i] * (j < rhs_size ? rhs.value[j] : 0);
			this->value[i + j] = static_cast<int>(cur % BASE);
			carry = static_cast<int>(cur / BASE);
		}
		this->value[i + rhs_size] += carry;
	}
	this->remove_lead_zeros();
	return *this;
}

/*LongNum LongNum:: karatsuba_mply(const LongNum& lhs, const LongNum& rhs) {
	LongNum tmp_lhs = lhs;
	LongNum tmp_rhs = rhs;
	
	long long k = std:: max(lhs.getSize(), rhs.getSize()) / 2 + 1;
	tmp_lhs.value.resize(k, 0);
	
	
	return *this;
}*/

//After (in case :)) Karatsuba realization change common_mply to karatsuba_mply
LongNum operator *(const LongNum &lhs, const LongNum &rhs) {
	if ((lhs.getSign() == LongNum:: Sign:: ZERO) || (rhs.getSign() == LongNum:: Sign:: ZERO)) { return LongNum(0);}
	LongNum tmp;
	
	if ((lhs.getSign() == LongNum:: Sign:: POSITIVE) && (rhs.getSign() == LongNum:: Sign:: POSITIVE)) {
		tmp.common_mply(lhs, rhs);	
		return tmp;	
	}
	
	if ((lhs.getSign() == LongNum:: Sign:: NEGATIVE) && (rhs.getSign() == LongNum:: Sign:: POSITIVE)) {
		tmp.common_mply((-lhs), rhs);
		tmp._sign = LongNum:: Sign:: NEGATIVE;
		return tmp;		
	}
	
	if ((lhs.getSign() == LongNum:: Sign:: POSITIVE) && (rhs.getSign() == LongNum:: Sign:: NEGATIVE)) {
		tmp.common_mply(lhs, (-rhs));
		tmp._sign = LongNum:: Sign:: NEGATIVE;
		return tmp;		
	}
	
	else {
		tmp.common_mply((-lhs), (-rhs));		
	}
	return tmp;
}

template < typename T >
LongNum operator * (const LongNum &lhs, const T &rhs) {return (lhs * LongNum(rhs));}

template < typename T >
LongNum operator * (const T &lhs, const LongNum &rhs) {return (LongNum(lhs) * rhs);}


void LongNum:: shift_right() {
	if (this->value.size() == 0) {
		this->value.push_back(0);
		return;
	}
	
	this->value.push_back(this->value[this->value.size() - 1]);
	
	for (long long i = this->value.size() - 2; i > 0; --i) {
		this->value[i] = this->value[i - 1];		
	}
	
	this->value[0] = 0;	
}

LongNum operator /(const LongNum &lhs, const LongNum &rhs) {
	if (rhs.getSign() == LongNum:: Sign:: ZERO) {
		throw std:: runtime_error("divisor cannot be zero");
	}
	if (lhs.getSign() == LongNum:: Sign:: ZERO) {
		return LongNum(0);
	}
	
	if ((lhs.getSign() == LongNum:: Sign:: POSITIVE) && (rhs.getSign() == LongNum:: Sign:: POSITIVE)) {
		LongNum result, current;
		result._sign = LongNum:: Sign:: POSITIVE;
		result.value.resize(lhs.getSize());
		
		for (long long i = static_cast<long long>(lhs.getSize()) - 1; i >= 0; --i){
			current.shift_right();
			current.value[0] = lhs.value[i];
			current.remove_lead_zeros();
			current._sign = LongNum:: Sign:: POSITIVE;
			/*std:: cerr << "before current = " << current << " , sign = ";
			current.printSign();
			std:: cerr << "\n";*/
			//use bin search to find the maximum divisor
			int ans = 0, left = 0, right = BASE;
			LongNum tmp;
			while(left <= right) {
				int medium = (left + right) / 2;
				tmp = rhs * medium;
				/*std:: cerr << "rhs =  "<< rhs << " tmp =  "<< " " << tmp << "\n";
				std:: cerr << "current =  " << current << " medium = " << medium << "\n";
				std:: cerr << "left =  " << left << " right = " << right << "\n";
				std:: cerr << "ans =  " << ans << "\n" ;
				std:: cerr << "tmp <= LongNum(current)) ==  " << (tmp <= current) << "\n" ;
				std:: cerr << "tmp sign =  ";
				tmp.printSign(); 
				std:: cerr << " current sign =  ";
				current.printSign();
				std:: cerr<< "\n" ;*/
				if (tmp <= current) {
					
					ans = medium;
					left = medium + 1;
				}
				else {
					right = medium - 1;
				}
							//std::cerr << "right = "<< right << " medium = " << medium << "tmp = " << tmp<<"ans = " << ans << "\n";

			}
			
			result.value[i] = ans;
			current = current - rhs * ans;			
			//std::cerr << "_____________\n" << "result[i] = " << ans << " current = " << current << "\n";
		}
		result.remove_lead_zeros();
		/*std:: cerr << "result = " << result << "sign = ";
		result.printSign();
		std::cerr << "\n";*/
		return result;
	}
	
	if ((lhs.getSign() == LongNum:: Sign:: POSITIVE) && (rhs.getSign() == LongNum:: Sign:: NEGATIVE)) {
		//std:: cerr << "-rhs = " << (-rhs) << "\n";
		//(-rhs).printSign();
		LongNum result = (lhs / (-rhs));
		result._sign = LongNum:: Sign:: NEGATIVE;
		return result;
	}
	
	if ((lhs.getSign() == LongNum:: Sign:: NEGATIVE) && (rhs.getSign() == LongNum:: Sign:: POSITIVE)) {
	//std:: cerr << "-rhs = " << (-rhs) << "\n";
	//(-rhs).printSign();
	LongNum result = ((-lhs) / rhs);
	result._sign = LongNum:: Sign:: NEGATIVE;
	return result;
	}
	
	else {
		LongNum result = ((-lhs) / (-rhs));
		result._sign = LongNum:: Sign:: POSITIVE;
		return result;
	}
}
