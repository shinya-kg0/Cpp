#include <iostream>
#include <string>

using namespace std;

// class A {
//     public:
//         // オブジェクトと変数の間違いを防ぐ
//         // 初期化はできるが代入はできない
//         explicit A(int);
//         int value;
//         int get_value() const;
// };

// // コンストラクタ
// // 初期化はこの書き方が推奨される
// A::A(int x):value(x) {}

// int A::get_value() const {
//     return value;
// }

// int main() {
//     A a(11);
//     // A a = 12; これはエラー

//     cout << a.get_value() << endl;
// };

// 複数の初期化コードが必要な時

class A {
    public:
        // strや独自クラス、構造体など
        // データをコピーするには大きいものは参照渡しをしたい
        explicit A(int x, const string &s);

        int value;
        string name;

        void print_details() const;
};

A::A(int x, const string &s)
    : value(x), name(s) {};

void A::print_details() const {
    cout << "value: " << value << endl;
    cout << "name: " << name << endl;
};

int main() {
    A a(11, "test obj");

    cout << "\n--- explicit のチェック ---" << endl;
    a.print_details();

};


