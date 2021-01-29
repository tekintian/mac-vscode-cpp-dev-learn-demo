#include <iostream>
#include <cstdlib>

using namespace std;

int main(int argc, char **argv)
{
    int *myptr;
    myptr = (int *)malloc(6 * sizeof(int)); // 分配6个int的内存

    if (myptr)
    {
        std::cout << "Lets intilize 6 memory blocks with odd numbers" << std::endl;
        for (int i = 0; i < 6; i++)
        {
            myptr[i] = (i * 2) + 1;
        }
        std::cout << "Lets see the values" << std::endl;
        for (size_t i = 0; i < 6; i++)
        {
            std::cout << "Value a position" << i << " is " << *(myptr + i) << std::endl;
        }
        free(myptr);
    }

    return 0;
}