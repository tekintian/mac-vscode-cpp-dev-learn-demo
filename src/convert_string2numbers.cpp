#include <iostream>
#include <sstream>

using namespace std;

int main(int argc, char **argv)
{
    string s ="123456";
    stringstream stm(s);

    int x = 0;
    stm >> x; // 从流stm中提取数据到x

    cout<<"value of x:" << x <<endl;

    return 0;
}