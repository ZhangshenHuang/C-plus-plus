// 多态的优点：
// 代码组织结构清晰
// 可读性强
// 利于前期和后期的扩展以及维护

#include <iostream>
#include <string>
using namespace std;

// 抽象的父类
class AbstractCalculator
{
public:
    virtual float getResult(float mNum1, float mNum2)
    {
        return 0;
    }

public:
    float mNum1, mNum2;
};

// 加法类
class AddCalculator : public AbstractCalculator
{
public:
    float getResult(float mNum1, float mNum2)
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