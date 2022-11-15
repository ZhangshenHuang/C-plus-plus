#include<iostream>
#include<string>
using namespace std;

class person
{
public:

    // 姓名可读可写
    void set_name(string s_name)
    {
        name = s_name;
    }
    string get_name()
    {
        return name;
    }

    // age 只读
    int get_age()
    {
        return age;
    }

    // 情人只可写
    int set_lover(string s_lover)
    {
        if(s_lover.size() > 10)
        {
            cout << "Lover input error! " << endl;
            return -1;
        }
        lover = s_lover;
        return 0;
    }

// 将所有成员属性设置为私有，可以自己控制读写权限
// 对于写权限，可以检测数据的有效性
private:

    string name;
    int age = 69;
    string lover;
};

int main()
{
    person p1;
    p1.set_name("Herry");
    cout << "The name you set is: " << p1.get_name() << endl;
    cout << p1.get_name() << "'s age is: " << p1.get_age() << endl;
    p1.set_lover("Curry");
}