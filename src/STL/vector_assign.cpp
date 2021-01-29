#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <algorithm>

using namespace std;

/**
 * @brief int 类型vector容器数据打印输出
 * 
 * @param v 
 */
void printVectorInt(vector<int> &v)
{
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *it << "  ";
    }
    cout << endl;
}

// template <typename T>
// void tpv(vector<T> &v)
// {
//   for (vector<T>::iterator it = v.begin(); it != v.end(); it++)
//   {
//     cout << *it << "  ";
//   }
//   cout << endl;
// }
/**
 * @brief vector常用赋值操作 演示
assign(beg, end);//将[beg, end)区间中的数据拷贝赋值给本身。
assign(n, elem);//将n个elem拷贝赋值给本身。
vector& operator=(const vector  &vec);//重载等号操作符
swap(vec);// 将vec与本身的元素互换。
 * 
 */
void vtest1()
{
    vector<int> v1(5, 10);
    vector<int> v2;
    v2 = v1;
    // printVectorInt(v2);
    // printVectorInt(v1);

    vector<int> v3;
    v3.assign(8, 90); // 将8个90拷贝赋值给本身
    // printVectorInt(v3);

    vector<int> v4;
    v4.assign(v3.begin(), v3.end()); //将v3的开始到结束的元素拷贝到v4
    // printVectorInt(v4);

    vector<int> v5(5, 58);
    vector<int> v6(6, 66);
    // 将v5和v6的元素互换
    v5.swap(v6);
    printVectorInt(v6);
}
/**
 * @brief vector大小操作 演示
size();//返回容器中元素的个数
empty();//判断容器是否为空
resize(int num);//重新指定容器的长度为num，若容器变长，则以默认值填充新位置。如果容器变短，则末尾超出容器长度的元素被删除。
resize(int num, elem);//重新指定容器的长度为num，若容器变长，则以elem值填充新位置。如果容器变短，则末尾超出容器长>度的元素被删除。
capacity();//容器的容量
reserve(int len);//容器预留len个元素长度，预留位置不初始化，元素不可访问
 * 
 */
void testCom()
{
    vector<int> v;

    srand((unsigned)time(NULL)); //生成随机数种子
    // 循环赋值给v
    for (size_t i = 1; i <= 100; i++)
    {
        v.push_back(i * rand());
    }
    if (v.empty())
    {
        std::cout << "容器为空!" << std::endl;
    }
    else
    {
        std::cout << "Container Info:" << std::endl;
        std::cout << "size = " << v.size() << std::endl;
        std::cout << "capacity = " << v.capacity() << std::endl;
    }
    // printVectorInt(v);

    v.resize(8);            // 使用resize将空间设置为8个元素(只能修改size,不能修改容量)
    vector<int>(v).swap(v); // 将容器的容量重置为size

    printVectorInt(v);

    std::cout << "size = " << v.size() << std::endl;
    std::cout << "capacity = " << v.capacity() << endl;

    std::cout << "[2]=" << v[2] << std::endl;

    std::cout << "at(3)=" << v.at(3) << std::endl;
}

int main()
{
    // vtest1();
    testCom();
}