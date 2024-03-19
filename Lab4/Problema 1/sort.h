#pragma once

#include <vector>
#include <string>

class Sort {
private:
    int n;
    int vect[200]{};

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
