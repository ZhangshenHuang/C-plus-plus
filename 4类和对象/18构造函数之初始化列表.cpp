// 初始化列表语法用来初始化属性
// 语法：构造函数：属性1（值1），属性2（值2），...{}

#include<iostream>
using namespace std;

class person
{
public:
    // 在设置构造函数的时候顺便把属性值给初始化了，简洁了函数体内部，为大型程序做铺垫
    person(int age1, int age2, int age3): Age1(age1), Age2(age2), Age3(age3)  //这里后面没有什么符号，要注意
    {
        cout << "parameter constructor is calling..." << endl;
    }

    void print(const person &p)
    {
        cout << "p.Age1 is: " << p.Age1 << endl;
        cout << "p.Age2 is: " << p.Age2 << endl;
        cout << "p.Age3 is: " << p.Age3 << endl;
    }


private:
    int Age1, Age2, Age3;
};

int main()
{
    person p1(12, 23, 56);
    p1.print(p1);

    return 0;
}