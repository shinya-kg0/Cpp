#include <iostream>
using namespace std;

// マクロによる定義：あらかじめ定義した規則によって置換する機能
// Cでよく使われる
// #define MAX 256
#define INT 1

// 関数も作成可能
// 三項演算子：(条件) ? (true処理) : (false処理)
#define MAX(a, b) ((a > b) ? a : b)


int main() {
    // cout << "MAX: " << MAX << endl;
    cout << "INT: " << INT << endl;

    int x1 = 5, y1 = 10;

    cout << "input: " << x1 << " " << y1 << endl;
    cout << "MAX: " << MAX(x1, y1) << endl;

}