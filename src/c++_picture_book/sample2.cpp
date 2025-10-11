#include <iostream>
#include <string>

using namespace std;

class Person {
    public:
        Person();
        Person(const string &name);
        Person(const string &name, int age, const string phonenum);
        Person(const Person &person);
        ~Person(){
            // if(name != NULL) delete [] name;
        }

        void init(const string &name, int age, const string &phonenum);
        void SetName(const string &name) {this->name = name;}
        void SetAge(const int age) {this->age = age;}
        void SetNum(const string &phonenum) {this->phonenum = phonenum;}
        string GetName() {return name;}
        int GetAge(){return age;}
        string GetPhoneNum() {return phonenum;}
    private:
        string name;
        int age;
        string phonenum;
};

void Person::init(const string &name, int age, const string &phonenum) {
    this->name = name;
    this->age = age;
    this->phonenum = phonenum;
}

Person::Person() {
    name = "";
    age = 0;
    phonenum = "";
};

Person::Person(const string &name) {
    init(name, 0, "");
};

Person::Person(const string &name, int age, const string phonenum) {
    init(name, age, phonenum);
}

Person::Person(const Person &psn) {
    init(psn.name, psn.age, psn.phonenum);
}


int main() {
    Person Shiori1("しおりお嬢さん");

    cout << Shiori1.GetName() << endl;
    Shiori1.SetAge(20);
    Shiori1.SetNum("123-4567-890");

    Person Shiori2("しおり先生", 30, "001-0023-0045");

    Person Shiori3(Shiori2);
    Shiori3.SetName("しおり兄貴");
    Shiori3.SetAge(24);

    Person *p [] = { &Shiori1, &Shiori2, &Shiori3 };
    
    for (int i=0; i<3; i++) {
        cout << "名前：" << p[i]->GetName() << "年齢：" << p[i]->GetAge() 
            << "電話番号：" << p[i]->GetPhoneNum() << endl;
    }

    

}