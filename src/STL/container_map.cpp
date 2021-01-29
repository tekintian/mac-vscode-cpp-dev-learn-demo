/**
 * @file container_map.cpp
 * @author TekinTian (tekintian@gmail.com)
 * @brief map容器存取数据演示
 * @version 0.1
 * @date 2021-01-29
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>
#include <map>

using namespace std;

void mapPrint(map<int, string> &m)
{
    for (map<int, string>::const_iterator it = m.begin(); it != m.end(); it++)
    {
        // *it = <int, string>
        cout << "key=" << (*it).first << " val=" << (*it).second << endl;
    }
    cout << endl;
}

int main(int argc, char **argv)
{
    map<int, string> m;
    // pair构造方式
    m.insert(pair<int, string>(123, "C++语言"));
    // 使用 make_pair
    m.insert(make_pair(456, "Java语言"));
    // value_typ形式
    m.insert(map<int, string>::value_type(789, "PHP语言"));
    // 数组形式
    m[1000] = "PYTHON";
    m[1] = "Tekin";

    // 打印map
    mapPrint(m);

    /* result:
    key=123 val=C++语言
    key=456 val=Java语言
    key=789 val=PHP语言
    key=1000 val=PYTHON
    */

    return 0;
}