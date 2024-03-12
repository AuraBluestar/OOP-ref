#include "Math.h"
#include <iostream>
#include <cstdarg>
using namespace std;

int Math::Add(int x, int y)
{
    return (x+y);
}

int Math::Add(int x, int y, int z)
{
    return (x+y+z);
}

int Math::Add(double x, double y)
{
    int s = int(x) + int(y);
    return s;
}

int Math::Add(double x, double y, double z)
{
    int s = int(x) + int(y) + int(z);
    return s;
}

int Math::Mul(int x, int y)
{
    return x*y;
}

int Math::Mul(int x, int y, int z)
{
    return x*y*z;
}

int Math::Mul(double x, double y)
{
    int s = int(x) * int(y);
    return s;
}

int Math::Mul(double x, double y, double z)
{
    int s = int(x) * int(y) * int(z);
    return s;
}

int Math::Add(int count, ...)
{
    double s = 0;
    va_list args;
    va_start(args, count);;
    for (int i = 0; i < count; i++) 
    {
            double x = va_arg(args, double);
            s = Add(s,x);
    }
    va_end(args);
    return int(s);
}

char* Math::Add(const char* str1, const char* str2)
{
    char str[9999] = { };
    if (str1 == nullptr || str2 == nullptr)
        return nullptr;
    else 
    {
        if(strlen(str1)+strlen(str2)+1>9999)
            return nullptr;
        strcpy_s(str, str1);
        strcat_s(str, str2);
    }
    char* sir = str;
    return sir;
}
