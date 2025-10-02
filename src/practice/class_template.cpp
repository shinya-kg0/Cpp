#include <iostream>

using namespace std;


template <typename T>
class xy {
    public:
        T x;
        T y;
};

void show(int x, int y) {
    cout << "int_x: " << x << endl;
    cout << "int_y: " << y << endl;
}

void show(double x, double y) {
    cout << "double_x: " << x << endl;
    cout << "double_y: " << y << endl;
}

int main() {
    xy <int> int_xy{1, 2};
    xy <double> double_xy{1.23, 4.56};

    double_xy.x = -3.21;

    show(int_xy.x, int_xy.y);
    show(double_xy.x, double_xy.y);
}
