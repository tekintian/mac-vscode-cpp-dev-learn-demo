/**
 * @file t1.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-01-27
 * 
 * @copyright Copyright (c) 2021
 * @see https://stackoverflow.com/questions/39913218/candidate-template-ignored-couldnt-infer-template-argument
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


template<typename T>
class MyClassRef {
public:
    MyClassRef(std::nullptr_t = nullptr):_value{nullptr} {}
    explicit MyClassRef(T *value);

    template<typename T2, typename = typename std::enable_if<std::is_convertible<T2*, T*>::value, T2>::type>
    MyClassRef(MyClassRef<T2> const& value);

    template<typename T2>
    MyClassRef(MyClassRef<T2> &&value):MyClassRef{}
    {
        swap(*this, value);
    }

    template<typename T2>
    MyClassRef& operator=(MyClassRef<T2> value)
    {
        swap(*this, value);
        return (*this);
    }

    template<typename T1, typename T2, typename = typename std::enable_if<std::is_convertible<T2*, T1*>::value>::type>
    friend void swap(MyClassRef<T1>& t1, MyClassRef<T2>& t2)
    {
        using std::swap;
        swap(t1._value, t2._value);
    }
private:
  T *_value;
};
