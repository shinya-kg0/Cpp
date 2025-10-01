#include <iostream>
#include <string>

using namespace std;

class Person {
    private:
        int HP = 0;
        int MP = 0;
        
    public:
        int get_HP() { return HP; };
        void set_HP(int hp) { HP = hp; };

        int get_MP() { return MP; } const;
        void set_MP(int mp){ MP = mp; };
};

int main() {
    Person person1;

    person1.set_HP(100);
    person1.set_MP(50);

    cout << person1.get_HP() << endl;
    cout << person1.get_MP() << endl;

}