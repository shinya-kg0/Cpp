#include <iostream>
using namespace std;

int equation(int a, int b);
double equation(double a, double b);

int main() {
    int x = 10;
    int y = 20;

    int z = equation(x, y);

    cout << z << endl;

    double xd = 1.5;
    double yd = 2.5;

    double zd = equation(xd, yd);

    cout << zd << endl;

}

int equation(int a, int b) {
    return 2 * a + b;
}

double equation(double a, double b) {
    return 2 * a + b;
}