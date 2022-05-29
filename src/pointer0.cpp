#include <iostream>

using namespace std;

void test(int *p1) {
  // 给指针p1赋值 888
  //   int a = 888;
  //   p1 = &a;

  *p1 = *p1 + 100 - 199; // *p1 指向的是值,如果在 *p前带类型就是声明指针
}

int main(int argc, char **argv) {
  int *p1 = NULL; // 定义一个int类型的指针 p1
  int p = 999;    // 定义int变量p并赋值为999
  p1 = &p;        // 将p的地址赋值给指针p1
  printf("*p1=%d, p1=%p, &p1=%p, &(*p1)=%p, p=%d, &p=%p \n", *p1, p1, &p1,
         &(*p1), p, &p);
  // *p1 = 999, p1 = 0x7ffee4763f84, &p1 = 0x7ffee4763f88, &(*p1)
  // =0x7ffee4763f84, p= 999, &p = 0x7ffee4763f84

  test(p1);

  printf("*p1=%d, p1=%p, &p1=%p, &(*p1)=%p, p=%d, &p=%p \n", *p1, p1, &p1,
         &(*p1), p, &p);
  //*p1=888, p1=0x7ffee6f1af84, &p1=0x7ffee6f1af88, &(*p1)=0x7ffee6f1af84,
  // p=888, &p=0x7ffee6f1af84

  return 0;
}