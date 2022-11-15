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

//赋值
void myAssign()
{
    list<int> l1;
    l1.push_back(10);
    l1.push_back(20);
    l1.push_back(30);
    l1.push_back(40);
    printList(l1);

    //赋值
    list<int> l2;
    l2 = l1;
    printList(l2);

    list<int> l3;
    l3.assign(l2.begin(), l2.end());
    printList(l3);

    list<int> l4;
    l4.assign(10, 100);
    printList(l4);
}

//交换
void mySwap()
{

    list<int> l1;
    l1.push_back(10);
    l1.push_back(20);
    l1.push_back(30);
    l1.push_back(40);

    list<int> l2;
    l2.assign(10, 100);

    cout << "交换前： " << endl;
    printList(l1);
    printList(l2);

    cout << endl;

    // l1.swap(l2); //两种交换方式都可以
    swap(l1, l2);
    cout << "交换后： " << endl;
    printList(l1);
    printList(l2);
}

int main()
{
    // myAssign();
    mySwap();

    return 0;
}