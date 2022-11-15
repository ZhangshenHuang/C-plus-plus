#include <iostream>
#include <list>
#include <string>
using namespace std;

class Person
{
public:
    Person(string name, int age, int height, int weight)
    {
        this->mName = name;
        this->mAge = age;
        this->mHeight = height;
        this->mWeight = weight;
    }

public:
    string mName;
    int mAge, mHeight, mWeight;
};

// 排序规则：
// 年龄升序，如果年龄相同，则身高降序，身高还相同则体重升序
bool myCompare(Person p1, Person p2)
{
    if (p1.mAge == p2.mAge) {
        if (p1.mHeight == p2.mHeight) {
            return p1.mWeight < p2.mWeight;
        } else {
            return p1.mHeight > p2.mHeight;
        }
    } else {
        return p1.mAge < p2.mAge;
    }
}
void myPerson()
{
    Person p1("Curry", 32, 206, 100);
    Person p2("James", 35, 220, 110);
    Person p3("Harden", 32, 206, 90);
    Person p4("Shuhao", 32, 206, 120);
    Person p5("Thompson", 35, 206, 110);
    Person p6("Durant", 35, 230,120);

    list<Person> l;
    l.push_back(p1);
    l.push_back(p2);
    l.push_back(p3);
    l.push_back(p4);
    l.push_back(p5);
    l.push_back(p6);

    l.sort(myCompare);

    for (list<Person>::iterator iter = l.begin(); iter != l.end(); ++iter) {
        cout << "Name:" << iter->mName << " Age:" << iter->mAge
             << " Height:" << iter->mHeight << " Weight:" << iter->mWeight << endl;
    }
}

int main()
{
    myPerson();

    return 0;
}