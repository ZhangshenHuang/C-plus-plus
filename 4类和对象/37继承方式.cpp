// 继承的方式
// 继承的方式一共有三种
// 1.公共继承
// 2.保护继承
// 3.私有继承

#include <iostream>
#include <string>
using namespace std;

class Father
{
public:
    int mAge1;

protected:
    int mAge2;

private:
    int mAge3;
};

/********************************************************************/
// 公共权限继承
class Son1 :  public Father
{
public:
    void modify()
    {
        mAge1 = 10;  //父类中为公共权限，子类中仍为公共权限
        mAge2 = 10;  //父类中为保护权限，子类中仍为保护权限，test01()中进行了验证
        // mAge3 = 100; 父类中的私有成员，子类访问不到
    }
};

void testPublic()
{
    Son1 s1;
    s1.mAge1 = 18;  //公共权限，类外可以访问
    // s1.mAge2 = 18; 保护权限，类外访问不到
}

/********************************************************************/
// 保护权限继承
class Son2 : protected Father
{
public:
    void modify()
    {
        mAge1 = 10; //父类中为公共权限，继承方式为保护，到子类中即为保护权限
        mAge2 = 10; //父类中为保护权限，继承方式为保护，到子类中仍为保护权限
        // mAge3 = 10; 父类中的私有成员，子类访问不到
    }
};

void testProtected()
{
    Son2 s2;
    // s2.mAge1 = 18; 保护权限，类外无法访问
    // s2.mAge2 = 18; 保护权限，类外无法访问
}

/********************************************************************/
// 私有权限继承
class Son3 : private Father
{
public:
    void modify()
    {
        mAge1 = 10;
        mAge2 = 10;
        // mAge3 = 10; //父类中的私有成员，子类访问不到
    }
};

void testPrivate()
{
    Son3 s3;
    // s3.mAge1 = 18; 私有权限，类外不可访问
    // s3.mAge2 = 18; 私有权限，类外不可访问
}