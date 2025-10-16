#include <iostream>

using namespace std;

// 基底クラス Figure
class Figure {
    public:
        virtual void area() = 0; // 面積（純粋仮想関数）
        virtual void around() = 0; // 外周（純粋仮想関数）

        void GetMeasure(){
            area();
            around();
        }
};

// 派生クラス
class Square : public Figure{
    public:
        Square(double s);
        Square(double s, double h);
        void area(){
            cout << "四角形の面積：" << side * height << endl;
        }
        void around() {
            cout << "四角形の外周" << 2 * (side + height) << endl;
        }
    private:
        double side;
        double height;
};

// Squareクラスのコンストラクタ
Square::Square(double s) {
    side = height = s;
}

Square::Square(double s, double h) {
    side = s;
    height = h;
}

// 派生クラスCircle
class Circle : public Figure {
    public:
        Circle(double r);
        void area(){
            cout << "円の面積：" << radius * radius * pi << endl;
        }
        void around(){
            cout << "円の外周：" << 2 * (radius * pi) << endl;
        }
    private:
        const double pi;
        double radius;
};

// Circleコンストラクタ
Circle::Circle(double r):pi(3.14){
    radius = r;
}

int main() {
    Figure *pFig1;
    Figure *pFig2;
    Figure *pFig3;

    Square mysquare1(2.5);
    Square mysquare2(2.3, 3.7);
    Circle mycircle(3.6);

    pFig1 = &mysquare1;
    pFig2 = &mysquare2;
    pFig3 = &mycircle;

    pFig1->GetMeasure();
    pFig2->GetMeasure();
    pFig3->GetMeasure();
}