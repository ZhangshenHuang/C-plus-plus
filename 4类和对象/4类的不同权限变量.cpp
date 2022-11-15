#include<iostream>
#include<string>
using namespace std;

class person
{
    // 公共权限，类内可以，类外可以
    public:
    string name;

    // 保护权限，类内可以，类外不可以
    protected:
    string asset;

    // 私有权限，类内可以，类外不可以
    private:
    string bank_code;

    public:
    void func()
    {
        name = "Bob";
        asset = "BMW";
        bank_code = "123456";
    }
};

int main()
{
    person p1;
    p1.name = "Jerry";
    // p1.asset = "Ben Chi";
    // p1.bank_code = "654321";
    
    return 0;
}