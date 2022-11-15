#include <iostream>
#include <list>
using namespace std;

void printList(const list<int>& l)
{
    for (list<int>::const_iterator iter = l.begin(); iter != l.end(); ++iter) {
        cout << *iter << " ";
    }
    cout << endl;
}

void myList()
{
    // 默认构造
    list<int> l1;
    l1.push_back(2);
    l1.push_front(1);
    l1.push_back(3);
    l1.push_back(4);
    printList(l1);

    // 区间构造
    list<int> l2(l1.begin(), l1.end());
    printList(l2);

    // n个elements构造
    list<int> l3(10, 45);
    printList(l3);

    // 拷贝构造
    list<int> l4(l3);
    printList(l4);
}

int main()
{
    myList();

    return 0;
}