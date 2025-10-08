# 環境構築

MacOSでC++17を使うという前提

## コンパイラの準備

```bash
xcode-select --install

clang++ --version
```

## Homebrewからも準備

```bash
brew install gcc

g++-15 --version   # (インストールされたバージョンで変わる)
```

## VSCode拡張を導入

- C/C++ (ms-vscode.cpptools). 
  → IntelliSense、デバッグ、コード補完
- CMake Tools. 
  → プロジェクトが大きくなると必須
- CodeLLDB. 
  → デバッグ用（LLDBベース）

## Hello World

```c++
// hello.cpp
#include <iostream>
using namespace std;

int main() {
    cout << "Hello, Modern C++!" << endl;
    return 0;
}
```

ビルド

`-o`はアウトプットファイルを表す。

```bash
clang++ -std=c++17 hello.cpp -o hello
./hello
```

## CMake環境

`CMakeLists.txt`に設定などを書いてビルドの準備をする。

```cmake
cmake_minimum_required(VERSION 3.16)
project(HelloModernCXX LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(hello hello.cpp)
```

```bash
# ビルドはディレクトリを分けたい
mkdir build && cd build
# CMakeLists.txtを読み込むために親ディレクトリに移動
cmake ..
# ビルドコマンド
make 
# 実行コマンド
./hello
```

# ポインタの概念

- 重要ポイント
  - 通常は値渡し（コピーが渡される）
  - 参照渡しはポインタ（アドレス）を渡す
    - こうすることで、値を直接操作できる！
    - 不要なコピーをしなくていいのでメモリの節約！

![](images/pointer.png)

[参考](https://www.youtube.com/watch?v=HJ-R_c_jazc&list=PLcuLcFhI8wDCpZlr2J-MY5gHECi6RBn9o&index=11)


## 変数との違い

- 一般的な変数
  - `a`：値
  - `&a`：アドレス

- 構造体のポインタ
  - ポインタはアドレスを管理する
  - `*`をつければ値を参照する
  - `a_ptr`：アドレス
  - `*a_ptr`：値

## 使い方

- ポインタにアドレスを渡す
  - これによって`&a`と`a_ptr`が同じ部分を参照

- 構造体のポインタないの変数参照
  - `(*ptr).name`の代わりにアロー演算子（`ptr->x`）を使う


- ポインタだけ宣言しておいて、後で`malloc`でメモリを確保する
  - こうすると動的にメモリの確保ができる！

- 関数にも構造体ごと渡せるので、引数がスッキリする
- 構造体を引数とする関数
  - 関数内で構造体を編集したい時は「構造体のポインタ」を渡す（`*a_ptr`）
  - `void 関数名 (struct 型 ポインタ) {}`
- 関数にポインタを渡したい時は、「構造体のアドレス」を渡す（`&a`）



# クラス

- 中にクラス変数やメソッドを定義できる
  - privateとpublicがある
  - 基本的にはprivateで変更したくない（気軽に触って欲しくない変数を定義）
  - publicにgetter, setterを用意しておく
  - メンバ変数にアクセスや変更をしたい時は、関数を通して行う

## コンストラクタとデストラクタ

public内に関数名のようにクラス名を記述すれば良い

継承している場合は、基底クラスのコンストラクタから呼ばれ、派生クラスのコンストラクタが呼ばれる。

デストラクタはmain関数が終わった後メモリを解放するために呼ばれる。

順番は逆になって派生デストラクタ→基底デストラクタとなる


# vector

## 要素へのアクセス方法

- i行j列にアクセスしたい
  1. `変数名.at(i).at(j)`
  2. `変数名[j][i]`

## サイズ取得

- `size()`：縦の長さ
- `at(0).size()`：横の長さ



# プリプロセッサ

中心的な処理（main関数など）の前処理を行う部分

例）`#include`, `using namespace`, `#define`など

- コンパイル時に実行される
  - 実行時の処理に含まれない
  - 入力ファイルで処理を変えられない

- Cでよく使われる
  - C++は`const int xxx`の方が推奨される

- マクロ定義では関数も使用可能！
  - 三項演算子と組み合わせることも多い
  - `三項演算子：(条件) ? (true処理) : (false処理)`

## ifdef/ifndef

プリプロセッサでif文が使える！

→ PC内の設定に応じて処理を変えることができる！（PCによってメモリが違うなど、、、）

```c++
#if 条件
  処理
#else
  処理
#endif
```

- `ifdef`：もし定義されていたら処理を行う
  - メリットとしては、設定し忘れた変数を補完できる。

```c++
#ifdef 定数名
  処理
#else
  処理
#endif

#ifdef MAX
#else
  #define MAX 128
#endif
```

- `ifndef`：もし定義されていなかったら、処理を行う

```c++
#ifndef 定数名
  処理
#else
  処理
#endif

#ifdef MAX
  #define MAX 128
#endif
```

## include

他のファイルを読み込む

1. `#include <xxx.h>`
   1. パスが通っているところから`xxx.h`を探してくれる→ ライブラリで使う
2. `#include "xxx.h"`
   1. 同じディレクトリを探した後に、パスが通っているところを探す→ 自作ヘッダ利用時に使用


# Eigen

サードパーティ製なので、ライブラリの配置をする必要がある。

公式ページからzipファイルをとってきて、所定の位置に配置。  
makefileなどに設定する。

ライブラリが多くなってくるとMakefileを使った方がよい。

簡易版としてhomebrewを使う。

## 環境構築

```bash
$brew install eigen

$brew list eigen

/opt/homebrew/Cellar/eigen/3.4.1/include/eigen3/ (530 files)
/opt/homebrew/Cellar/eigen/3.4.1/sbom.spdx.json
/opt/homebrew/Cellar/eigen/3.4.1/share/eigen3/ (4 files)
/opt/homebrew/Cellar/eigen/3.4.1/share/pkgconfig/eigen3.pc
```

配置されたパスをコンパイル時に渡すことで利用可能

```bash
clang++ -std=c++17 eigen.cpp -o eigen -I /opt/homebrew/Cellar/eigen/3.4.1/include/eigen3
```

## 型の種類

### ベクトル

`Vector<次元><型> 変数名;`

- Vector3i: 3次元のベクトル（int）
- Vector3f: float
- Vector3d: double（よく使う）

- Vector2d: 2要素
- Vector3d: 3要素
- Vector4d: 4要素

### 行列

`Metrix<次元><型> 変数名;`

- Matrix2d m2: 2x2行列
- Matrix3d m3: 3x3
- Matrix4d m4: 4x4

### 無次元行列

宣言時の要素数で行列サイズを決定する  
可読性を考えると上の書き方の方がいい時もある

- VectorXd v(5): 5要素
- MetrixXd m(10,10); 10x10行列


## サイズを見たい時

- 行数：`変数.rows()`
- 列数：`変数.cols()`
- 要素数：`変数.size()`
- リサイズしたい：`変数.resize(要素数)`

## 便利機能

- ランダムな値で初期化：`Matrix::Random(サイズ)`
- 転置行列：`変数.transpose()`
- 最大値：`.maxCoeff()`
- 最小値：`.minCoeff()`
- 合計：`.sum()`
- 平均値：`.mean()`

## 行列計算

逆行列などは大変→ Eigenを活用（高速化や並列処理で活躍！）

- 行列計算には2つある
  - 直接法  
    - 直接、逆行列を求めにいく。
    - さまざまなメソッドが存在するので場合によって使い分ける。
  - 反復法
    - 疎行列に適している

- Matrixは行列同士の演算は内積的に計算をする
- Arrayを使うことで、行列同士の計算を要素同士で行える。

```c++
// ベクトル
ArrayXd a(3);
// 行列
ArrayXXd b(2,2);
```


