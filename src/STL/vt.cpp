#include <iostream>
#include <vector>
#include <string>

using namespace std;

#define N 10

int main()
{
    vector<int> v{0, 1};

    for (int i = 0; i < N; ++i)
    {
        v.push_back(v[i] + v[i + 1]);
    }

    // for_each(v.begin(), v.end(), [](int vv) { cout << vv << " "; });

    for(int vv:v)
    {
      cout<<vv <<"\n";
    }

    cout << endl;
}