// set容器默认升序排序
// 利用仿函数，改变排序规则

#include <iostream>
#include <set>
using namespace std;

class MyCompare
{
public:
    // C++17要求添加const修饰
    bool operator()(int v1, int v2) const
    {
        return v1 > v2;
    }
};

void printAscend(set<int>& s)
{
    for (set<int>::iterator it = s.begin(); it != s.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
}

void printDescend(set<int, MyCompare>& s)
{
    for (set<int, MyCompare>::iterator it = s.begin(); it != s.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
}

void ascend()
{
    set<int> s1;
    //插入
    s1.insert(10);
    s1.insert(30);
    s1.insert(20);
    s1.insert(40);
    printAscend(s1);
}

void descend()
{
    set<int, MyCompare> s2;
    //插入
    s2.insert(10);
    s2.insert(30);
    s2.insert(20);
    s2.insert(40);
    printDescend(s2);
}

int main()
{
    ascend();
    descend();

    return 0;
}