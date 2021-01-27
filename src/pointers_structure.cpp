/**
 * @file pointers_structure.cpp
 * @author your name (you@domain.com)
 * @brief C++ Pointers to Structure demo
 * @version 0.1
 * @date 2021-01-26
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>

using namespace std;

struct Distance
{
    int feet;
    float inch;
};

int main(int argc, char **argv)
{
    Distance *ptr, d;
    ptr = &d;

    std::cout << "Enter feet:" << std::endl;
    cin >> (*ptr).feet;

    std::cout << "Enter inch:" << std::endl;
    cin >> (*ptr).inch;

    std::cout << "Displaying information." << std::endl;
    std::cout << "Distance = " << (*ptr).feet << " feet " << (*ptr).inch << " inch " << std::endl;

    return 0;
}