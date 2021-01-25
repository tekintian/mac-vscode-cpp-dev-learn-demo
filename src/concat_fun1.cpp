#include <iostream>

using namespace std;

#define concat(a,b) a ## b

int main(int argc, char **argv)
{
    int xy=100;
    cout<<concat(x,y)<<endl;

    cout<<"__TIME__"<<__TIME__<<endl;
    cout<<"__DATE__"<<__DATE__<<endl;
    
    return 0;
}