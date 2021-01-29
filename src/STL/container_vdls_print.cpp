/**
 * @file container_vdls_print.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-01-29
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <stack>

using namespace std;

/**
 * @brief 模板函数打印迭代容器 
 * 
 * @tparam T 容器类型 泛型 支持 vector, deque, list, set
 * @param t 
 */
template <class T> void itPrint(const string &msg,T const &t)
{
    cout<< msg << ": ";
    for (const auto &var : t)
    {
        std::cout << var << " ";
    }
    cout << std::endl;
}

/* 回调函数打印变量 */
void vprint(const int &var) {
    cout<< var <<" ";
}

int main(int argc, char **argv)
{
    //vector
    vector<int> v{10, 20, 30, 40};
     cout<< "--------- for_each with callback func --------"<< endl;
    for_each(v.begin(),v.end(), vprint); 
    cout<<endl;

    cout<< "-------- for_each with lambda --------"<< endl;
    for_each(v.begin(),v.end(), [](int var){ cout<< var <<" "; }); 
    cout<<endl;

    // 泛型打印函数
    itPrint("int类型",v);
    
    // deque
    deque<string> str{"aaa", "bbb", "ccc"};
    itPrint("string类型",str);
    
    // list<string> L;
    list<string> l{"list1", "list2", "列表3"};
    itPrint("list类型",l);

    set<int> s{9,66,23,11};
    itPrint("set类型",s);


    return 0;
}