#include <iostream>
#include <string>

using namespace std;

class Person {
    public:
        // 純粋仮想関数を定義することで、抽象クラスを作れる
        // 抽象クラス自体はインスタンス化できないが、派生クラスにメソッドの強制ができる
        virtual void say_hello() = 0;
};

class Warrior :public Person {
    public:
        void say_hello() { cout << "Hello Warrior" << endl; }
};

int main() {
    // Person person1 → これはエラーになる
    Warrior warrior1;
    warrior1.say_hello();
}
