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