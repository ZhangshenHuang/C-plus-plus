// 函数调用运算符()重载
// 由于重载后的使用方式非常像函数的调用，因此称为仿函数
// 仿函数写法不固定，灵活性较高

#include <iostream>
#include <string>
using namespace std;

class MyAdd
{
public:
    MyAdd(int num1, int num2)
    {
        mNum1 = num1;
        mNum2 = num2;
    }

    void operator()()
    {
        cout << "Num is: " << this->mNum1 + this->mNum2 << endl;
    }

private:
    int mNum1, mNum2;
};

void test01()
{
    MyAdd number(12, 13);
    number.operator()();
}

int main()
{
    test01();

    return 0;
}