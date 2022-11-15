#include <iostream>
#include <stack>
using namespace std;

void myStack()
{
    stack<int> s;

    s.push(1);
    s.push(2);
    s.push(3);

    cout << "stack's size is: " << s.size() << endl;

    while (!s.empty()) {
        cout << s.top() << endl;
        s.pop();
    }
    cout << "stack's size is: " << s.size() << endl;
}

int main()
{
    myStack();

    return 0;
}