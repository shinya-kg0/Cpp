#include <iostream>
#include <vector>

using namespace std;

int main() {

    // 配列ver
    int arr[5] = { 1, 2, 3, 4, 5 };

    for (int i = 0; i < 5; i++ ) {
        cout << arr[i] << endl;
    };
    cout << endl;

    for (int *i_ptr = &arr[0]; i_ptr != &arr[5]; i_ptr++) {
        cout << *i_ptr << endl;
    };

    // vector ver
    vector<int> v = { 1, 2, 3, 4, 5 };

    for (vector<int>::iterator it = v.begin(); it != v.end(); it++ ) {
        cout << *it << endl;
    }
    cout << endl;

    // autoを使う方が一般的（しかも便利！）
    for (auto it = v.begin(); it != v.end(); it++ ) {
        cout << *it << endl;
    }
    cout << endl;

    // 範囲for文
    // イテレータ：順にアクセスするためのポインタ
    // イテレータは&付きで定義するとポインタではなく通常の変数として扱える！！
    for (auto &it : v) {
        cout << it << endl;
    };
};