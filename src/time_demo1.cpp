#include <iostream>
#include <ctime>
using namespace std;

int main(int argc, char const *argv[])
{
    // 获取当前系统的日期时间戳
    time_t now = time(0);
    std::cout << now << std::endl;

    tm *ltm = localtime(&now);

    // 输出 tm 结构的各个组成部分
    cout << "年: " << 1900 + ltm->tm_year << endl;
    cout << "月: " << 1 + ltm->tm_mon << endl;
    cout << "日: " << ltm->tm_mday << endl;
    cout << "时间: " << ltm->tm_hour << ":";
    cout << ltm->tm_min << ":";
    cout << ltm->tm_sec << endl;

    time_t curtime;
    time_t tt = time(&curtime);
    std::cout << "tt" << tt << std::endl;
    std::cout << "ctime=" << ctime(&curtime) << std::endl;

    return 0;
}
