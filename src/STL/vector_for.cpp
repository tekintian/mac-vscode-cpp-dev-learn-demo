#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <algorithm>

using namespace std;

void myPrint(int var)
{
    cout << var << endl;
}
/**
 * @brief 容器对象打印函数, 支持 vector , deque 
 * 模板函数打印 vector对象
 * 
 * @tparam T 
 * @param t 
 */
template <class T>
void cprint(const T &t)
{
    for (const auto &e : t)
    {
        cout << e << "\n";
    }
    cout << endl;
}

void testVector()
{
    // 单端动态数组 vector 类模板
    vector<int> v; // v 就是一个具体的vector容器

    // push_back尾部插入
    v.push_back(1);
    v.push_back(300);
    v.push_back(89);

    // 访问数据
    // 定义一个迭代器,存储v的起始迭代器
    // 迭代器和容器是关联的
    vector<int>::iterator it_begin = v.begin();
    // 定义一个迭代器存储结束迭代器
    vector<int>::iterator it_end = v.end();

    // for循环遍历元素  只要起始迭代器不等于结束迭代器就开始遍历
    for (; it_begin != it_end; it_begin++)
    {
        int var = *it_begin;
        std::cout << "var = " << var << std::endl;
    }

    // for 循环遍历2  推荐用法
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        // 此处 var的类型 int 是 vector<int>中的int
        int var = *it;
        std::cout << "var=" << var << std::endl;
    }
    std::cout << "======template func===== \n";
    // template func
    cprint(v);
    std::cout << "======for_each===== \n";
    // stl提供的算法来遍历容器(必须要包含算法头文件  algorithm )
    // for_each 从容器的起始 -- 结束 逐个取出元素
    for_each(v.begin(), v.end(), myPrint);
    cout << endl;
}

int main(int argc, char **argv)
{
    testVector();

    // char var[]="你好";
    // int a = 8;
    // int *p; // 定义一个int类型指针 p
    // p = &a; // 在指针变量p中存储变量a的地址

    vector<string> str{"aaa", "bbbb"};
    cprint(str);

    deque<int> dd(5, 10);
    cprint(dd);
    return 0;
}