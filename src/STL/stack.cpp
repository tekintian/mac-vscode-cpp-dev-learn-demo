#include <iostream>
#include <stack>

using namespace std;

int main(int argc, char **argv) {
  // stack栈容器 是标准的 FILO 先进后出的数据结构,  没有遍历功能, 没有迭代器
  stack<int> s;
  for (size_t i = 0; i < 10; i++) {
    s.push(i + 1);
  }

  std::cout << "stack top:" << s.top() << std::endl;

  // 输出栈内的数据
  while (!s.empty()) {
    //访问最顶端的元素
    std::cout << s.top() << std::endl;
    //出栈
    s.pop();
  }

  return 0;
}