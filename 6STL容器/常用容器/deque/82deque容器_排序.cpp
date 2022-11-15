#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>
using namespace std;

void printDeque(const deque<int>& d)
{
    for (auto it = d.begin(); it != d.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
}

void printVector(const vector<int>& v)
{
    for (auto it = v.begin(); it != v.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
}

void mySort()
{
    deque<int> d = {23, 5, 90, 100};
    cout << "Before sort:" << endl;
    printDeque(d);

    cout << "After sort:" << endl;
    sort(d.begin(), d.end());
    printDeque(d);

    // 对于支持随机访问的迭代器的容器，都可以利用sort算法直接对其进行排序
    // sort默认支持升序
    // vector容器也支持sort算法
    vector<int> v = {293, 56, 970, 1200};
    cout << "Before sort:" << endl;
    printVector(v);

    cout << "After sort:" << endl;
    sort(v.begin(), v.end());
    printVector(v);
}

int main()
{
    mySort();

    return 0;
}