#include <ctime>
#include <iostream>
#include <pthread.h>
#include <unistd.h>

using namespace std;

//定义全局变量
string g_s;
time_t g_time = time(0);

void *func(void *) {
  g_s = ctime(&g_time);
  sleep(1);
  std::cout << "child thread created " << g_s << std::endl;
}

int main(int argc, char **argv) {
  g_s = ctime(&g_time);
  pthread_t t1[10];
  for (size_t i = 0; i < 10; i++) {
    std::cout << "Thread t[" << i << "] is created  " << g_s << std::endl;

    pthread_create(&t1[i], NULL, &func, NULL);
    pthread_join(t1[i], NULL);
  }
  exit(EXIT_SUCCESS);
  return 0;
}