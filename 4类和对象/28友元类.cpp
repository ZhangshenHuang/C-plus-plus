// 类做友元
// 基本语法：friend class 类名；

#include <iostream>
#include <string>
using namespace std;

class Building
{
    // 类做友元
    // 未使用作用域符号:: 不会出现因为class GoodGay的大小未知而报"使用了未定义类型GoodGay"错误
    friend class GoodGay;
    // friend GoodGay::void access();

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

class GoodGay
{
public:
    void access()
    {
        cout << "Your goodfriend is accessing your: " << building->mSittingRoom << endl;
        cout << "Your goodfriend is accessing your: " << building->mBedRoom << endl;
    }

    ~GoodGay()
    {
        if (building != NULL) {
            delete building;
            building = NULL;
        }
        cout << "Class GoodGay's destructor is calling..." << endl;
    }

private:
    // 若使用此种在堆区开辟一个Building类型的对象，则返回值就是一个指向Building类型对象的指针
    // 相比于在栈区使用指针成员变量，少了具体的初始化操作，简化了代码，但要注意手动释放堆区空间
    Building* building = new Building;

    // 单独使用此行语句是可以的，cout << build.mSittingRoom即可
    // Building build;

    // 若非要使用cout << build->mSittingRoom，且在栈区完成，则需要定义一个指向具体对象的指针变量
    // Building build;
    // Building *building = &build;
};

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