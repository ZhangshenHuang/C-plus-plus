// 静态成员变量
// 1.所有对象共享同一份数据
// 2.在编译阶段分配内存
// 3.类内声明，类外初始化


#include<iostream>
#include<string>
using namespace std;

class person
{
public:


// 静态成员变量也有访问权限限制，如果是private类型，则外面的函数体访问不到
public:
    static int age;
    static string name;
};

// 类外初始化，此处的int 和 string 类型声明符不可少，否则报错
int person::age = 34;
string person::name = "Curry";

void test1()
{
    person p1;
    cout << "p1's name is: " << p1.name << ", age is: " << person::age << endl;
}

void test2()
{
    person p2;
    p2.age = 40;
    p2.name = "James Harden";
    // 两种访问方式，1.通过对象访问 2.通过类名访问
    cout << "p2's name is: " << person::name << ", age is: " << p2.age << endl;
}

int main()
{
    // test1();
    test2();
    // 这里如果反一下，函数test1()在test2()之后调用，则p1输出结果和p2一样
    // 因为这个数据独一份，该类的所有成员共享
    test1();

    return 0;
}