#pragma once

#include <vector>
#include <string>

class Sort {
private:
    int n;
    int vect[200];

public:
    Sort(int nr_elemente, int min, int max);
    Sort(int nr_elemente, int v[200]);
    Sort(int nr_elemente, ...);
    Sort(char s[200]);
    Sort(const char* sir);

    void InsertSort();
    void QuickSort();
    void BubbleSort();
    void Print();
    int GetElementsCount();
    int GetElementFromIndex(int index);
};
/*add several constructors that will allow the following:

1. create the list that needs to be sorted out of random values within a specific interval (min, max). 
The constructor will receive 3 parameters (the number of elements in the list, minimum value, maximum value).

2. create the list that needs to be sorted from an initialization list

3. create the list that needs to be sorted from an existing vector 
(the constructor will have two parameters - one being the vector, the other one being the number of elements from the vector)

4. create the list that needs to be sorted using variadic parameters (use va_args for this)

5. create the list that needs to be sorted from a string (e.g. "10,40,100,5,70" -> 
each number is separated from the rest of the number with a comma). 
It is assumed that the string is correctly written (no space, only numerical characters and commas) */