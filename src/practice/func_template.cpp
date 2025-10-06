#include <iostream>


// テンプレート化としておくことで型を気にせず渡せる
// template <typename T>
// T add(T a, T b, T c) {
//     T sum = a + b + c;
//     return sum;
// }

// int main() {
//     cout << add(1, 2, 3) << endl;
//     cout << add(1.23, 4.56, 7.89) << endl;
// }

template <typename T>
void show(T& value) {
    cout << "(T&) left: " << value << endl;
}

template <typename T>
void show(T&& value) {
    cout << "(T&&) right: " << value << endl;
}

int main() {
    int i = 100;

    // 
    show(i);
    show(1300);
}

// 関数呼び出し
// show(i); 左辺値（変数）　T&が呼ばれる
// show(1300); 右辺値（数値） T&&が呼ばれる

