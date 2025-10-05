#include <iostream>
#include <vector>

using namespace std;

int main() {
    // vector<型> 変数名(長さ, 初期値)
    vector<int> vec1(3, 1);
    // vector<vector<int>>
    // 変数名(y長さ, vector<型> (長さ, 初期値));
    vector<vector<int>> vec2(3, vector<int>(3, 0));

    for (int i = 0; i < 3; i++ ) {
        for (int j = 0; j < 3; j++ ) {
            vec2.at(i).at(j) = i + j * 3;
        }
    }

    for (int i = 0; i < 3; i++ ) { 
        for (int j = 0; j < 3; j++ ) {
            cout << vec2[j][i] << " ";
        }
        cout << endl;
    }

    vector<vector<int>> vec3 = { {1, 2}, {3, 4}, {5, 6} };
    cout << vec3.size() << endl;
    cout << vec3.at(0).size() << endl;
}