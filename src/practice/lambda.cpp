#include <iostream>

using namespace std;

int main() {
    // autoは型推論してくれる
    // 処理だけする関数
    auto func1 = []() { cout << "Hello" << endl; };
    func1();

    // 一度処理だけする関数
    // 引数で関数を渡したい時などで便利！
    // []() { cout << "Hello" << endl; };

    // 引数あり関数
    auto func2 = [](auto x) { cout << x << endl; };
    func2(100);
    func2("hogehoge");

    // 返り値あり関数
    // 返り値の値が自明なら自明なら->intは必要なくreturnだけしてもOK
    auto func3 = []()->int { return 100; };
    cout << func3() << endl;

    // テンプレートと同じような使い方もできる！
    auto func4 = [](auto x) { auto y = x * 2; return y; };
    cout << func4(100) << endl;

    auto a = 10;
    auto b = 10;

    // [=]：コピーキャプチャ
    // 関数外の変数を使用できる
    // ただし、変更はできない
    auto func5 = [=]() { cout << a << " " << b << endl; };
    func5();

    // [=]：コピーキャプチャ mutable
    // 変更可能だが、関数外には反映されない
    auto func5_2 = [=]() mutable { a += 10; cout << a << " " << b << endl; };
    func5_2();

    // [&]：リファレンスキャプチャ
    // 関数外の変数を編集できる！
    auto func6 = [&]() { a+=10; b+=10;};
    func6();
    cout << a << " " << b << endl;
}