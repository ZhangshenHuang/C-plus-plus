#include <iostream>
#include <string>
using namespace std;

void myPair()
{
    // 1.有参构造函数形式创建
    pair<string, int> p1("Herry", 18);
    cout << "Name is:" << p1.first << " Age is:" << p1.second << endl;

    // 2.make_pair()函数创建
    pair<string, int> p2 = make_pair("Tom", 20);
    cout << "Name is:" << p2.first << " Age is:" << p2.second << endl;
}

int main()
{
    myPair();

    return 0;
}