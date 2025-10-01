#include <iostream>
#include <string>

using namespace std;

struct Strc {
    int HP = 0;
    int MP = 0;
    int ATK = 0;
};

int main () {
    Strc person1;

    person1 = {100, 50, 10};
    person1.MP = 300;

    cout << person1.HP << endl;
    cout << person1.MP << endl;
    cout << person1.ATK << endl;

    return 0;
}
