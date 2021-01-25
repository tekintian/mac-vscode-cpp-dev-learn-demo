#include <iostream>
#include <cstdlib>
#include <pthread.h>

using namespace std;
#define  NUM_THREADS 5

void *printHello(void *threadid){
  // 对传入的参数进行强制类型转换,由无类型指针变为整形指针,然后在读取值
  int tid = *((int*)threadid);
  cout<<"Hello Tekin, 线程ID:"<<tid<<"\n"<<endl;
  pthread_exit(NULL);
}

int main(int argc, char **argv)
{
    pthread_t threads[NUM_THREADS];
    int indexes[NUM_THREADS]; // 用数组来保存i的值
    int rc,i;

    for(i=0;i<NUM_THREADS; i++){
        cout<<"创建线程"<< i <<endl;
        indexes[i]=i; // 先保存i的值
        // 传入的时候必须强制转换为 void*类型,即无类型指针
        rc = pthread_create(&threads[i], NULL, printHello,(void *)&(indexes[i]));
        if(rc) {
            cout<<"线程创建失败"<<rc<<endl;
            exit(-1);
        }
    }
    pthread_exit(NULL);
}