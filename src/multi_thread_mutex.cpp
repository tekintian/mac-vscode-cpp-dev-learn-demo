/**
 * @file multi_thread_mutex.cpp
 * @author tekintian (tekintian@gmail.com)
 * @brief 互斥量的用法
lock
mutex.lock()

当锁空闲时，获取并继续执行
当锁被获取时，阻塞并等待锁释放
mutex.unlock()

释放锁（同一把锁的获取和释放必须在同一线程中成对出现）
如果 mutex 在调用 unlock() 时处于空闲状态，那么程序的行为是未定义的

lock_guard
在 lock_guard 对象构造时，传入的 mutex 对象（即它管理的 mutex
对象）会被当前线程锁住。 在 lock_guard 对象被析构时，它所管理的 mutex
对象会自动解锁，不再需要手动调用 lock 和 unlock 对mutex 进行上锁和解锁操作；
lock_guard 对象并不负责 mutex 对象的生命周期，只是简化了上锁和解锁操作；
这种采用“资源分配时初始化”（RAII）方法来加锁、解锁，避免了在临界区中因为抛出异常或return等操作导致没有解锁就退出的问题。这极大的简化了编写mutex相关的异常处理代码。
 *
 * @version 0.1
 * @date 2021-02-04
 *
 * @copyright (C)2021  Tekin.cn All Right Reserved.
 *
 */
#include <iostream>
#include <mutex>
#include <queue>
#include <thread>

using namespace std;

class Handle {
private:
  queue<int> m_queue;
  mutex m_mutex;
  int m_num = 100;

public:
  void inMsgRevQueue();
  void outMsgRevQueue();
};

void Handle::inMsgRevQueue() {
  for (size_t i = 0; i < m_num; i++) {
    m_mutex.lock(); // 加锁
    std::cout << "InMsgRevQueue() :" << i << std::endl;
    m_queue.push(i);

    m_mutex.unlock(); // 释放锁
  }
}

void Handle::outMsgRevQueue() {
  for (size_t i = 0; i < m_num; i++) {
    // 采用lock_guard 避免了在临界区中因为抛出异常或return等操作导致没有解锁就退出的问题
    lock_guard<mutex> lck(m_mutex);
    
    if (!m_queue.empty()) {
      std::cout << "outMsgRevQueue():" << m_queue.front() << std::endl;
      m_queue.pop(); //出队列
    }
  }
}

int main(int argc, char **argv) { 

    std::cout << "main begin" << std::endl;

    Handle handler;
    thread t1(&Handle::inMsgRevQueue, std::ref(handler));
    thread t2(&Handle::outMsgRevQueue, std::ref(handler));

    t1.join();
    t2.join();

    std::cout << "main end" << std::endl;
    return 0; 
}