#include <iostream>

using namespace std;

namespace first_space{
    void myfunc(){
        cout<<"inside first_space myfunction!"<<endl;
    }
    //嵌套命名空间
    namespace second_space{
        void myfunc(){
            cout<<"inside second_space myfunction!"<<endl;
        }
    }
}
//使用嵌套命名空间
using namespace first_space::second_space;

int main(int argc, char **argv)
{
    // 调用第二个命名空间中的函数
    myfunc();

    //调用第一个命名空间
    first_space::myfunc();
    return 0;
}