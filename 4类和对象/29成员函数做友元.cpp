// 成员函数做友元
// 注意成员函数要写在类外！！！
// 基本语法：friend object::void func();

#include <iostream>
#include <string>
using namespace std;
class Building; //此声明必须，不然class GoodGay里面的Building的类型无法被识别 仅仅是声明，而非定义！！！

class GoodGay
{
public:
    void access();

    GoodGay();

    ~GoodGay()
    {
        if (building != NULL) {
            delete building;
            building = NULL;
        }
        cout << "Class GoodGay's destructor is calling..." << endl;
    }

private:
    /******************************************************************************************************************************/
    // 为什么这里仅仅只定义一个Building类型的指针呢？而不对这个指针指向的值进行初始化呢？
    // 因为指针的大小是恒定的，64位系统中为4字节，这时候class GoodGay的大小是已知的，不会因为未知class Building的实际大小而引发内存申请错误
    // 虽然在此class之前进行了class Building的声明，但仅仅只是声明，并不是初始化，class Building的大小在此处仍为未知！！！
    // 所以将对其他类类型的指针成员变量的初始化利用构造函数放在class外部！！！
    // 只能使用这个类型的引用或者指针！！！！！
    /******************************************************************************************************************************/
    Building* building;
    // 像如下编写则会报错，在一个类没有定义好之前，是不可以进行对象的实例化的！！！！！！！！！！！
    // Building *building = new Building;
};

class Building
{
    // 成员函数做友元
    friend void GoodGay::access();

public:
    Building()
    {
        mSittingRoom = "sitting room";
        mBedRoom = "bed room";
    }

public:
    string mSittingRoom;

private:
    string mBedRoom;
};

// 构造函数置于类外，可读性差
GoodGay::GoodGay()
{
    building = new Building;
}

void GoodGay::access()
{
    cout << "Your goodfriend is accessing your: " << building->mSittingRoom << endl;
    cout << "Your goodfriend is accessing your: " << building->mBedRoom << endl;
}

void test01()
{
    GoodGay g1;
    g1.access();
    // 在执行完此函数体内语句后才执行GoodGay的析构函数
}

int main()
{
    test01();

    return 0;
}