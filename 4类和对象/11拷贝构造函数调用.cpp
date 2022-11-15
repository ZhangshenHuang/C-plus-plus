#include<iostream>
using namespace std;

// 拷贝构造函数调用时机
// 使用一个已经创建完毕的对象来初始化一个新对象
// 值传递的方式给函数参数传值
// 以值方式返回局部对象


class person
{
public:

    person()
    {
        cout << "parameterless constructor" << endl;
    }

    person(int a)
    {
        age = a;
        cout << "parameter constructor" << endl;
    }

    person(const person &p)
    {
        age = p.age;
        cout << "copy constructor" << endl;
    }

    ~person()
    {
        cout << "deconstructor!" << endl;
    }



private:

    int age;
};

// 使用一个已经创建完毕的对象来初始化一个新对象
void test1()
{
    person p1(100);
    person p2(p1);
}

// 值传递的方式给函数参数传值
void work(person p)
{
    cout << "value diliver copy constructor" << endl;
}

void test2()
{
    person p3;
    work(p3);
}

// 以值方式返回局部对象
person valreturn()
{
    person p4;
    cout << (int*)&p4 << endl;
    return p4;
}

void test3()
{
    person p = valreturn();
    cout << (int*)&p << endl;
}

int main()
{
    // test1();
    // test2();
    // 这里以值方式返回局部对象，VS和code 有别，以VS为准
    test3();

    return 0;
}