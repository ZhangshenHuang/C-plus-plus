// 递增运算符重载
// 通过重载递增运算符，实现自己的整型数据

#include <iostream>
#include <string>
using namespace std;

class Person
{
    friend ostream& operator<<(ostream& out, Person p);

public:
    Person()
    {
        mAge = 20;
        mHeight = 160;
        mName = "Jerry";
        mId = "123456";
    }

    Person& operator++()
    {
        ++mAge;
        ++mHeight;
        mInfor = mName + mId;
        return *this;
    }

    // 不能返回局部变量的引用，后置自增无链式编程操作
    /*加入占位参数int 编译器识别为后置自增，不仅仅对int型数据适合，对string类型同样适用，编译器内部规定*/
    Person operator++(int)
    {
        Person temp = *this;
        ++mAge;
        ++mHeight;
        mInfor = mId + mName;
        return temp;
    }

private:
    int mAge, mHeight;
    string mName, mId, mInfor; 
};

// 这里是个坑 p不能为引用类型，因为后置递增重载函数返回的是一个局部变量！！！
ostream& operator<<(ostream& out, Person p)
{
    out << p.mAge <<" " << p.mHeight << " " << p.mInfor;
    return out;
}

void test01()
{
    Person p1, p2;
    /*****************************************************/
    cout << "++p1 = " << ++p1 << ", p1 = " << p1 << endl;
    cout << "p2++ = " << p2++ << ", p2 = " << p2 << endl;
}

int main()
{
    test01();

    return 0;
}