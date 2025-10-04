#include <iostream>
#include <string>

using namespace std;

void sq(int* x, int* y);

int main() {
    int x = 10;

    cout << &x << endl;

    int* xPtr;
    xPtr = &x;

    cout << "間接参照演算子を使うと中身がわかるよ：" << *xPtr << endl;
    cout << "アドレスが入っているよ：" << xPtr << endl;
    
    int y = 20;

    int *yPtr = &y;

    cout << "計算前：" << *yPtr << endl;

    sq(xPtr, yPtr);

    cout << "計算前：" << *yPtr << endl;
}

void sq(int* x, int* y) {
    *y = *x * *x;
};
