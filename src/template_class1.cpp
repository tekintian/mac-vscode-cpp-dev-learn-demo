#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <stdexcept>

using namespace std;
/**
 * @brief 泛型方法来对元素进行入栈出栈操作
 * 
 * @tparam T 
 */
template <class T> class Stack{
    private:
        vector<T> elems; //定义元素
    
    public:
        void push(T const&); //入栈
        void pop(); // 出栈
        T top() const; //返回栈顶元素
        bool empty() const { // 如果为空则返回真
            return elems.empty();
        }
};

template <class T> void Stack<T>::push(T const &elem)
{
    //追加传入元素的副本
    elems.push_back(elem);
}

template <class T> void  Stack<T>::pop()
{
    if(elems.empty()){
        throw out_of_range("Stack<>::pop(): empty stack");
    }
    //删除最后一个元素
    elems.pop_back();
}

template <class T> T Stack<T>::top() const
{
    if(elems.empty()) {
        throw out_of_range("Stack<>::top(): empty stack");
    }
    // 返回最后一个元素的副本
    return elems.back();
}

// 主函数
int main(int argc, char **argv)
{
    try{
        Stack<int> intStack; // int类型的栈
        Stack<string> stringStack; // string类型的栈
        // 操作int类型的栈
        intStack.push(7);
        cout<<intStack.top()<<endl;

        // 操作string类型的栈
        stringStack.push("Hello");
        cout<< stringStack.top() << endl;
        stringStack.pop();
        stringStack.pop();

    } catch (exception const& ex) { 
        cerr << "Exception: " << ex.what() <<endl; 
        return -1;
    } 
    return 0;
}