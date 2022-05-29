#include <iostream>

using namespace std;

#define ARC4RANDOM_MAX 0X100000000

int main(int argc, char **argv) {
  // double val = floorf(((double)arc4random() / ARC4RANDOM_MAX) * 100.0f);

  for (int i = 0; i < 100; i++) {
    double val = floorf(((double)arc4random() / ARC4RANDOM_MAX) * 100.0f);
    cout << val << "  ";
  }
  cout << endl;

  return 0;
}