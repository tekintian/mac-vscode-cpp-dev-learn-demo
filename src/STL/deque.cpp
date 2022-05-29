#include <deque>
#include <iostream>

using namespace std;

int main(int argc, char **argv) {

  deque<int> d1;
  //   d1.push_back(9);
  //   d1.push_back(10);
  //   d1.pop_front();

  //   for (auto var : d1) {
  //     std::cout << "out:" << var << std::endl;
  //   }

  for (size_t i = 1; i <= 10; i++) {
    d1.push_back(i);
  }

    d1.assign(100,random());
  for (deque<int>::iterator it = d1.begin(); it != d1.end(); it++) {
    // 这里的it是指针, *it 是取指针的值
    std::cout << "" << *it << std::endl;
  }

  return 0;
}