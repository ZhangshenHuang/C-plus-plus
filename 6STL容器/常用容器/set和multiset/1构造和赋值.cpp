#include <iostream>
#include <set>
using namespace std;

void printSet(set<int>& s)
{
    for (set<int>::iterator it = s.begin(); it != s.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
}

//构造和赋值  set容器的底层是由二叉树实现的
void myConstruct()
{
    set<int> s1;

    // 使用insert插入数据，没有push操作函数 内部自动升序排序
    s1.insert(10);
    s1.insert(30);
    s1.insert(20);
    s1.insert(40);
    printSet(s1);

    //拷贝构造
    set<int> s2(s1);
    printSet(s2);

    //赋值
    set<int> s3;
    s3 = s2;
    printSet(s3);
}

int main()
{
    myConstruct();

    return 0;
}