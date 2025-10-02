#include <iostream>
using namespace std;

template <class T>
T equation(T a=0, T b=0);

int main () {
    int x = 10;
    int y = 20;

    int z = equation(x, y);

    cout << z << endl;

    double xd = 1.5;
    // double yd = 2.5;

    double zd = equation(xd);

    cout << zd << endl;
}

template <class T>
T equation(T a, T b) {
    return 2 * a + b;
}