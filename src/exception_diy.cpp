#include <iostream>
#include <exception>
using namespace std;

// 定义自己的异常处理接头体
struct MyException : public exception
{
    /**
     * @brief 重写exception方法
     * 
     * @return const char* 
     */
    const char *what() const throw()
    {
        return "My C++ Exception";
    };
};

int main(int argc, char const *argv[])
{
    try
    {
        throw MyException();
    }
    catch (MyException &e)
    {
        cout << e.what() << endl;
    }
    catch (exception &e)
    {
        // 其他错误
        cout << e.what();
    }

    return 0;
}
