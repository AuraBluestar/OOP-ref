#include<iostream>
#include "Math.h"
using namespace std;

int main()
{
	Math m;
	cout << m.Add(1, 3) << endl;//1+3
	cout << m.Add(1, 3, 8) << endl;//1+3+8
	cout << m.Add(1.25, 3.85) << endl;//int(1)+int(3)
	cout << m.Add(1.25, 3.85, 8.16) << endl;//int(1)+int(3)+int(8.16)
	cout << m.Mul(1, 5) << endl;//1*5
	cout << m.Mul(1, 5, 4) << endl;//1*5*4
	cout << m.Mul(1.89, 5.25) << endl;//int(1.89)*int(5.25)
	cout << m.Mul(1.89, 5.25, 4.00) << endl;//int(1.89)*int(5.25)*int(4.00)
	cout << m.Add(3, 1.89, 5.25, 4.00) << endl;
	cout << m.Add("Good ", "job!") << endl;// "Good " + "job!"
	return 0;
}