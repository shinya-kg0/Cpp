#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> v;
    cout << "入力（0以下で終了）：" << endl;
    while (true) {
        int input_val;
        cin >> input_val;

        if (input_val <= 0) break;

        v.push_back(input_val);
    };

    // vector独自の参照するための型がある
    for (vector<int>::size_type i = 0; i < v.size(); i++) {
        cout << "x[" << i << "]: " << v[i] << endl;
    }


    // 他の初期化方法

    vector<int> v1;
    vector<int> v2(5);
    // 初期値を明示しておいた方が無難
    // -1など入れておいてもデバックしやすい
    vector<int> v3(5, 0);
    vector<int> v4{ 1, 2, 3, 4, 5 };
    vector<int> v5 = { 1, 2, 3, 4, 5 };

    // ベクトルのコピー
    vector<int> x1{v4};
    vector<int> x2 = v4;

    // 型推論でのautoは便利！
    for (auto i = 0; i < 5; i++ ) {
        // cout << v1[i] << endl;
        cout << v2[i] << endl;
        cout << v3[i] << endl;
        cout << v4[i] << endl;
        cout << v5[i] << endl;
    }
}