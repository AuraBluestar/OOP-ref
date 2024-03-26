#include "Number.h"
#include <cstddef>
#include<string>
#include <sstream>
#include <string.h>
#include <iostream>
#define _CRT_SECURE_NO_WARNINGS

Number::Number(const char* value, int base)
{
	int i;
	for (i = 0; *(value + i); i++)
		nr[i] = *(value + i);
	nr[i] = NULL;
	baza = base;
}

Number::Number(const char* value)
{
	int i;
	for (i = 0; *(value + i); i++)
		nr[i] = *(value + i);
	nr[i] = NULL;
}


Number::~Number()
{
	baza = 0;
	strcpy(nr, "0");
}

int Number::GetBase()
{
	return baza;
}

int Number::GetDigitsCount()
{
	return strlen(nr);
}

Number& Number::operator=(int value)
{
	int baza = this->baza;

	std::string numar = std::to_string(value);
	Number a(numar.c_str(), 10);	
	a.SwitchBase(baza);
	strcpy(this->nr, a.nr);
	a.~Number();
	return *this;
}

Number& Number::operator+=(Number n)
{
	Number a = *this + n;
	strcpy(this->nr, a.nr);
	a.~Number();
	return *this;
}

void Number::Print()
{
	std::cout <<nr<<std::endl;
}

int value(char c)
{
	if (c >= '0' && c <= '9')
		return (int)c - '0';
	return c - 'A' + 10;
}

char character(int x)
{
	if (x >= 0 && x <= 9)
		return x + '0';
	return x - 10 + 'A';
}


int convert_to_deci(char s[256], int base)
{
	int exponent = 0;
	int deci_number = 0;
	for (int i = strlen(s) - 1; i >= 0; i--)
	{
		deci_number += value(s[i]) * pow(base, exponent);
		exponent++;
	}
	return deci_number;
}

char* convert_from_deci(int x, int base)
{
	int k = 0;
	char* new_number = (char*)malloc(256);

	while (x != 0 && base!=0)
	{
		new_number[k++] = character(x % base);
		x = x / base;
	}
	if (k == 0) 
		new_number[k++] = '0';
	new_number[k] = '\0';

	_strrev(new_number);
	return new_number;
}

void Number::SwitchBase(int newBase)
{
	int a = convert_to_deci(nr, baza);
	strcpy_s(nr, convert_from_deci(a, newBase));
	baza = newBase;
}

Number::Number(int value)
{
	baza = 10;
	std::string numar = std::to_string(value);
	strcpy(this->nr, numar.c_str());
}

bool Number::operator>(Number numar2)
{
	int baza = std::max(this->baza, numar2.baza);
	int nr1 = convert_to_deci(this->nr, baza);
	int nr2 = convert_to_deci(numar2.nr, baza);
	if (nr1 > nr2) return true;
	return false;
}

bool Number::operator<(Number numar2)
{
	int nr1 = convert_to_deci(nr, baza);
	int nr2 = convert_to_deci(numar2.nr, numar2.baza);
	if (nr1 < nr2) return true;
	return false;
}

bool Number::operator>=(Number numar2)
{
	int nr1 = convert_to_deci(nr, baza);
	int nr2 = convert_to_deci(numar2.nr, numar2.baza);
	if (nr1 >= nr2) return true;
	return false;
}

bool Number::operator<=(Number numar2)
{
	int nr1 = convert_to_deci(nr, baza);
	int nr2 = convert_to_deci(numar2.nr, numar2.baza);
	if (nr1 <= nr2) return true;
	return false;
}

bool Number::operator==(Number numar2)
{
	int nr1 = convert_to_deci(nr, baza);
	int nr2 = convert_to_deci(numar2.nr, numar2.baza);
	if (nr1 == nr2) return true;
	return false;
}

Number operator+(Number nr1, Number nr2)
{
	int baza = std::max(nr1.GetBase(), nr2.GetBase());
	int x = convert_to_deci(nr1.nr, nr1.GetBase());
	int y = convert_to_deci(nr2.nr, nr2.GetBase());
	int result = x + y;
	std::string valoare = std::to_string(result);
	Number z(valoare.c_str(), baza);
	return z;
}

Number operator-(Number nr1, Number nr2)
{
	int baza = std::max(nr1.GetBase(), nr2.GetBase());
	int x = convert_to_deci(nr1.nr, nr1.GetBase());
	int y = convert_to_deci(nr2.nr, nr2.GetBase());
	int result = x - y;
	std::string valoare = std::to_string(result);
	Number z(valoare.c_str(), baza);
	return z;
}

Number Number::operator--()
{
	char numar[20] = {};
		for (int i = 1; i < strlen(nr); i++) 
		{
			numar[i - 1] = nr[i];
		}
	strcpy(nr, numar);
	return *this;
}

Number Number::operator--(int) 
{
	char numar[20] = {};
	for (int i = 0; i < strlen(nr)-1; i++)
	{
		numar[i] = nr[i];
	}
	strcpy(nr, numar);
	return *this;
}

char& Number::operator[](int index)
{
	int digitsCount = this->GetDigitsCount();
	if (index >= 0 && index < digitsCount) {
		return nr[index];
	}
	else {
		static char nullChar = '\0'; // Caracter nul static
		return nullChar;
	}
}

