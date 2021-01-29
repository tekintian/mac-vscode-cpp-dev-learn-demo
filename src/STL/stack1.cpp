#include <iostream>
#include <stack>
using namespace std;
void stackone(stack<int> so)
{
    stack<int> sg = so;
    while (!sg.empty())
    {
        cout << '\t' << sg.top();
        sg.pop();
    }
    cout << endl;
}
int main()
{
    stack<int> st;
    st.push(505);
    st.push(404);
    st.push(303);
    st.push(202);
    st.push(101);
    cout << "The stack st is consists of these numbers: ";
    stackone(st);
    cout << "\n st.size() : " << st.size();
    cout << "\n st.top() : " << st.top();
    cout << "\n st.pop() : ";
    st.pop();
    stackone(st);
    return 0;
}