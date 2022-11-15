// 构造函数调用规则
// 默认情况下，C++编译器至少给一个类添加三个函数

// 1.默认构造函数（无参，函数体为空）
// 2.默认析构函数（无参，函数体为空）
// 3.默认拷贝构造函数，对属性进行值拷贝

// 构造函数调用规则
// 1.如果用户提供有参构造函数，编译器不再提供无参构造函数，但会提供拷贝构造函数
// 2.如果用户提供拷贝构造函数，编译器不再提供其他构造函数

#include<iostream>
using namespace std;

class person
{
public:
/*     person()
    {
        cout << "parameterless constructor" << endl;
    } */

    person(int age)
    {
        Age = age;
        cout << "parameter constructor" << endl;
    }

/*     person(const person &p)
    {
        Age = p.Age;
        cout << "copy constructor" << endl;
    } */

    ~person()
    {
        cout << "destructor!" << endl;
    }

private:
    int Age;
};

// 如果用户提供有参构造函数，则编译器不再提供默认构造函数，但会提供拷贝构造函数
void test1()
{
    // person p1;
    person p2(34);
    person p3(p2);
}

void test2()
{
    ;
}
int main()
{ 
    test1();

    return 0;
}