#include <iostream>
#include <csignal>
#include <unistd.h>

using namespace std;
void signalHandler(int signum)
{
    cout<<"Interrupt signal "<<signum<<" received! "<<endl;
    exit(signum);
}

int main(int argc, char **argv)
{
    int i=0;
    signal(SIGINT, signalHandler);
    while(++i){
        cout<<" Going to sleep...."<<endl;
        if(i==3){
            raise(SIGINT); //生成信号
        }
        sleep(1);
    }

    return 0;
}