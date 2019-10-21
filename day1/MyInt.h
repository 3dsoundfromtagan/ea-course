#pragma once

class MyInt {
public:
	MyInt();
	MyInt(const int &my_int);
	~MyInt();
	
	int getValue() const;
	friend std:: ostream& operator << (std:: ostream &os, const MyInt &longnum);

	
	MyInt operator+() const;
	
	friend MyInt operator+(const MyInt &lhs, const MyInt &rhs);
	//Prefix increment
	const friend MyInt& operator++ (MyInt &rhs);
	
	//Postfix increment
	const friend MyInt operator++ (MyInt &rhs, int);
	
	MyInt& operator += (const MyInt &rhs);
	
	MyInt operator-() const;
	friend MyInt operator-(const MyInt &lhs, const MyInt &rhs);
	//Prefix increment
	const friend MyInt& operator-- (MyInt &rhs);
	
	//Postfix increment
	const friend MyInt operator-- (MyInt &rhs, int);
	
	MyInt& operator -= (const MyInt &rhs);
	
	friend MyInt operator*(const MyInt &lhs, const MyInt &rhs);
	friend MyInt operator/(const MyInt &lhs, const MyInt &rhs);

	
	
	MyInt &operator = (const MyInt & rhs);
	friend bool operator == (const MyInt &lhs, const MyInt &rhs);
	friend bool operator != (const MyInt &lhs, const MyInt &rhs);

	friend bool operator<(const MyInt &lhs, const MyInt &rhs);
	friend bool operator<=(const MyInt &lhs, const MyInt &rhs);
	friend bool operator>(const MyInt &lhs, const MyInt &rhs);
	friend bool operator>=(const MyInt &lhs, const MyInt &rhs);
	
	friend MyInt operator*(const MyInt &lhs, const MyInt &rhs);
	friend MyInt operator/(const MyInt &lhs, const MyInt &rhs);
	friend MyInt operator%(const MyInt &lhs, const MyInt &rhs);
	
	
private:
	int value;
};

MyInt::	MyInt() {
	value = 0;
}

MyInt::	MyInt(const int &my_int) {
	value = my_int;
}

MyInt::	~MyInt() {}

int MyInt::	getValue() const{
	return value;
}


std:: ostream& operator << (std:: ostream &os, const MyInt &my_int){
	std::cout << my_int.getValue();
	return os;
}

MyInt MyInt:: operator+() const{
	return MyInt(*this);
}

MyInt MyInt:: operator-() const{
	return MyInt((-*this));
}

MyInt operator+(const MyInt &lhs, const MyInt &rhs) {
	return MyInt(lhs.value + rhs.value);
}

MyInt operator-(const MyInt &lhs, const MyInt &rhs) {
	return MyInt(lhs.value - rhs.value);
}

MyInt operator*(const MyInt &lhs, const MyInt &rhs) {
	return MyInt(lhs.value * rhs.value);
}

MyInt operator/(const MyInt &lhs, const MyInt &rhs) {
	return MyInt(lhs.value / rhs.value);
}

MyInt operator%(const MyInt &lhs, const MyInt &rhs) {
	return MyInt(lhs.value % rhs.value);
}

const MyInt& operator++ (MyInt &rhs) {
	rhs = rhs + MyInt((int)1);
	return rhs;
}

const MyInt operator++ (MyInt &rhs, int) {
	MyInt tmp(rhs);
	rhs = rhs + MyInt((int)1);
	return tmp;
}

const MyInt& operator-- (MyInt &rhs) {
	rhs = rhs - MyInt((int)1);
	return rhs;
}

const MyInt operator- (MyInt &rhs, int) {
	MyInt tmp(rhs);
	rhs = rhs - MyInt((int)1);
	return tmp;
}


MyInt & MyInt:: operator = (const MyInt & rhs) {
	if (this == &rhs) {
        return *this;
    }
    value = rhs.value;
	return *this;    
}

MyInt& MyInt:: operator += (const MyInt &rhs) {
	return *this = (*this + rhs);
}

MyInt& MyInt:: operator -= (const MyInt &rhs) {
	return *this = (*this - rhs);
}


bool operator<(const MyInt &lhs, const MyInt &rhs){
	return (lhs.value < rhs.value);
}

bool operator<=(const MyInt &lhs, const MyInt &rhs){
	return (lhs.value <= rhs.value);
}

bool operator>(const MyInt &lhs, const MyInt &rhs){
	return (lhs.value > rhs.value);
}

bool operator>=(const MyInt &lhs, const MyInt &rhs){
	return (lhs.value >= rhs.value);
}

bool operator==(const MyInt &lhs, const MyInt &rhs){
	return (lhs.value == rhs.value);
}

bool operator!=(const MyInt &lhs, const MyInt &rhs){
	return (lhs.value != rhs.value);
}
