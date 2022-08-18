// 再次感受多态的魅力
// 提供抽象饮品制作基类，提供咖啡和茶的制作子类

// 关于多态更多的一点理解：
// 子类中的公共部分写在抽象父类中，子类进行继承，同时具体到每个子类具体的内容又不同
#include <iostream>
#include <string>
using namespace std;

// 抽象父类
class AbstractDrinking
{
public:
    virtual void boil() = 0;
    virtual void brew() = 0;
    virtual void pourCup() = 0;
    virtual void ingredient() = 0;

    // 这个函数使用十分妙，将每个子类需要执行的函数写在一起，子类进行继承
    void makingProcess()
    {
        // 这里千万不能添加void 否则变成函数声明
        boil();
        brew();
        pourCup();
        ingredient();
    }
};

class Coffee : public AbstractDrinking
{
public:
    // 这里的virtual可写可不写
    virtual void boil()
    {
        cout << "Firstly, please boiling pure water..." << endl;
    }

    virtual void brew()
    {
        cout << "Secondly, please brewing coffee!" << endl;
    }

    virtual void pourCup()
    {
        cout << "Thirdly,please pouring your coffee into glass cup~" << endl;
    }

    virtual void ingredient()
    {
        cout << "Fourthly, Would you want to add some sugar?" << endl;
    }
};

class Tea : public AbstractDrinking
{
public:
    virtual void boil()
    {
        cout << "Firstly, please boiling spring water..." << endl;
    }

    virtual void brew()
    {
        cout << "Secondly, please brewing tea!" << endl;
    }

    virtual void pourCup()
    {
        cout << "Thirdly,please pouring your tea into vacuum cup~" << endl;
    }

    virtual void ingredient()
    {
        cout << "Fourthly, Would you want to add some lemon?" << endl;
    }
};

void drinkMaking(AbstractDrinking* abstractDrinking)
{
    abstractDrinking->makingProcess(); //子类中的makingProcess(),继承自父类
    if (abstractDrinking != nullptr) {
        delete abstractDrinking;
        abstractDrinking = nullptr;
    }
}

int main()
{
    cout << "************This is the making method of tea***************" << endl;
    drinkMaking(new Tea);
    cout << endl;
    
    cout << "************This is the making method of tea***************" << endl;
    drinkMaking(new Coffee);

    return 0;
}