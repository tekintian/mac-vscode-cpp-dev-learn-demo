#include <iostream>
using namespace std;
//声明函数
int max(int num1, int num2);

int main()
{
    int a=100, b=200;
    int ret;
    ret =max(a,b);
    cout<<"Max value is:"<<ret <<endl;
    return 0;
}
/**
 * @brief 
 * 
 * @param num1 
 * @param num2 
 * @return int 
 */
int max(int num1,int num2)
{
    return num1>num2? num1:num2;
}
