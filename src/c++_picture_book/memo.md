# サンプル１

- sprintfはC++では非推奨

- 単純な名前や数字などは参照渡しでOK

```c++
void hoge(const string &name) {

}
```

- stringstreamが使い勝手良さそう（汎用性を意識した出力）
  - 型を意識せずにfstringみたいな使い方ができる

- Enum classを使う時はintにキャストする必要がある

```c++
    ss << subname[static_cast<int>(subject)] << ": " << point << "点";
```

ポインタを活用した場合の例

```c++
#include <iostream>
#include <string>
#include <sstream> 
#include <stdexcept> // エラーハンドリングのために追加

using namespace std;

// Studentクラスはシンプルなので、大きな変更は不要
class Student {
    public:
        void SetID(int num) {
            id = num;
        };
        void SetName(const string &name) {
            this->name = name;
        };
        int GetID() const { return id; };
        string GetName() const { return name; };
    private:
        int id;
        string name;
};

enum class Subjects{Math, English, Science};

class Exam {
    public:
        // コンストラクタを削除し、SetInfoで初期化する元のスタイルを維持
        void SetInfo(int id, const string &name, Subjects s, int num);
        int GetPoint() const { return point; };
        string GetResult() const;
        // Studentオブジェクトへのポインタは不要なため、参照でアクセスを維持
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
    
    // enum class の値が配列の範囲外でないか、念のためチェックを強化
    if (static_cast<int>(subject) >= sizeof(subname) / sizeof(subname[0])) {
        throw out_of_range("Invalid subject index.");
    }
    
    stringstream ss;
    ss << subname[static_cast<int>(subject)] << ": " << point << "点";
    return ss.str();
};

// ポインタ（Exam*）ではなく、単一のExamオブジェクトのconst参照（&）で受け取るのが適切
void PrintResult(const Exam &exam) {
    cout << exam.GetStudentName() << endl;
    cout << exam.GetResult() << endl;
};

// 【変更点】ポインタの配列（Exam**）とサイズを受け取るように変更
double GetAvg(Exam **exams, int num) {
    double sum = 0;
    for (int i=0; i < num; i++) {
        // ポインタを通じてメンバーにアクセスするため、アロー演算子 (->) を使用
        if (exams[i] != nullptr) {
            sum += exams[i]->GetPoint();
        } else {
            // nullptrの場合はスキップ（またはエラー処理）
        }
    }
    return sum / num;
};


int main() {
    // 【変更点1】Examオブジェクトをヒープに動的確保し、ポインタの配列で管理する
    const int EXAM_COUNT = 3;
    Exam* exams[EXAM_COUNT]; // Exam* 型の静的配列 (ポインタの配列)

    // new 演算子でヒープメモリにオブジェクトを生成し、ポインタを配列に格納
    exams[0] = new Exam(); 
    exams[1] = new Exam();
    exams[2] = new Exam();

    // アロー演算子 (->) を使ってメンバー関数を呼び出す
    exams[0]->SetInfo(1, "しおり", Subjects::Math, 60);
    exams[1]->SetInfo(1, "しおり", Subjects::English, 75);
    exams[2]->SetInfo(1, "しおり", Subjects::Science, 88);

    // 単一オブジェクトはそのまま参照渡し (ポインタをデリファレンス: *exams[i])
    PrintResult(*exams[0]);
    PrintResult(*exams[1]);
    PrintResult(*exams[2]);
    cout << endl;
    
    // 【変更点2】GetAvg関数に、ポインタの配列の先頭アドレスを渡す
    // examsはExam*型の配列なので、examsの先頭アドレス（Exam**型）を渡す
    cout << "平均：" << GetAvg(exams, EXAM_COUNT) << "点" << endl;

    // 【変更点3】new で確保したメモリは delete で解放する必要がある (これが生ポインタの最大の注意点)
    delete exams[0];
    delete exams[1];
    delete exams[2];
    
    return 0;
}
```

# サンプル2

初期化の方法が色々ある。

クラスの配列を作って、ポインタを使って処理を行う手法

```cpp
    Person *p [] = { &Shiori1, &Shiori2, &Shiori3 };
    
    for (int i=0; i<3; i++) {
        cout << "名前：" << p[i]->GetName() << "年齢：" << p[i]->GetAge() 
            << "電話番号：" << p[i]->GetPhoneNum() << endl;
    }

```

# サンプル3

初期化の方法（継承もあるよ）

```cpp
// クラス定義
class DrinkBox {
    public:
        // コンストラクタ
        DrinkBox(){}
        DrinkBox(const string &str, int n1, int n2)
            : name(str), price(n1), count(n2) {}
        // ...
        string name;
        int price;
        int count;
};

// 継承する時
class AlcholBox : public DrinkBox{
    public:
        AlcholBox(const string &str, int n1, int n2, float f)
            : DrinkBox(str, n1, n2), alcper(f) {}
        // ...
    private:
        float alcper;
};
```

