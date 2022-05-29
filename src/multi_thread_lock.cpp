/**
 * std::lock 函数模板
lock（mutex1, mutex2, ...）; 一次锁定两个或多个锁，用于处理多个互斥量

当全部锁空闲时，获取并继续执行
当全部锁未被获取时，阻塞并等待锁释放

当只获取其中一部分锁，另一部分锁被其它线程锁定时，则释放当前已获取的锁，继续等待并重新尝试获取全部锁，以此防止死锁
 */
#include <iostream>
#include <mutex>
#include <queue>
#include <thread>

using namespace std;

class Handle {
public:
  void inMsgRevQueue() {
    for (int i = 0; i < 100000; ++i) {
      m_mutex1.lock();
      m_mutex2.lock();

      cout << "inMsgRevQueue() : " << i << endl;
      m_queue.push(i);

      m_mutex2.unlock();
      m_mutex1.unlock();
    }
  }

  void outMsgRevQueue() {
    for (int i = 0; i < 100000; ++i) {
      lock(m_mutex1, m_mutex2); // 注意这里 ！！！

      if (!m_queue.empty()) {
        cout << "outMsgRevQueue() : " << m_queue.front() << endl;
        m_queue.pop();
      }

      m_mutex2.unlock();
      m_mutex1.unlock();
    }
  }

private:
  queue<int> m_queue;
  mutex m_mutex1;
  mutex m_mutex2;
};

int main() {
  cout << "main begin" << endl;

  Handle handler;

  thread th1(&Handle::inMsgRevQueue, std::ref(handler));
  thread th2(&Handle::outMsgRevQueue, std::ref(handler));

  th1.join();
  th2.join();

  cout << "main end" << endl;

  return 0;
}