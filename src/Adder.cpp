#include <iostream>
#include "adder.h"

using namespace std;

/**
 * @brief Adder构造方法
 *  注意: 这里的构造方法参数如果有默认值,则必须在定义的时候指定,且默认值只能放到参数的最后, 如这里的: int tl 的初始化只能在类定义的时候就行(即在Adder.h头文件中进行)
 * @param bn 常量 只能使用 Member Initializers
 * @param tl 设置了默认值,初始化在类创建时
 */
Adder::Adder(int bn, int tl) : baseNum(bn), total(tl)
{
}
// 析构方法
Adder::~Adder()
{
}
void Adder::addNum(int number)
{
    total += number;
}
int Adder::getTotal()
{
    return baseNum + total;
}
// 入口函数
int main(int argc, char **argv)
{
    Adder a(9);  // 初始化Adder对象为 a , 构造方法里面有2个参数,因为有一个有默认值,所以这里可以传1个参数; 有默认值的参数初始化时可以不传值
    a.addNum(8); // 访问对象方法
    a.addNum(9);

    cout << "Total=" << a.getTotal() << endl;
    return 0;
}