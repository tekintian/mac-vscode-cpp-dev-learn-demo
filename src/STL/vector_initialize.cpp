/**
 * @file vector_initialize.cpp
 * @author tekintian (tekintian@gmail.com)
 * @brief 6种容器数据初始化的方式演示, 模板函数打印不同类型容器数据.
 * @version 0.1
 * @date 2021-01-30
 * 
 * @copyright (C)2021  Tekin.cn All Right Reserved.
 */
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 模板函数打印容器数据
template <class T> void print(string const &str, T const &t) {
  cout << "\n------- " << str << " ---------\n";
  for (auto var : t) {
    cout << var << "  ";
  }
  cout << "\n";
}

/** 6中初始化vector容器的方法演示  */
int main(int argc, char **argv) {
  // vector创建
  vector<int> v1;
  // 1. Initializing by pushing values one by one :
  v1.push_back(10);
  v1.push_back(20);
  print("int", v1); // 10  20

  // 2.Initializing like arrays :
  vector<double> v2{2.5, 21.99, 22, 24, 25.8, 26};
  print("double", v2); // 2.5  21.99  22  24  25.8  26

  // 3.Specifying size and initializing all values :
  vector<float> v3(5, 30); // 5个30
  print("float", v3);      // 30  30  30  30  30

  // 4. Initializing from an array :
  string str[] = {"aaa", "bbbb", "cccccc"};
  int n = sizeof(str) / sizeof(str[0]);
  vector<string> v4(str, str + n);
  print("string", v4); // aaa  bbbb  cccccc

  // 5. Initializing from another vector :
    vector<int> v5_f{109,2,30,40,50};
    vector<int> v5{v5_f.begin(), v5_f.end()};
    print("from another vector", v5); // 109  2  30  40  50

    // 6. Initializing all elements with a particular value :
    // fill函数需要头文件  #include <cstdlib>
    vector<int> v6(3); //初始化容器大小
    int value = 8; // 需要填充的值
    fill(v6.begin(), v6.end(), value); // 填充方式初始化
    print("fill", v6);                 // 8  8  8

    return 0;
}