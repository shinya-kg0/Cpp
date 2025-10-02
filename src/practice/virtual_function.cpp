#include <iostream>
#include <string>

using namespace std;

class Person {
    public:
        // void say_hello() { cout << "Hello Person" << endl; };

        // 仮想関数：virtual変数宣言
        virtual void say_hello() { cout << "Hello Person" << endl; };
};

class Warrior :public Person {
    public:
        void say_hello() { cout << "Hello Warrior" << endl; }
};

int main() { 
    // ポインタ生成（基底・派生）
    Person *personPtr1;
    Warrior *warriorPtr1;

    // オブジェクト生成（基底・派生）
    Person person1;
    Warrior warrior1;

    warrior1.say_hello();

    // 基底ポインタ・基底オブジェクト
    personPtr1 = &person1;
    personPtr1->say_hello();

    // 基底ポインタ・派生オブジェクト
    // 注意！：仮装関数化してなかったら基底のメソッドが呼ばれる
    // 仮想関数化することで、基底ポインタ・派生オブジェクトで派生側のメソッドが呼べる！
    personPtr1 = &warrior1;
    personPtr1->say_hello();

    // 名前空間を使うことで基底ポインタ・派生オブジェクトでも基底側のメソッドが呼べる！
    personPtr1->Person::say_hello();
    // 派生ポインタ・派生オブジェクト
    // warriorPtr1 = &warrior1;
    // warriorPtr1->say_hello();
}