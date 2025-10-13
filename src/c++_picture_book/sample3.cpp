// C言語っぽい

#include <iostream>
#include <string.h>

using namespace std;

class DrinkBox {
    public:
        // コンストラクタ
        DrinkBox(){}
        DrinkBox(const char *str, int n1, int n2){
            name = new char[strlen(str) + 1];    // 文字数に合わせて動的にメモリを確保
            strcpy(name, str);
            price = n1;
            count = n2;
        }
        // デストラクタ
        ~DrinkBox(){
            delete [] name;    // メモリを解放
            // cout << "デストラクタ呼び出し完了" << endl;
        }

        // 合計金額の計算
        int GetTotalPrice(){
            return count * price;
        }
        // タイトルの表示
        void PrintTitle(){
            cout << "商品名\t単価\t数量\t金額" << endl;
        }
        // 商品データの表示
        void PrintData(){
            cout << name << "\t" << price << "\t" << count << "\t" << GetTotalPrice() << endl;
        }

        char *name;
        int price;
        int count;
};

// DrinkBoxクラスを継承
class AlcholBox : public DrinkBox{
    public:
        AlcholBox(const char *str, int n1, int n2, float f) {
            name = new char[strlen(str) + 1];    // 文字数に合わせて動的にメモリを確保
            strcpy(name, str);
            price = n1;
            count = n2;
            alcper = f;
        }
        // 再定義
        void PrintTitle(){
            cout << "商品名（度数[%]）\t単価\t数量\t金額" << endl;
        }
        // 再定義
        void PrintData(){
            cout << name << "（" << alcper << "）\t" << price << "\t" << count << "\t" << GetTotalPrice() << endl;
        }
    private:
        float alcper;
};

int main() {
    DrinkBox coffee("コーヒー", 200, 3);
    DrinkBox oolongtea("ウーロン茶", 150, 2);
    AlcholBox wine("ワイン", 300, 2, 15.0);

    coffee.PrintTitle();
    coffee.PrintData();

    oolongtea.PrintData();

    wine.PrintTitle();
    wine.PrintData();

    int sum = coffee.GetTotalPrice() + oolongtea.GetTotalPrice() + wine.GetTotalPrice();

    cout << "\n＊＊＊合計金額" << sum << "円＊＊＊" << endl;
}