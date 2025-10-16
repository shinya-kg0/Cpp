#include <iostream>
#include <memory>
#include <cmath>
#include <iomanip>

using namespace std;

constexpr double PI = 3.14159265358979323846;

class Figure {
    public:
        virtual double area() const = 0;
        virtual double around() const = 0;

        void printMeasure() const {
            cout << fixed << setprecision(2);
            cout << "面積：" << area() << "、外周：" << around() << endl;
        }

        // 基底クラスのデストラクタは仮想にしておく
        virtual ~Figure() = default;
};

// finalでこれ以上継承されないことを明示している
class Square final : public Figure {
    public:
        explicit Square(double s) : side_(s), height_(s) {}
        explicit Square(double s, double h) : side_(s), height_(h) {}

        double area() const override {
            return side_ * height_;
        }

        double around() const override {
            return 2.0 * (side_ + height_);
        }

        ~Square() override = default;
    private:
        double side_;
        double height_;
};

class Circle final : public Figure {
    public:
        explicit Circle(double r) : radius_(r) {}

        double area() const override {
            return radius_ * radius_ * PI;
        }
        double around() const override {
            return 2.0 * radius_ * PI;
        }

        ~Circle() override = default;
    private:
        double radius_;
};

int main() {
    // C++では、スマートポインタ (std::unique_ptr) を使用して
    // オブジェクトのメモリ管理を自動化するのが一般的です（RAIIの原則）。

    // Figureの具象クラスオブジェクトをヒープに作成し、unique_ptrで所有
    auto pFig1 = make_unique<Square>(2.5);
    auto pFig2 = make_unique<Square>(2.3, 3.7);
    auto pFig3 = make_unique<Circle>(3.6);

    pFig1->printMeasure();
    pFig2->printMeasure();
    pFig3->printMeasure();

}