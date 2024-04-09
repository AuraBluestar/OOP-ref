#include <iostream>
using namespace std;

int operator"" _Kelvin(long long unsigned k) {
    cout << (k - 273.15);
    return (k - 273.15);
}

int operator"" _Fahrenheit(long long unsigned f) {
    int x;
    x = f - 32;
    cout << (x / 1.8);
    return (x / 1.8);
}


int main() {

    float a = 300_Kelvin;
    cout << endl;
    float b = 120_Fahrenheit;
    return 0;
}
