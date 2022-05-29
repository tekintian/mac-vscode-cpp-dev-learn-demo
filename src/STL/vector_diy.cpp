/**
 *
 * @file vector_diy.cpp
 * @author tekintian (tekintian@gmail.com)
 * @brief vector存放自定义数据演示
 * @version 0.1
 * @date 2021-02-01
 *
 * @copyright (C)2021  Tekin.cn All Right Reserved.
 *
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Person {
private:
  string name;
  int age;

public:
  Person(string name, int age) : name(name), age(age){};
  void show(void);
};
// Person类方法show 实现
void Person::show(void) {
  std::cout << "name=" << name << " age=" << age << std::endl;
}
// 自定义的for_each数据打印回调函数
void myPrint(Person p) { p.show(); }

int main(int argc, char **argv) {
  Person p1("宋江", 60);
  Person p2("吴用", 50);
  Person p3("李奎", 48);

  // 使用vector存放自定义数据
  vector<Person> v;
  v.push_back(p1);
  v.push_back(p2);
  v.push_back(p3);

  for_each(v.begin(), v.end(), myPrint);

  return 0;
}