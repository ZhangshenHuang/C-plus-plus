#include <iostream>
#include <string>
using namespace std;

void test01()
{
    string str = "hello world";

    // 尽量使用迭代器进行操作
    for (int i = 0; i < str.size(); i++) {
        cout << str[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < str.size(); i++) {
        cout << str.at(i) << " ";
    }
    cout << endl;

    //字符修改  at方式并不常见
    str[0] = 'x';
    str.at(1) = 'x';
    cout << str << endl;
}

int main()
{

    test01();

    // system("pause");

    return 0;
}