#include "Sort.h"
#include <algorithm>
#include <iostream>
#include <stdarg.h>
#include <functional>
using namespace std;

Sort::Sort(int nr_elemente, int min, int max) {
    n = nr_elemente;
    vect = new int[n];
    if (nr_elemente <= 200)
    {
        srand(time(0));
        for (int i = 0; i < n; i++) {
            vect[i] = rand() % (max - min + 1) + min;
        }
    }
    else cout << "depaseste marimea";
}

Sort::Sort(int nr_elemente, int v[200]) {
    n = nr_elemente;
    vect = new int[n];
    if (nr_elemente <= 200)
    {
        for (int i = 0; i < n; i++)
            vect[i] = v[i];
    }
    else cout << " depaseste marimea";
    
}

Sort::Sort(int nr_elemente, ...) {
    n = nr_elemente;
    vect = new int[n];
    if (nr_elemente <= 200)
    {
        va_list list;
        va_start(list, nr_elemente);
        for (int i = 0; i < nr_elemente; i++) {
            vect[i] = va_arg(list, int);
        }
        va_end(list);
    }
    else cout << "Se depaseste capacitatea";
}

Sort::Sort(char s[200]) {
    n = 0;
    vect = new int[n];
    char* p, * ss = NULL;
    p = strtok_s(s, ",", &ss);
    while (p)
    {
        vect[n] = 0;
        char cpy[100];
        strcpy_s(cpy, p);
        for (int j = 0; j < strlen(cpy); j++)
            vect[n] = vect[n] * 10 + (cpy[j] - '0');
        n++;
        p = strtok_s(NULL, "," ,&ss);
    }
   
}

Sort::Sort(const char* sir)
{
    int v[200]{};
    int nr = 0;
    int count = 0;
    for (int i = 0; i < std::strlen(sir); i++)
    {
        if (sir[i] != ',')
        {
            nr = nr * 10 + (sir[i] - '0');
        }
        else
        {
            v[count++] = nr;
            nr = 0;
        }

    }
    v[count++] = nr;
    vect = new int[count];
    for (int i = 0; i < count; i++)
    {
        vect[i] = v[i];
    }
    n = count;
}

void Sort::BubbleSort() {
    bool ascendent;
    int j,i;
    for ( i = 0; i < n-1; i++) 
    {
        ascendent = false;
        for (j= 0; j < n-i-1; j++) 
        {
            if (vect[j]>vect[j+1])
            {
                swap(vect[j], vect[j + 1]);
                ascendent = true;
            }
        }
        if (ascendent == false)
            break;
    }
}

void Sort::InsertSort() {
    for (int i = 1; i < n; i++) 
    {
        int k = vect[i];
        int j = i-1;
        while (j >=0 && vect[j]>k) 
        {
            vect[j+1] = vect[j];
            j--;
        }
        vect[j + 1] = k;
    }
}

int partitie(int v[], int l, int h)
{
    int x = v[h];
    int i = (l - 1);
    for (int j = l; j <= h - 1; j++)
    {
        if (v[j] <= x)
        {
            i++;
            swap(v[i], v[j]);
        }
    }
    swap(v[i + 1], v[h]);
    return (i + 1);
}

void quicksort(int v[], int l, int h)
{
    if (l < h) {
        int p = partitie(v, l, h);
        quicksort(v, l, p - 1);
        quicksort(v, p + 1, h);
    }
}
void Sort::QuickSort() {
    quicksort(vect, 0, n - 1);
}


void Sort::Print() {
    for (int i = 0; i < n; i++) {
        cout << vect[i] << " ";
    }
    cout << endl;
}

int Sort::GetElementsCount() {
    return n;
}

int Sort::GetElementFromIndex(int index) {
    return vect[index];
}