#include <iostream>
#include <string>

using namespace std;

class Person {
    private:
        int HP = 0;
    public:
        int get_HP() { return HP; };
        void set_HP(int HP) { this->HP = HP; };

    Person(int HP=0) {
        cout << "コンストラクタ" << endl;
        this->HP = HP;
    }

    ~Person() {
        cout << "デストラクタ" << endl;
    }
};

int main() {
    Person person1(100);
    cout << person1.get_HP() << endl;
};