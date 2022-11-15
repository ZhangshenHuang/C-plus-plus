#include <iostream>
#include <list>
using namespace std;

void printList(const list<int>& l)
{
    for (list<int>::const_iterator it = l.begin(); it != l.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
}

//插入和删除
void myInsert()
{
    list<int> l;
    //尾插
    l.push_back(10);
    l.push_back(20);
    l.push_back(30);
    //头插
    l.push_front(100);
    l.push_front(200);
    l.push_front(300);

    printList(l);

    //尾删
    l.pop_back();
    printList(l);

    //头删
    l.pop_front();
    printList(l);

    //插入
    list<int>::iterator it = l.begin();
    l.insert(++it, 1000);
    printList(l);

    //删除
    it = l.begin();
    l.erase(++it);
    printList(l);

    //移除
    l.push_back(10000);
    l.push_back(10000);
    l.push_back(10000);
    printList(l);

    // remove为删除所有相同元素
    l.remove(10000);
    printList(l);

    //清空
    l.clear();
    printList(l);
}

int main()
{
    myInsert();

    return 0;
}