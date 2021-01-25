#include <iostream>

using namespace std;

double division(int a, int b)
{
    if (b == 0)
    {
        throw "Division by zero condition!";
    }
    return a / b;
}

int main(int argc, char const *argv[])
{
    int x = 50, y = 0;
    double z = 0;
    try
    {
        z = division(x, y);
    }
    catch (const char *msg)
    {
        std::cerr << msg << '\n';
    }

    return 0;
}
