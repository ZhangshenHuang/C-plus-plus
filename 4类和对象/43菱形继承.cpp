// 菱形继承（钻石继承）的概念：两个子类继承了同一个父类，同时又有某个类同时继承两个子类
// 利用虚继承解决菱形继承问题

#include <iostream>
using namespace std;

class Animal
{
public:
    int mAge;
};

// 继承前添加virtual关键字后变为虚继承，此时公共的父类Animal称为虚基类
class Sheep : virtual public Animal {};
class Camel : virtual public Animal {};
class GrassHorse : public Sheep, public Camel {};

void test01()
{
    GrassHorse gh1;
    gh1.Sheep::mAge = 20;
    gh1.Camel::mAge = 30;

    cout << "gh1.Sheep::mAge = " << gh1.Sheep::mAge << endl;
    cout << "gh1.Camel::mAge = " << gh1.Camel::mAge << endl;

    // 此时GrassHorse中有两个年龄数据，如果直接访问会出错，通过在对基类的继承过程中添加virtual关键字变为虚继承 解决
    cout << "gh1.mAge = " << gh1.mAge << endl;
}

int main()
{
    test01();

    return 0;
}