/**
 * @file tuple.cpp
 * @author your name (you@domain.com)
 * @brief tuple演示,  仅 C++11 编译时返回正常的值:
 * 编译: g++ tuple.cpp -std=c++11 -o tuple
 * @version 0.1
 * @date 2021-01-29
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;

int main()
{
    int key = 10;
    vector<tuple<int, int>> v;
    v.resize(10);
    v[0] = std::make_tuple(10, 11);
    v[1] = std::make_tuple(20, 21);

    if (v.end() != std::find_if(v.begin(), v.end(), [key](std::tuple<int, int> t) { return get<0>(t) == key; }))
    {
        cout << "FOUND\n";
    }
    else
    {
        cout << "NOT FOUND\n";
    }
}
