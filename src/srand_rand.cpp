/** 随机数 因为 rand()是个伪随机函数, 需要每次产生不同的随机数,需要先使用 srand
 * 设置当前时间为随机数种子 */
#include <iostream>

using namespace std;

int main(int argc, char **argv) {
  //使用当前时间设置随机数种子
  srand(time(NULL));
  for (size_t i = 0; i < 10; i++) {
    // 产生随机数
    int rnum = rand();
    std::cout << "  " << rnum;
  }
  cout << std::endl;

  return 0;
}