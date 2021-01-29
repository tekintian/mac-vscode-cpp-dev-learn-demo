#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char **argv)
{
  vector<int> v;
  v.push_back(2);
  v.push_back(1);
  v.push_back(5);
  v.push_back(3);
  v.push_back(4);

  for_each(v.begin(), v.end(), [](int v) { cout << v << " "; });
  cout << endl;

  return 0;
}