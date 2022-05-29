#include <iostream>

using namespace std;

class CopyConstructor {
  char *s_copy;

public:
  CopyConstructor(const char *str) {
    s_copy = new char[20]; // 动态申请内存
    strcpy(s_copy, str);
  };
  CopyConstructor(const CopyConstructor &str) {
    s_copy = new char[20];
    strcpy(s_copy, str.s_copy);
  };
  void concatenate(const char *str) { strcat(s_copy, str); };
  void display() { std::cout << " message: " << s_copy << std::endl; };
  ~CopyConstructor() { delete[] s_copy; };
};

int main(int argc, char **argv) {
  CopyConstructor c1("Copy");
  CopyConstructor c2 = c1;
  c1.display();
  c2.display();
  c1.concatenate(" constructor ");
  c1.display();
  c2.display();
  return 0;
}