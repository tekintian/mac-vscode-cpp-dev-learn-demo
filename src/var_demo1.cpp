#include <iostream>

int main(int argc, char const *argv[])
{
    int a = 3;
    int b = 2;
    b = a++;                       // 将a赋值给b 后 a再自增,  结果: b=3, a=4
    std::cout << ++b << std::endl; // b自增后输出  结果: b=4

    return 0;
}
