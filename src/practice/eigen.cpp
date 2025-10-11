#include <iostream>
// 密行列用
// 細かいライブラリを含む書き方
#include <Eigen/Dense>

using Eigen::MatrixXd;
using namespace std;
using namespace Eigen;

int main() {
    // 行列の型を定義している
    MatrixXd m(2, 2);
    m(0, 0) = 3;
    m(1, 0) = 2.5;
    m(0, 1) = -1;
    m(1, 1) = m(1, 0) + m(0, 1);
    
    std::cout << m << std::endl;

    // 初期化の方法
    Vector2d v2{1, 2};
    cout << v2 << endl;
    
    Matrix2d m2{ {1.0, 3.4}, {5.6, 3.1}};
    cout << m2 << endl;

    // 宣言して、代入することもできる
    // この方法の方がよく使う
    Matrix2d m2b;
    m2b << 2.4, 6.9, 0.8, -2.9;
    cout << m2b << endl;

    // ゼロ初期化
    VectorXd vxz = VectorXd::Zero(2);
    cout << vxz << endl;

    MatrixXd mxz = MatrixXd::Zero(2, 3);
    cout << mxz << endl;

    // 連続地で初期化も可能（要素数、初期値、終わりの値）
    VectorXd vxz2 = VectorXd::LinSpaced(3, 0, 2);
    cout << vxz2 << endl;
}
