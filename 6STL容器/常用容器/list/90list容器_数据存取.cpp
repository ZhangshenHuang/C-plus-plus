#include <iostream>
#include <list>
using namespace std;

//数据存取
void myTake()
{
    list<int> l1;
    l1.push_back(10);
    l1.push_back(20);
    l1.push_back(30);
    l1.push_back(40);

    // cout << l1.at(0) << endl;//错误 不支持at访问数据
    // cout << l1[0] << endl; //错误  不支持[]方式访问数据
    cout << "第一个元素为： " << l1.front() << endl;
    cout << "最后一个元素为： " << l1.back() << endl;

    // list容器的迭代器是双向迭代器，不支持随机访问
    list<int>::iterator it = l1.begin();
    // it = it + 1;//错误，不可以跳跃访问，即使是+1
}

int main()
{
    myTake();

    return 0;
}