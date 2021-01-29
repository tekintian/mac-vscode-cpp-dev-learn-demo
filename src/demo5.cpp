#include <vector>
struct base
{
    // TO FIX: uncomment the next line
    // virtual ~base() {}
};

struct derived : base
{
    std::vector<int>::iterator m_iter;
    derived(std::vector<int>::iterator iter) : m_iter(iter) {}
    ~derived() {}
};

int main()
{
    std::vector<int> vect(10);
    base *pb = new derived(vect.begin());
    delete pb; // doesn't call ~derived()
               // access violation
}