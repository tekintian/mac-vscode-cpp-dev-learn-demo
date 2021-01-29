/**
 * @file vector_nest.cpp
 * @author Tekin
 * @brief 嵌套vector定义和数据获取
 * @version 0.1
 * @date 2021-01-27
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char **argv)
{
    vector<int> v1;
    vector<int> v2;
    vector<int> v3;

    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(3);

    v2.push_back(10);
    v2.push_back(20);
    v2.push_back(30);

    v3.push_back(100);
    v3.push_back(200);
    v3.push_back(300);

    // 嵌套vector定义
    vector< vector<int> > v;
    v.push_back(v1);
    v.push_back(v2);
    v.push_back(v3);

    // 循环遍历 取数据
    for(vector< vector<int> >::iterator it=v.begin(); it!=v.end(); it++) {
        // 循环遍历 vector<int>
        for(vector<int>::iterator mit=(*it).begin(); mit != (*it).end(); mit++) {
            cout<< *mit << "  ";
        }
        cout<< endl;
    }

    return 0;
}