// 问题引出：在使用多态的时候，如果子类中有属性在堆区开辟，那么delete父类指针是无法将子类在堆区开辟的空间释放的
// 即子类在堆区开辟的空间无法释放问题

// 解决方式：1.将父类中的析构函数改为虚析构或者纯虚析构

// 虚析构和纯虚析构的共性：
// 1.可以解决父类指针释放子类对象在堆区创建的数据问题
// 2.都需要有具体的函数实现

// 区别：如果是纯虚析构，则该父类属于抽象类，无法实例化对象

// 语法：
// 虚析构：virtual ~类名() {}
// 纯虚析构：virtual ~类名() = 0;   类名::~类名() {}

#include <iostream>
#include <string>
using namespace std;

class Animal
{
public:
    virtual void speak() = 0;

    // 父类构造函数
    Animal()
    {
        cout << "Animal's constructor is calling..." << endl;
    }

    // // 父类析构函数 将父类的析构函数声明为虚析构 可以通过delete父类指针 调用父类以及子类的析构函数
    // virtual ~Animal()
    // {
    //     cout << "Animal's destructor is calling..." << endl;
    // }

    // 下为方法二纯虚析构解决
    virtual ~Animal() = 0;
};

Animal::~Animal()
{
    cout << "Animal's pure destructor is calling..." << endl;
}

class Cat : public Animal
{
public:
    virtual void speak()
    {
        cout << "Cat is speaking..." << endl;
    }

    // 子类构造函数
    Cat(string name)
    {
        mName = new string(name);
        cout << "Cat's constructor is calling..." << endl;
    }

    // 子类析构函数
    ~Cat()
    {
        if (mName != nullptr) {
            delete mName;
            mName = nullptr;
        }
        cout << "Cat's destructor is calling..." << endl;
    }

public:
    string* mName;
};

void speak()
{
    Animal* animal = new Cat("Tom");
    animal->speak();

    // 如果没有此释放指针的操作，那么就不会调用析构函数，子类和父类的都不会调用
    if (animal != nullptr) {
        delete animal;
        animal = nullptr;
    }
}

int main()
{
    speak();

    return 0;
}