#include <iostream>

using namespace std;

struct A {
    int num;
};

struct B {
    int num;
};

int main() {
    struct A a;
    a.num = 1;

    struct A* a_ptr = &a;
    // a_ptr = &a;

    // 値だと*をつければ取得できるけど、構造体、クラスだとアロー演算子を使う！
    cout << a_ptr->num << endl;

    struct B b;
    b.num = 2;

    // 先にポインタの宣言
    struct B* b_ptr;
    // メモリの確保
    b_ptr = (B*)malloc(sizeof(B));

    if (b_ptr != NULL) {
        // 構造体ごとコピーして値をポインタに渡している
        *b_ptr = b;

        cout << b_ptr->num << endl;
    }
};


