#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    char name[50];
    unsigned int age;

    cout << "请输入你的名称:\n";
    cin >> name;
    cout << "你输入的名称是:" << name << endl;

    // 要求输入多个演示
    std::cout << "多个输入参数演示" << std::endl;
    cin >> name >> age;
    std::cout << "cin>>name=" << name << "\n cin>>age=" << age << std::endl;
    return 0;
}
