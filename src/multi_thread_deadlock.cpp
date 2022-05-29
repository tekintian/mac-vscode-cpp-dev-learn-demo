/**
 * 死锁代码演示
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
      m_mutex2.lock();
      m_mutex1.lock();

      if (!m_queue.empty()) {
        cout << "outMsgRevQueue() : " << m_queue.front() << endl;
        m_queue.pop();
      }

      m_mutex1.unlock();
      m_mutex2.unlock();
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