#include "Sort.h"
#include <iostream>
using namespace std;

int main() {

    // create Sort object with 10 random values between 1 and 100, and sort in ascending order
    Sort s1(10, 1, 100);
    cout << "Initial random values: ";
    s1.Print();
    s1.InsertSort();
    cout << "Sorted in ascending order: ";
    s1.Print();
    cout << std::endl;

    Sort s2 = { 5, 10, 2, 8, 1, 5 };
    cout << "Initial values: ";
    s2.Print();
    s2.BubbleSort();
    cout << "Sorted in ascending order: ";
    s2.Print();
    cout << std::endl;

    // create Sort object with 17 random values between 1 and 145, and sort in ascending order
    Sort s3(17, 1, 145);
    cout << "Initial random values: ";
    s3.Print();
    s3.QuickSort();
    cout << "Sorted in ascending order: ";
    s3.Print();
    cout << std::endl;

    return 0;
}