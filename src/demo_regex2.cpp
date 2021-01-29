#include <iostream>
#include <regex>
#include <string>
using namespace std;

int main() {
  if (regex_match("softwareDevelopment", regex("(Soft)(.*)")))
    cout << "String:literal => matched\n";
  const char search_string[] = "SoftwareDevelopmentHelp";
  string text("software");
  regex str_expr("(soft)(.*)");
  if (regex_match(text, str_expr))
    cout << "String:object => matched\n";
  if (regex_match(text.begin(), text.end(), str_expr))
    cout << "String:range(begin-end)=> matched\n";
  cmatch cm;
  regex_match(search_string, cm, str_expr);
  smatch sm;
  regex_match(text, sm, str_expr);
  regex_match(text.cbegin(), text.cend(), sm, str_expr);
  cout << "String:range, size:" << sm.size() << " are the matches\n";
  regex_match(search_string, cm, str_expr, regex_constants::match_default);
  cout << "The total matches are : ";
  for (int i = 0; i < sm.size(); ++i) {
    cout << "[" << sm[i] << "] ";
  }
  cout << endl;
  return 0;
}