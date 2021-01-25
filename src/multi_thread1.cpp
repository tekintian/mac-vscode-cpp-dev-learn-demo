#include <iostream>
// 必须的线程头文件
#include <pthread.h>

using namespace std;

#define NUM_THREADS 5
//线程运行函数定义
void *say_hello(void *args)
{
    cout<<"Hello Tekin!\n"<<endl;
    return 0;
}

int main(int argc, char **argv)
{
    //定义线程的id变量,多个变量使用数组
    pthread_t tids[NUM_THREADS];

    for(int i=0;i<NUM_THREADS;i++){
        //参数依次是: 创建线程的id, 线程参数, 调用函数, 传入的函数参数
        int ret = pthread_create(&tids[i],NULL,say_hello, NULL);
        if(ret!=0){
            cout<<"pthread_create error:"<<ret<<endl;
        }
    }
    //等各个线程退出后，进程才结束，否则进程强制结束了，线程可能还没反应过来；
    pthread_exit(NULL);
    return 0;
}