#include <iostream>

using namespace std;
/**
 * @brief 模板函数实现冒泡排序
 * 
 * @tparam T 
 * @param a 
 * @param n 
 */
template <class T> void bubbleSort(T a[], int n) {
    for (size_t i = 0; i < n-1; i++)
    {
        for (size_t j = n-1; i < j; j--)
        {
            if (a[j]<a[j-1])
            {
                swap(a[j],a[j-1]);
            }
        }
    }
}

int main(int argc, char **argv)
{
    int a[5] = {10,50,30, 36,18};
    int n = sizeof(a) / sizeof(a[0]);

    std::cout << "sizeof(a)="<< sizeof(a) << std::endl;

    bubbleSort(a, n);
    std::cout << "sort:" << std::endl;
    for (int v:a)
    {
      cout<< v << "  ";  
    }
    cout<<endl;

    return 0;
}