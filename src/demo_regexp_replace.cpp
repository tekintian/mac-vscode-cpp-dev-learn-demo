#include <iostream>
#include <iterator>
#include <regex>
#include <string>
using namespace std;

int main() {
  string search_string = " Hello! Welcome to EDUCBA, Learn with the best  \n ";
  cout << " Here is the input string: " << search_string << endl;
  regex regexp("H[a-zA-z]+");
  cout << " Replace the word 'Hello' with word 'Hey' : ";
  cout << regex_replace(search_string, regexp, "Hey");
  string output;
  cout << " Replace the word 'Hey' back to 'Hello' : ";
  regex_replace(back_inserter(output), search_string.begin(),
                search_string.end(), regexp, "Hello");
  cout << output;
  return 0;
}
