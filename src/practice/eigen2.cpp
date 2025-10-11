#include <iostream>
#include <Eigen/Dense>

using namespace Eigen;
using namespace std;

int main() {
    Matrix2d a;
    a << 1.0, 2.0, 3.0, 4.0;

    Matrix2d b;
    b << 1.0, 1.0, 1.0, 1.0;

    cout << a + b << "\n" << endl;
    cout << a - b << "\n" << endl;
    cout << a + 3.0 * b << "\n" << endl;

    a += b;
    cout << a << "\n" << endl;

    a -= b;
    cout << a << "\n" << endl;

    // ノルム：aの大きさ
    cout << a.norm() << "\n" << endl;
    // aの大きさの二乗
    cout << a.squaredNorm() << "\n" << endl;
}