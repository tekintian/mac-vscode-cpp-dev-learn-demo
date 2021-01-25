#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int *getRandom()
{
    //因为 C++ 不支持在函数外返回局部变量的地址，除非定义局部变量为 static 变量
    static int ret[10];

    // 设置种子
    srand((unsigned)time(NULL));
    for (size_t i = 0; i < 10; i++)
    {
        ret[i] = rand();
        cout << ret[i] << endl;
    }
    return ret;
}

int main(int argc, char const *argv[])
{
    int *p;
    p = getRandom();
    for (size_t i = 0; i < 10; i++)
    {
        cout << "*(p + " << i << " ) =" << *(p + i) << endl;
    }

    return 0;
}
