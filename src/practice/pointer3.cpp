#include <iostream>

using namespace std;

struct A {
    int num;
};

struct B {
    int num;
};

void func(struct A* a_ptr) {
    cout << a_ptr->num << endl;
};

int main() {
    struct A a;
    a.num = 1;

    func(&a);

    // 構造体のポインタを生成
    struct B* b_ptr;
    // メモリの確保
    b_ptr = (B*)malloc(sizeof(B));

    if (b_ptr != NULL) {
        b_ptr->num = 2;
    }

    // 関数にポインタ渡ししたい時は、構造体のアドレスを渡す
    func(b_ptr);
};


