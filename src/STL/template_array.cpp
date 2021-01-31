#include <iostream>

using namespace std;

template <class T> 
class MyArrClass {
private:
  T *ptr;
  int size;

public:
  MyArrClass(T arr[], int s);
  ~MyArrClass(){};
  void print();
};
// MyArrClass类的构造方法
template <class T>
MyArrClass<T>::MyArrClass(T arr[], int s) {
  ptr = new T[s];
  size = s;
  for (int i = 0; i < size; i++) {
    ptr[i] = arr[i];
  }
}
// MyArrClass类的print方法
template <class T> void MyArrClass<T>::print() {
  for (int i = 0; i < size; i++) {
    cout << " " << *(ptr + i);
  }
  cout << endl;
}

int main(int argc, char **argv) {
  int arr[5] = {8, 6, 3, 9, 1};
  MyArrClass<int> a(arr, 5);
  a.print();

  return 0;
}