#include <iostream>
#include <string>
#include <sstream> 

using namespace std;

class Student {
    public:
        void SetID(int num) {
            id = num;
        };
        void SetName(const string &name) {
            this->name = name;
        };
        int GetID() { return id; };
        string GetName() const { return name; };
    private:
        int id;
        string name;
};

enum class Subjects{Math, English, Science};

class Exam {
    public:
        void SetInfo(int id, const string &name, Subjects s, int num);
        int GetPoint() const { return point; };
        string GetResult() const;
        string GetStudentName() const { return student.GetName(); }
    private:
        Student student;
        Subjects subject;
        int point;
};

void Exam::SetInfo(int id, const string &name, Subjects s, int num) {
    student.SetID(id);
    student.SetName(name);
    subject = s;
    point = num;
}

string Exam::GetResult() const {
    const string subname[] = {"数学", "英語", "理科"};
    stringstream ss;
    ss << subname[static_cast<int>(subject)] << ": " << point << "点";
    return ss.str();
};

void PrintResult(const Exam &exam) {
    cout << exam.GetStudentName() << endl;
    cout << exam.GetResult() << endl;
};

double GetAvg(const Exam *exam, int num) {
    double sum = 0;
    for (int i=0; i < num; i++) {
        sum += exam[i].GetPoint();
    }
    return sum / num;
};


int main() {
    Exam exam[3];
    exam[0].SetInfo(1, "しおり", Subjects::Math, 60);
    exam[1].SetInfo(1, "しおり", Subjects::English, 75);
    exam[2].SetInfo(1, "しおり", Subjects::Science, 88);

    PrintResult(exam[0]);
    PrintResult(exam[1]);
    PrintResult(exam[2]);
    cout << endl;
    cout << "平均：" << GetAvg(exam, 3) << "点" << endl;
    return 0;
}
