// 友元：让类外的一些函数或者类访问类内的private成员
// 关键字：friend

// 友元的三种实现：
// 1.全局函数做友元
// 2.类做友元
// 3.成员函数做友元

#include <iostream>
#include <string>
using namespace std;

class Building
{
    // 声明goodGay是友元，可以访问类中的private成员
    friend void goodGay(Building* building);

public:
    Building()
    {
        mSittingRoom = "sitting room";
        mBedRoom = "bedroom";
    }

public:
    string mSittingRoom;

private:
    string mBedRoom;
};

// 形参使用指针或者引用都可以，换着习惯使用
void goodGay(Building* building)
{
    cout << "Your goodGay is accessing your: " << building->mSittingRoom << endl;
    cout << "Your goodGay is accessing your: " << building->mBedRoom << endl;
}

void test01()
{
    Building b1;
    goodGay(&b1);
}

int main()
{
    test01();

    return 0;
}