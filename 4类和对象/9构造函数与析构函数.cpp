#include<iostream>
using namespace std;

class person
{
public:

    // 构造函数，可以有形参
    person()
    {
        cout << "Construcor!" << endl;
    }

    // 析构函数，无形参
    ~person()
    {
        cout << "Destructor!" << endl;  
    }
};

void test()
{
    person p;
}

int main()
{
    // 在栈上的数据
    person p;
    // test();
    system("pause");
    return 0;
}