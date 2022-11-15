#include <iostream>
#include <set>
#include <string>
using namespace std;

class Person
{
public:
    Person(string name, int height)
    {
        this->mName = name;
        this->mHeight = height;
    }
public:
    string mName;
    int mHeight;
};

class PersonCompare
{
public:
    bool operator()(const Person& p1, const Person& p2) const
    {
        return p1.mHeight > p2.mHeight;
    }
};

void printPerson(set<Person, PersonCompare>& s)
{
    for (set<Person, PersonCompare>::iterator iter = s.begin(); iter != s.end(); ++iter) {
        cout << "Name is:" << iter->mName << "  Height is:" << iter->mHeight << endl;
    }
}
void customData()
{
    Person p1("Liubei", 172);
    Person p2("GuanYu", 200);
    Person p3("ZhangFei", 160);

    set<Person, PersonCompare> s;
    s.insert(p1);
    s.insert(p2);
    s.insert(p3);

    printPerson(s);
}

int main()
{
    customData();

    return 0;
}