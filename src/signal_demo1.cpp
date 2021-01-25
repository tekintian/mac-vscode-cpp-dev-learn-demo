#include <iostream>
#include <csignal>
#include <unistd.h>

using namespace std;
//信号处理函数定义
void signalHandler(int signum){
    cout<<"Interrupt signal("<<signum<<") received!";
    exit(signum);
}
int main(int argc, char **argv)
{
    //注册信号 SIGINT 和信号处理程序
    signal(SIGINT, signalHandler);
    // 一直执行,  按 ctrl+c来终止程序后上面的信号处理程序就会触发
    while(1){
        cout<<"Going sleep...."<<endl;
        sleep(1);
    }
    return 0;
}