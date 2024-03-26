#pragma once
#define _CRT_SECURE_NO_WARNINGS

class Number {
	char nr[256];
	int baza=10;
public:

	Number(const char* value, int base); // where base is between 2 and 16  
	Number(int value);
	Number(const char*);
	~Number();

	// add operators and copy/move constructor
	bool operator>(Number nr2);
	bool operator<(Number nr2);
	bool operator>=(Number nr2);
	bool operator<=(Number nr2);
	bool operator==(Number nr2);
	friend Number operator+(Number nr1, Number nr2);
	friend Number operator-(Number nr1, Number nr2);
	Number operator--();
	Number operator--(int);
	//void operator=(int);
	char& operator[](int index);
	Number& operator=(int value);
	Number& operator+=(Number n);

	void SwitchBase(int newBase);
	void Print();
	int  GetDigitsCount(); // returns the number of digits for the current number   
	int  GetBase(); // returns the current base
};
