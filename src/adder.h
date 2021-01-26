#ifndef __ADDER__H__
#define __ADDER__H__
class Adder
{
private:
    int total;
    const int baseNum; // 基础常量

public:
    Adder(int bn, int tl = 0); // 构造方法, 这里tl有默认值,必须在这里指定
    ~Adder();                  // 析构方法
    void addNum(int number);   // 自定义的方法
    int getTotal();            // 获取总数
};

#endif //!__ADDER__H__