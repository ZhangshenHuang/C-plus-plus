// 深拷贝与浅拷贝是面试经典问题，也是常见的一个坑
// 浅拷贝：简单的赋值拷贝操作，即 “=” 的赋值操作
// 深拷贝：在堆区重新申请空间，进行拷贝操作

// 如果有属性在堆区开辟，且函数语句中执行了拷贝构造，一定要自己编写拷贝构造函数，防止浅拷贝带来的堆区数据重复释放问题！！！！！

#include<iostream>
using namespace std;

class person
{
public:
    person()
    {
        cout << "parameterless constructor is calling..." << endl;
    }

    person(int age, int height)
    {
        cout << "parameter constructor is calling..." << endl;
        Age = age;
        Height = new int (height);
    }

    // 自己编写的拷贝构造函数
    person(const person &p)
    {
        cout << "copy constructor is calling..." << endl;
        // 原来编译器默认的拷贝构造函数只写了这两条，属于浅拷贝
        // 因此如果属性有在堆区开辟的，一定要自己提供拷贝函数
        // 从而防止系统提供的默认浅拷贝函数带来的问题
        Age = p.Age;
        // Height = p.Height;

        // 此为自己编写的深拷贝，即在堆区重新开辟一片内存，两个对象的属性存储在不同的堆区
        // 而不是共用一片堆区，在执行自己析构函数的时候出现重复释放同一片堆区的问题
        Height = new int (*p.Height);
    }

    ~person()
    {
        if(Height != NULL)
        {
            delete Height;
        }
        Height = NULL;  //代码严谨，防止野指针
        cout << "destructor is calling..." << endl;
    }



public:
    int Age, *Height;
};

void test1()
{
    person p1(23, 178);
    cout << "p1's age is: " << p1.Age << endl;
    cout << "p1's height is: " << *p1.Height << endl;

    person p2(p1);
    cout << "p2's age is: " << p2.Age << endl;
    cout << "p2's height is: " << *p2.Height << endl;
}

int main()
{
    test1();

    return 0;
}