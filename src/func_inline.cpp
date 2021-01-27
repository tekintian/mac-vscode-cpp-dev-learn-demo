#include <stdio.h>

// 定义一个内联函数 返回指针
inline const char *num_check(int v)
{
    return (v % 2 > 0) ? "奇" : "偶";
}

int main(int argc, char **argv)
{

    for (size_t i = 0; i < 5; i++)
    {
        printf("%03d  %s\n", i, num_check(i));
    }

    return 0;
}