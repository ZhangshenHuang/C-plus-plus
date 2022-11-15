// 问题引出：在多态中，通常父类中虚函数的实现是毫无意义的，主要是调用子类重写内容
// 解决：将虚函数改为纯虚函数

// 纯虚函数语法：virtual 返回值类型 函数名 （参数列表）= 0；

// 当一个类中有了纯虚函数，这个类被称为抽象类

// 抽象类特点：
// 1.无法实例化对象
// 2.子类必须重写父类（抽象类）中的纯虚函数，否则也属于抽象类



// 使用上节计算器代码

#include <iostream>
#include <string>
using namespace std;

// 抽象的父类
class AbstractCalculator
{
public:
    // 通过在后面补充“ = 0 ”，变为纯虚函数，此时的父类为抽象类，不可实例化对象
    virtual float getResult(float mNum1, float mNum2) = 0;

public:
    float mNum1, mNum2;
};

// 加法类
class AddCalculator : public AbstractCalculator
{
public:
    // 这里子类中重写的父类函数前的virtual可写可不写，只有重写了纯虚函数，这个子类才可以实例化对象
    virtual float getResult(float mNum1, float mNum2)
    {
        return mNum1 + mNum2;
    }
};

// 减法类
class SubCalculator : public AbstractCalculator
{
public:
    float getResult(float mNum1, float mNum2)
    {
        return mNum1 - mNum2;
    }
};

// 乘法类
class MulCalculator : public AbstractCalculator
{
public:
    float getResult(float mNum1, float mNum2)
    {
        return mNum1 * mNum2;
    }
};

// 除法类
class DivCalculator : public AbstractCalculator
{
public:
    float getResult(float mNum1, float mNum2)
    {
        return mNum1 / mNum2;
    }
};

// 实现了一个简易的二元素四则运算计算器，但除法运算时，除数为负数有问题
void calculate()
{
    float num1, num2;
    string oper, selection;
    // 在堆区开辟了一块内存 父类类型的指针 指向 子类     反之子类类型的指针 不可以指向 父类
    // 父类中有的子类中都有，反之子类中有的父类中不一定有
    AbstractCalculator* ptr = new AddCalculator;

    cout << "Please enter a expression, separate with space: " << endl;
    
    while (cin >> num1 >> oper >> num2) {
        if (oper == "+") {
            ptr = new AddCalculator;  //ptr指向AddCalculator类
            cout << num1 << " + " << num2 << " = " << ptr->getResult(num1, num2) << endl; //p->func() == (*p).func() !!!
        } else if (oper == "-") {
            ptr = new SubCalculator;  //指针指向的数据类型仍为 AbstractCalculator 类型
            cout << num1 << " - " << num2 << " = " << (*ptr).getResult(num1, num2) << endl; //getResult()为 SubCalculator的，而不是父类的
        } else if (oper == "*") {
            // ptr = new MulCalculator;
            MulCalculator mul1;
            cout << num1 << " * " << num2 << " = " << mul1.getResult(num1, num2) << endl;
        } else if (oper == "/" && num2 != 0) {
            ptr = new DivCalculator;
            cout << num1 << " / " << num2 << " = " << ptr->getResult(num1, num2) << endl;
        } else {
            cout << "Error input!" << endl;
        }
        cout << "Again?(Press y or Y), Over?(Press any other buttons)" << endl;
        cin >> selection;
        if (selection != "y" && selection != "Y") {
            delete ptr;
            ptr = nullptr;
            break;
        } else {
            cout << "Please enter a expression again, separate with space: " << endl;
        }
    }
}

int main()
{
    calculate();

    return 0;
}