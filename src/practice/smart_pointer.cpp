// コンストラクタでメモリを確保して
// デストラクタでメモリを解放するのがスタンダード

// スマートポインタを使うと楽にメモリ管理ができる！
// メモリリークを防げる！

#include <iostream>
#include <string>
// スマートポインタにはmemoryが必要
#include <memory>
#include <utility>

using namespace std;

class A {
public:
    A() { cout << "コンストラクタ" << endl; }
    ~A() { cout << "デストラクタ" << endl; }
};

unique_ptr<A> allocate() {
    cout << "allocate()" << endl;
    // new演算子でコンストラクタを呼ぶ＋メモリ確保
    unique_ptr<A> ptr{ new A{} };
    // メモリ領域をreturnしているイメージ
    // uniqueポインタは所有者が1人、ふつうにreturnするとコピーが渡されるのでエラー
    // moveを使うことで所有権を移動している
    return std::move(ptr);
};

int main() {
    {
        // この時点では空のポインタ
        unique_ptr<A> ptr;
        cout << "関数呼び出し" << endl;
        ptr = allocate();
        cout << "関数呼び出し後" << endl;
    }
    cout << "スコープ外" << endl;
};
