#include <iostream>
#include <cstring>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
    char str1[13] = {'T', 'e', 'k', 'i', 'n', 'c', 'n'};
    char str2[13] = "google";
    string str = "www.tekin.cn";

    std::cout << str << std::endl;
    char str3[13];
    int len;

    // 复制 str1到str3
    strcpy(str3, str1);
    cout << "strcpy(str3,str1)=" << str3 << "\n";

    strcat(str1, str2);
    cout << "strcat( str1, str2): " << str1 << endl;

    len = strlen(str1);
    cout << "strlen(str1)=" << len << endl;

    std::cout << " str * 地址=" << &str << std::endl;
    return 0;
}
