/**
 * @file vector_ct.cpp
 * @author TekinTian (tekintian@gmail.com)
 * @brief  vector容器存放自定义数据类型  for_each算法遍历数据演示.
 * @version 0.1
 * @date 2021-01-27
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


class Person
{
    private:
     const string name;
     const int age;
    public:
        Person(string name, int age):name(name), age(age) 
        {

        }
        void getInfo();
};

void Person::getInfo(){
cout<< "name="<< this->name << "  age="<< this->age << endl;
}

void myPrint(Person p)
{
    p.getInfo();
}

int main(int argc, char **argv)
{
    Person p1("张三",19);
    Person p2("李四",28);
    Person p3("王五",55);

    vector<Person> vp;
    vp.push_back(p1);
    vp.push_back(p2);
    vp.push_back(p3);

    for_each(vp.begin(),vp.end(), myPrint);
    
    return 0;
}