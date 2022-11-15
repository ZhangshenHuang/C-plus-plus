// 左移运算符重载
// 可以输出自定义的数据类型

#include <iostream>
using namespace std;

class Person
{
    friend ostream& operator<<(ostream& out, Person& p);

public:
    Person(int a, int h): mAge(a), mHeight(h) {}

private:
    int mAge, mHeight;
};

// 一旦使用链式编程思想，就要想到返回引用！！！
// 左移运算符重载函数一般写在类外，因为类内会默认为 Person << cout
ostream& operator<<(ostream& out, Person& p)
{
    out << p.mAge << " " << p.mHeight;
    return out;
}

void test01()
{
    Person p1(23, 178);
    Person p2(35, 180);
    cout << p1 << endl
         << p2 << endl;
}

int main()
{
    test01();

    return 0;
}