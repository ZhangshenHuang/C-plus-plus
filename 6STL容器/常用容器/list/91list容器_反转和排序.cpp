#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

void printList(const list<int>& l)
{
    for (list<int>::const_iterator it = l.begin(); it != l.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
}

// 使用此种方法实现降序排列暂时不太理解
bool compare(int val1, int val2)
{
    return val1 > val2;
}

void mySort()
{
    list<int> l1 = {12, 3, 88, 1, 8};

    cout << "Before sort: " << endl;
    printList(l1);

    cout << "After sort: " << endl;
    // 不支持随机访问迭代器的容器，内部会提供对应的一些算法，使用成员函数
    l1.sort();  //默认升序
    // 所有不支持随机访问迭代器的容器，不可以用标准算法
    // sort(l1.begin(), l1.end());
    printList(l1);

    cout << "using compare() realize ascend order: " << endl;
    l1.sort(compare);
    printList(l1);

    cout << "After reverse: " << endl;
    l1.reverse();  //reverse()反转实现降序
    printList(l1);
}

int main()
{
    mySort();

    return 0;
}