#include <iostream>
#include <exception>
using namespace std;

// 定义自己的异常处理接头体
struct MyException : public exception
{
    const char *m_ErrorInfo;
    MyException(const char *msg="FAIL!"){
        this->m_ErrorInfo=msg;
    };
    /**
     * @brief 重写exception方法
     * 
     * @return const char* 
     */
    const char *what() const throw()
    {
        return this->m_ErrorInfo;
    };
};

int main(int argc, char const *argv[])
{
    try
    {
        throw MyException("错误了!!");
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
