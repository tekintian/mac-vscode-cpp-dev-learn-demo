/**
 *
 * regexp search demo
 *
 * @file demo_regexp_search.cpp
 * @author tekintian (tekintian@gmail.com)
 * @brief regexp search demo
 * @version 0.1
 * @date 2021-01-29
 *
 * @copyright (C)2021  Tekin.cn All Right Reserved.
 *
 */
#include <iostream>
#include <regex>
#include <string>

using namespace std;

int main(int argc, char **argv) {
  string str = "Hello Tekin, welcome to learn C++ programming!";
  regex reg_exp("([a-z]{5,})");   // 正则表达式定义 l[a-z_]+
  smatch sm;                      // 接收变量定义
  regex_search(str, sm, reg_exp); // 执行正则搜索

  std::cout << "/* regex search result: */" << std::endl;

  // 使用增强for循环取接收信息
  for (auto v : sm) {
    cout << v << endl;
  }

  // regex_match 函数使用
  if (regex_match(str, reg_exp)) {
    cout << "找到了!\n";
  }

  regex_match(str.cbegin(), str.cend(), sm, reg_exp);
  // 匹配常量
  // regex_match(str, sm, reg_exp, regex_constants::match_default);

  std::cout << "/* regex_match result: */" << std::endl;

  cmatch cm;
  regex_match(str, cm, reg_exp);

  for (int i = 0; i < cm.size(); i++) {
    cout << " [ " << cm[i] << "]\n";
  }
  return 0;
}