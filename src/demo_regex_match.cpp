/**
 * regex_match  regex_replace 演示
 * @file demo_regex_match.cpp
 * @author tekintian (tekintian@gmail.com)
 * @brief  C++ program to demonstrate working of regex_replace()
 *
 * @version 0.1
 * @date 2021-01-30
 *
 * @copyright (C)2021  Tekin.cn All Right Reserved.
 *
 */
#include <iostream>
#include <iterator>
#include <regex>
#include <string>

using namespace std;

int main(int argc, char **argv) {
  string str1 = "你好 c++,I am Tekin , I come from 云南昆明";
  regex reg_exp("[\u4e00-\u9fa5]{2,}");

  if (regex_match(str1, reg_exp)) {
    cout << " 找到了英文字符了!\n";
  }

  if (regex_match(str1.begin(), str1.end(), reg_exp)) {
    cout << "regex_match matched \n";
  }

  smatch sm;
  regex_search(str1, sm, reg_exp);
  for (auto x : sm) {
    cout << x << "\n";
  }

  cout << regex_replace(str1, reg_exp, "你好");

  cout << "\n---------------------\n";
  string str2 = "你好 c++, 我来自 yunnan";
  string ret;

  regex_replace(back_inserter(ret), str2.begin(), str2.end(), reg_exp,
                "Hello ");

  cout << ret << "\n";

  return 0;
}