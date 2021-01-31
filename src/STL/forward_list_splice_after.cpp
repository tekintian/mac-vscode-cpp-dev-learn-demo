#include <forward_list>
#include <iostream>

using namespace std;

template <class S> void print(const S &s) {
  for (const auto &var : s) {
    cout << "(" << var << ") ";
  }
  cout << " \n------end print--------\n " << endl;
}

int main(int argc, char **argv) {
  forward_list<int> c1{10, 11};
  forward_list<int> c2{20, 21, 22};
  forward_list<int> c3{30, 31, 39, 38};
  forward_list<int> c4{40, 41, 42, 43};

  forward_list<int>::iterator where_iter;
  forward_list<int>::iterator first_iter;
  forward_list<int>::iterator last_iter;

  print(c1);

  where_iter = c2.begin();
  ++where_iter; // start at second element
  c2.splice_after(where_iter, c1);
  cout << "------after splice c1------" << endl;
  print(c1);
  print(c2);

  first_iter = c3.begin();
  c2.splice_after(where_iter, c3, first_iter);
  cout << "After splicing the first element of c3 into c2:" << endl;
  cout << "c3 = ";
  print(c3);
  cout << "c2 = ";
  print(c2);

  first_iter = c4.begin();
  last_iter = c4.end();
  // set up to get the middle elements
  ++first_iter;
  c2.splice_after(where_iter, c4, first_iter, last_iter);
  cout << "After splicing a range of c4 into c2:" << endl;
  cout << "c4 = ";
  print(c4);
  cout << "c2 = ";
  print(c2);

  return 0;
}