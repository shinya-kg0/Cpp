#include <iostream>
#include <string>

using namespace std;

class A {
    private:
        int value = 0;
    public:
        int get_value() const;
        void set_value(int value);
};

void A::set_value(int value) {
    this->value = value;
};

int A::get_value() const {
    return value;
};

int main() {
    A a;

    a.set_value(123);

    cout << a.get_value() << endl;
};



