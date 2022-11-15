#include <iostream>
#include <deque>
using namespace std;

void printDeque(const deque<int>& d)
{
    for (auto it = d.begin(); it != d.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
}

//数据存取
void access()
{
    deque<int> d;
    d.push_back(10);
    d.push_back(20);
    d.push_front(100);
    d.push_front(200);

    // 建议使用迭代器的方式进行元素访问
    for (int i = 0; i < d.size(); ++i) {
        cout << d[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < d.size(); ++i) {
        cout << d.at(i) << " ";
    }
    cout << endl;

    // front访问第一个元素 back访问最后一个元素
    cout << "front:" << d.front() << endl;
    cout << "back:" << d.back() << endl;
}

int main()
{
    access();

    return 0;
}