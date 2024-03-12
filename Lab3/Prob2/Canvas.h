#pragma once
#include <iostream>
using namespace std;
class Canvas {
private: 
    int value, height=0, length=0;
    char array[1000][1000] = { };
public:
    // contructor will call the clear method
    Canvas(int lines, int columns);

    //set the character at the position x and y to value
    void set_pixel(int x, int y, char value);

    // tuples of x, y, value
    void set_pixels(int count, ...);

    void clear();
    void print() const;
};

