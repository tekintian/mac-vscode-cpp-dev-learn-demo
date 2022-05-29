/**
 * 单例模式演示
 * 在单例的内部实现智能生成一个实例,同时他提供一个静态的 getInstance() 工厂方法
 * 将默认的构造函数和拷贝构造函数设计为私有.
 */
#include <iostream>
#include <string>

using namespace std;

class Printer {
private:
  // 1. 定义一个静态的对象指针变量  保存唯一的实例地址
  static Printer *singlePrint;
  // 3、防止 该类实例化其他对象 将构造函数全部 私有
  Printer() { count = 0; };
  Printer(const Printer &obj){}; // 拷贝构造函数
public:
  // 2. 提供一个方法获取单例指针
  static Printer *getSignlePrint(void) { return singlePrint; }
  // 普通方法
  void printTxt(string str);
  int count;
};

void Printer::printTxt(string str) {
  std::cout << " 打印: " << str << std::endl;
  count++;
}

/**  给对象申请一个唯一的实例 */
Printer *Printer::singlePrint = new Printer;

int main(int argc, char **argv) {
  //打印任务1
  Printer *p1 = Printer::getSignlePrint();
  p1->printTxt("任务1");
  p1->printTxt("任务2");
  p1->printTxt("任务3");
  cout << "p1任务数量:" << p1->count << endl; // 3

  Printer *p2 = Printer::getSignlePrint();
  p2->printTxt("任务4");
  p2->printTxt("任务5");
  p2->printTxt("任务6");

  std::cout << "p2任务数量:" << p2->count << std::endl; // 6
  return 0;
}
