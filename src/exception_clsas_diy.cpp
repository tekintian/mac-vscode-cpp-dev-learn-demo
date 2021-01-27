#include <iostream>
#include <string>

using namespace std;
/**
 * @brief 这里一继承 exception就报 error: exception specification of overriding function is more lax than base version
 * 根据这里的说明,无法解决@see https://stackoverflow.com/questions/53829852/exception-specification-of-overriding-function-is-more-lax-than-base-version 
 * 
 */
class MyException
{
    public:
        MyException(string msg="Error!"):m_ErrorMsg(msg)
        {
        };

       ~MyException() {};

       const char *what() const throw() {
        return this->m_ErrorMsg.data();
      };
      
        string m_ErrorMsg;
};

class Person
{
    private:
       string name;
       int age;
    public:
    Person(string name, int age):name(name),age(age)
    {
        if(age<18) {
            throw MyException("未成年人禁止入内!");
        }
    }
};

void testPerson()
{
    try {
        Person p("小明",10);
    }
    catch(MyException &e)
    {
        cout<<e.what()<<endl;
    }
}

int main(int argc, char **argv)
{
    testPerson();
    return 0;
}