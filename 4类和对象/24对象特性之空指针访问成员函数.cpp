// C++ 中空指针也是可以访问成员函数，但需要注意的是有没有用到this指针
// 如果有用到this指针的地方，空指针访问会报错

#include <iostream>
using namespace std;

class Person
{
public:
    void printName()
    {
        cout << "The class name is person!" << endl;
    }

    void printAge()
    {
        // 增强了程序的健壮性，防止空指针引起程序崩溃
        if (this == NULL) {
            return;
        }
        cout << "The person's age is: " << mAge << endl;
        // 相当于下面这行
        cout << "The person's age is: " << this->mAge << endl;
    }

public:
    int mAge = 35;
};

void test01()
{
    // 创建一个person类型的指针，但该指针不指向任何person类型的对象
    Person *p = NULL;
    p->printName();

    // 这里有一个this指针，p为NULL，都没有指向对象，调用this指向成员变量即会出错
    p->printAge();
    // cout << "The m_Age is: " << p->m_Age << endl;
}

int main()
{
    test01();

    return 0;
}