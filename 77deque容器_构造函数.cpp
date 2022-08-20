// 功能：双端数组，既可以对头部，也可以对尾部进行插入删除操作

// deque与vector的区别：
// 1.vector对于头部的插入删除效率低，数据量越大，效率越低
// 2.deque相对而言，对于头部的插入删除速度比vector快
// 3.vector的元素访问速度快于deque，因为vector内部是一整块的数据存储区，而deque内部是一个中控器，记录不同内存块的地址

#include <iostream>
#include <deque>
using namespace std;

void printDeque(const deque<int>& d)
{
    // for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++) {
    for (auto it = d.begin(); it != d.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
}

// deque构造
void conStruct()
{
    deque<int> d1; //无参构造函数
    for (int i = 0; i < 10; i++) {
        d1.push_back(i);
    }
    printDeque(d1);

    deque<int> d2(d1.begin(), d1.end());
    printDeque(d2);

    deque<int> d3(10, 100);
    printDeque(d3);

    deque<int> d4 = d3;
    printDeque(d4);
}

int main()
{
    conStruct();

    return 0;
}