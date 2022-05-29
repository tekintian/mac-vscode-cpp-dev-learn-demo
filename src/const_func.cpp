#include <iostream>

using namespace std;

class ConstDemo {
private:
  int id;
  mutable long mobile; // mutable修饰的成员变量在 const函数中可以修改

public:
  ConstDemo() { this->id = 0; };

  ConstDemo(int id, long mobile) {
    this->id = id;
    this->mobile = mobile;
  };
  void setMobileConst(int id, long mobile) const;
  void getInfo() const;
};
void ConstDemo::setMobileConst(int id, long mobile) const {
  //   this->id = id; //不能修改,这个将报错
  this->mobile = mobile;
}

void ConstDemo::getInfo() const { 
    printf("id=%d, mobile=%lu \n", id, mobile); 
}

int main(int argc, char **argv) {
  ConstDemo obj;
  obj.setMobileConst(1, 138888011868);
  obj.getInfo();

  // 常对象
  const ConstDemo obj2(2, 13888888888);
  obj2.getInfo();
  return 0;
}