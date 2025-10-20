#include <iostream>
#include <vector>
#include <string>
#include <numeric> // std::accumulate のために必要
#include <cstdio>  // printfの代わりにstd::coutを使う

class Ringo {
    public:
        enum class ColorIndex { Red, Green, Yellow };
        ColorIndex color;
        double weight;
        std::string kind;

        Ringo() : color{ColorIndex::Red}, weight{320.0}, kind{"fuji"} {}

        Ringo(ColorIndex c, double w, const std::string &k)
            : color{c}, weight{w}, kind{k} {}

        const std::string GetColorName() const {
            switch (color)
            {
            case ColorIndex::Red: return "Red";
            case ColorIndex::Green: return "Green";
            case ColorIndex::Yellow: return "Yellow";
            default: return "unknown";
            }
        }
        void PrintData() const {
            std::cout << "色：" << GetColorName()
                    << "重さ：" << weight << "g"
                    << "品種：" << kind << std::endl;
        }
        double GetWeight() const { return weight; }
};

class RingoBox {
    public:
        RingoBox() = default;

        bool Add(const Ringo &r);
        bool Del(size_t index);

        void Empty() { ringo.clear(); }
        size_t GetTotalNum() const { return ringo.size(); }
        double GetTotalWeight() const;
        void PrintData() const;

    private:
        std::vector<Ringo> ringo;
        static constexpr size_t MaxRingo = 40;
};

bool RingoBox::Add(const Ringo &r) {
    if (ringo.size() >= MaxRingo) return false;
    ringo.push_back(r);
    return true;
}

bool RingoBox::Del(size_t index) {
    if (index == 0 || index > ringo.size()) return false;
    ringo.erase(ringo.begin() + index - 1);
    return true;
}

double RingoBox::GetTotalWeight() const {
    // ラムダ式＋アルゴリズムを使って簡潔に
    return std::accumulate(ringo.begin(), ringo.end(), 0.0,
        [](double sum, const Ringo &r){
            return sum + r.GetWeight();
        }
    );
}

void RingoBox::PrintData() const {
    for (const auto &r: ringo) {
        r.PrintData();
    }

    std::cout << GetTotalNum() << "個のリンゴがあります。" << std::endl;
    std::cout << "総重量：" << GetTotalWeight() << "g" << std::endl;
}

int main() {
    // constexpr: コンパイル時の定数
    static constexpr size_t init_num = 4;

    Ringo myringo[] {
        {Ringo::ColorIndex::Red, 316.2, "ふじ"},
        {Ringo::ColorIndex::Green, 352.1, "王林"},
        {Ringo::ColorIndex::Red, 341.8, "つがる"},
        {Ringo::ColorIndex::Yellow, 320.7, "ゴールデンデリシャス"}
    };

    RingoBox myRingoBox;

    for (size_t i=0; i < init_num; ++i) {
        if (myRingoBox.Add(myringo[i])) {
            std::cout << "1個追加" << std::endl;
        }
    }
    if (myRingoBox.Del(2)) {
        std::cout << "2番目のりんごを削除" << std::endl;
    }
    std::cout << "\n--- りんごボックスの内容 ---" << std::endl;
    myRingoBox.PrintData();
}