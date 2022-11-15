#include <iostream>
#include <string>
#include <queue>
using namespace std;

class Person
{
public:
    Person(string name)
    {
        this->mName = name;
    }

    string mName;
};

void myQueue()
{
    queue<Person> q;

    Person p1("Jerry");
    Person p2("Alice");
    Person p3("Tom");

    q.push(p1);
    q.push(p2);
    q.push(p3);

    cout << "Queue's size is: " << q.size() << endl;
    while (!q.empty()) {
        cout << "Front is: " << q.front().mName << endl;
        cout << "Back is: " << q.back().mName << endl;

        q.pop();
    }
    cout << "Queue's size is: " << q.size() << endl;
}

int main()
{
    myQueue();

    return 0;
}