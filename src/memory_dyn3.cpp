#include <iostream>

using namespace std;

class Box
{
    public:
        Box(){
            cout<<"Box构造函数"<<endl;
        }
        ~Box(){
            cout<<"Box析构函数"<<endl;
        }
};

int main(int argc, char **argv)
{
    Box *myBoxArr = new Box[5]; //分配内存

    delete[]myBoxArr;// 释放内存

    return 0;
}