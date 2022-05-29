/**
 * std::lock_guard 的 std::adopt_lock 参数
使用 adopt_lock 构造的 unique_lock 和 lock_guard
对象在构造时不会锁定mutex对象，而是假定它已被当前线程锁定。
 */
#include <iostream>
#include <mutex>
#include <queue>
#include <thread>

using namespace std;

class Handle {
public:
  void inMsgRevQueue() {
    for (int i = 0; i < 1000; ++i) {
      m_mutex.lock();

      cout << "inMsgRevQueue() : " << i << endl;
      m_queue.push(i);

      m_mutex.unlock();
    }
  }

  void outMsgRevQueue() {
    for (int i = 0; i < 1000; ++i) {
      m_mutex.lock();

      lock_guard<mutex> lck(m_mutex, adopt_lock); // 注意这里 ！！！

      if (!m_queue.empty()) {
        cout << "outMsgRevQueue() : " << m_queue.front() << endl;
        m_queue.pop();
      }
    }
  }

private:
  queue<int> m_queue;
  mutex m_mutex;
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