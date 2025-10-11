#include <iostream>
#include <Eigen/Dense>
#include <Eigen/IterativeLinearSolvers>

using namespace Eigen;
using namespace std;

int main() {
    Matrix3d A;
    Vector3d b;

    A << 1,2,3,4,5,6,7,8,10;
    b << 3,3,4;

    // 直接法を使って逆行列を作っている
    Vector3d x = A.colPivHouseholderQr().solve(b);

    cout << x << endl;
    cout << "relative_error: " << (A * x - b).norm() / b.norm() << endl; 

    cout << endl;

    BiCGSTAB<MatrixXd> bicg;

    bicg.compute(A);
    x = bicg.solve(b);

    cout << x << endl;
    cout << "relative_error: " << (A * x - b).norm() / b.norm() << endl; 
}