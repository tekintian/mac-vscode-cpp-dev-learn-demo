#include <iostream>

using namespace std;

//类的类型参数化 抽象的类
//单个类模板
template <typename T> class A {
public:
  A(T t) { this->t = t; }

  T &getT() { return t; }

protected:
public:
  T t;
};
void main() {
  //模板了中如果使用了构造函数,则遵守以前的类的构造函数的调用规则
  A<int> a(100);
  a.getT();
  cout << a;
  return;
}