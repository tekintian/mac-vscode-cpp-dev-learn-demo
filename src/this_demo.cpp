#include <iostream>
#include <string>

using namespace std;

class ThisDemo {
public:
  ThisDemo();
  ThisDemo &myStr(string str);
};
ThisDemo::ThisDemo() {}
// 返回当前对象 一般使用引用 &
ThisDemo &ThisDemo::myStr(string str) {
  std::cout << str << " ";
  ;
  return *this; // *this代表的是当前调用函数的对象
}

int main(int argc, char **argv) {
  ThisDemo obj;
  obj.myStr("Hello").myStr("World! \n");
  return 0;
}