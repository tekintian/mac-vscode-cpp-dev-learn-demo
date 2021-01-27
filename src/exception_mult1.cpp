#include <iostream>
#include <string>

using namespace std;

class BaseException
{
protected:
    string msg;
    int code;

public:
    // 构造函数,使用成员初始化器赋值
    BaseException(string msg = "FAIL", int code = -1) : msg(msg), code(code)
    {
    }
    virtual void showError()
    {
        std::cout << "Base Exception error! msg:" << msg << " code:" << code << std::endl;
    }
};
/**
 * @brief 子异常类, 集成了基异常类
 * 
 */
class NullException : public BaseException
{
public:
    /**
     * @brief 带默认值的 有参构造函数
     *  有参构造函数实现只能是内联的,否则会报错
     * @param msg 
     * @param code 
     */
    NullException(string msg = "FAIL", int code = -1)
    {
        //注意这里的参数不能再使用成员初始化器来赋值了
        this->msg = msg;
        this->code = code;
    };
    virtual void showError();
};

void NullException::showError()
{
    std::cout << "Null Exception! msg:" << msg << "  code:" << code << std::endl;
}

int main(int argc, char **argv)
{
    try
    {
        //直接抛出异常
        throw NullException("空异常");
        // throw BaseException("基础异常");
    }
    catch (BaseException &e)
    {
        e.showError();
    }

    return 0;
}