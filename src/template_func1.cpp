#include <iostream>
#include <string>

using namespace std;

/**
 * @brief Get the Max object 函数模板
 *  泛型函数模板演示
 * @tparam T  是函数所使用的数据类型的占位符名称。
 * @param a 
 * @param b 
 * @return T const& 
 */
template <typename T> inline T const& getMax(T const &a, T const &b)
{
    return a<b?b:a;
}

int main(int argc, char **argv)
{
    // int类型示例
    int i=69,j=29;
    cout<< "getMax(i,j):" << getMax(i, j) <<endl;
    // double类型示例
    double f1 = 11.5,f2=28.7;
    cout<<"getMax(f1,f2):"<< getMax(f1,f2) <<endl;
    // string 示例
    string s1="hello",s2="world";
    cout<<"getMax(s1,s2):"<< getMax(s1,s2) <<endl;

    return 0;
}