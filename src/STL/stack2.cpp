#include <iostream>
using namespace std;
int stack[100], x = 100, top = -1;
void push(int value)
{
    if (top >= x - 1)
        cout << " This is Stack Overflow " << endl;
    else
    {
        top++;
        stack[top] = value;
    }
}
void pop()
{
    if (top <= -1)
        cout << " This is Stack Underflow " << endl;
    else
    {
        cout << " The popped element from the stack is " << stack[top] << endl;
        top--;
    }
}
void show()
{
    if (top >= 0)
    {
        cout << " Stack elements are: ";
        for (int i = top; i >= 0; i--)
            cout << stack[i] << " ";
        cout << endl;
    }
    else
        cout << " Stack is empty ";
}
int main()
{
    int ch, value;
    cout << " 1) Do you want to Push in stack " << endl;
    cout << " 2) Do you want to Pop from stack " << endl;
    cout << " 3) Do you want to show stack " << endl;
    cout << " 4) Do you want to Exit " << endl;
    do
    {
        cout << " Please enter the choice: " << endl;
        cin >> ch;
        switch (ch)
        {
        case 1:
        {
            cout << " Please enter the value to be pushed: " << endl;
            cin >> value;
            push(value);
            break;
        }
        case 2:
        {
            pop();
            break;
        }
        case 3:
        {
            show();
            break;
        }
        case 4:
        {
            cout << " Exit " << endl;
            break;
        }
        default:
        {
            cout << " Invalid Choice " << endl;
        }
        }
    } while (ch != 4);
    return 0;
}