#include <iostream>
#include <stdio.h>
#include <assert.h>

using namespace std;
/**
 * @brief C++ Function Template
 * 
 * @tparam T 
 * @param num1 
 * @param num2 
 * @return T 
 */
template <class T>
T add(T num1, T num2)
{
    return num1 + num2;
}

int main(int argc, char **argv)
{
    int result1;
    double result2;
    result1 = add<int>(2, 3);
    std::cout << " 2+3= " << result1 << std::endl;

    result2 = add<double>(88.9, 99.1);
    std::cout << "Double add = " << result2 << std::endl;

    /**
    int a;
    char str[50];

    printf("Enter an integer value: ");
    scanf("%d", &a);
    assert(a >= 10);
    printf("Integer entered is %d\n", a);

    printf("Enter string: ");
    scanf("%s", str);
    assert(str != NULL);
    printf("String entered is: %s\n", str);
    */
    printf("=========demo=========\n");
    int a = 10, b = 20;
    int *p = &a;
    // p = &b;
    printf("%p \n", &b);
    printf("%d \n", *p);

    return 0;
}