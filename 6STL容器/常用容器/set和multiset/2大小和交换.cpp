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

//大小
void mySize()
{

    set<int> s1;

    s1.insert(10);
    s1.insert(30);
    s1.insert(20);
    s1.insert(40);

    if (s1.empty()) {
        cout << "s1为空" << endl;
    } else {
        cout << "s1不为空" << endl;
        cout << "s1的大小为: " << s1.size() << endl;
    }
}

//交换
void mySort()
{
    set<int> s1;

    s1.insert(10);
    s1.insert(30);
    s1.insert(20);
    s1.insert(40);

    set<int> s2;

    s2.insert(100);
    s2.insert(300);
    s2.insert(200);
    s2.insert(400);

    cout << "交换前" << endl;
    printSet(s1);
    printSet(s2);
    cout << endl;

    cout << "交换后" << endl;
    // 两种交换方式的写法均可
    // s1.swap(s2);
    swap(s1, s2);
    printSet(s1);
    printSet(s2);
}

int main()
{
    // mySize();
    mySort();

    return 0;
}