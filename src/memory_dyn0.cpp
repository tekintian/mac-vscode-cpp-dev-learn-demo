#include <iostream>

using namespace std;

int main(int argc, char **argv)
{
    double *pvalue = NULL; // 初始化为null
    pvalue = new double;   //为变量请求内存
    *pvalue = 11199.88;    //在分配的内存地址中存储值
    std::cout << *pvalue << std::endl;
    delete pvalue; // 释放内存
    return 0;
}