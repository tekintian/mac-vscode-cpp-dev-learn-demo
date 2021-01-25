#include <iostream>

using namespace std;
/**
 * @brief C++中函数是不能直接返回一个数组的，但是数组其实就是指针，所以可以让函数返回指针来实现:
 * 
 * @param parr 
 * @param arr1 
 * @param arr2 
 */
void multMatrix(float parr[4], float arr1[4], float arr2[4])
{
    parr[0] = arr1[0] * arr2[0] + arr1[1] * arr2[2];
    parr[1] = arr1[0] * arr2[1] + arr1[1] * arr2[3];
    parr[2] = arr1[0] * arr2[0] + arr1[3] * arr2[2];
    parr[3] = arr1[0] * arr2[1] + arr1[3] * arr2[3];

    cout << parr[0] << "   " << parr[1] << endl;
    cout << parr[2] << "   " << parr[3] << endl;
}

int main(int argc, char const *argv[])
{
    float arr1[4] = {1.66, 0.56, 2.6, 9.88};
    float arr2[] = {1, 2, 3.8, 9.9};

    float *parr = new float[4];

    multMatrix(parr, arr1, arr2);

    std::cout << "-------------pointer-----------" << std::endl;
    cout << parr[0] << "   " << parr[1] << endl;
    cout << parr[2] << "   " << parr[3] << endl;

    // delete（删除）释放程序动态申请的内存空间。delete 后面通常是一个指针或者数组 []，并且只能 delete 通过 new 关键字申请的指针，否则会发生段错误。
    delete[] parr;

    return 0;
}
