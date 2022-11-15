#include <iostream>
#include <deque>
using namespace std;

void printDeque(const deque<int>& d)
{
    for (auto it = d.begin(); it != d.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
}

//大小操作
void readSize()
{
    deque<int> d1;
    for (int i = 0; i < 10; i++) {
        d1.push_back(i);
    }
    printDeque(d1);

    //判断容器是否为空
    if (d1.empty()) {
        cout << "d1为空!" << endl;
    } else {
        cout << "d1不为空!" << endl;
        //统计大小
        cout << "d1的大小为:" << d1.size() << endl;
    }

    // 注意没有容量capacity()的概念，与vector不同的地方

    //重新指定大小
    d1.resize(15, 1);
    printDeque(d1);

    d1.resize(5);
    printDeque(d1);
}

int main()
{
    readSize();

    return 0;
}