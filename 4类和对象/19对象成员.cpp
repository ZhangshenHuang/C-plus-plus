// C++中类的成员可以为另一个类的对象  称之为对象成员
// class A {}
// class B {public: A a};


// 先调用成员对象的构造函数，再调用外层类对象的构造函数
// 析构函数的调用顺序则与之相反

#include<iostream>
#include<string>
using namespace std;

class phone
{
public:
    phone(string phonename, int phoneprice): PhoneName(phonename), PhonePrice(phoneprice)
    {
        cout << "class phone's paramater constructor is calling..." << endl;
    }

    ~phone()
    {
        cout << "class phone's decontructor is calling..." << endl;
    }


public:
    string PhoneName;
    int PhonePrice;
};

class person
{
public:
    person(string name, phone type): Name(name), Type(type)
    {
        cout << "class person's parameter constructor is calling..." << endl;
    }

    ~person()
    {
        cout << "class person's deconstructor is calling..." << endl;
    }


public:
    string Name;
    phone Type;
};

void print(const person &p)
{
    cout << p.Name << " hold on " << p.Type.PhoneName << ". price is: " << p.Type.PhonePrice << endl;
}

int main()
{
    // 我他娘的真是个天才，这里体现出了如果一个类中包含另一个类的对象
    // 则建立构造函数的时候，先建造对象成员的构造函数，再建造外围类对象的构造函数
    phone p1("Apple 12", 4608);
    person p2("Bob", p1);
    print(p2);

    return 0;
}