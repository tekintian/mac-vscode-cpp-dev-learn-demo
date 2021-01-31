#include <iostream>

using namespace std;

int main(int argc, char **argv) {
  char line[200];
  int vowels, consonant, digit, space;
  vowels = consonant = digit = space = 0;
  printf("Enter a line of string:");
  fgets(line, sizeof(line), stdin);

  for (int i = 0; line[i] != '\0'; ++i) {
    printf("%c", line[i]);
  }
  return 0;
}