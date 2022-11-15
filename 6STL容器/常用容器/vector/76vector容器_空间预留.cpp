// reserve(int len)； 预留len个元素长度的空间，不初始化，不可被访问
// 减小vector在动态扩展容量时的扩展次数

#include <iostream>
#include <vector>
#include <string>
using namespace std;

void notReserve()
{
    char* p = nullptr;
    int num1 = 0;
    vector<char> v1;
    for (int i = 0; i < 1000000; i++) {
        v1.push_back(i);
        if (p != &v1[0]) {
            p = &v1[0];
            ++num1;
        }
    }
    cout << "num1 = " << num1 << endl;
}

void useReserve()
{
    char* p = nullptr;
    int num2 = 0;
    vector<char> v1;
    // 一次性预留足够的空间
    v1.reserve(1000000);
    for (int i = 0; i < 1000000; i++) {
        v1.push_back(i);
        if (p != &v1[0]) {
            p = &v1[0];
            ++num2;
        }
    }
    cout << "num2 = " << num2 << endl;
}

int main()
{
    notReserve();
    useReserve();

    return 0;
}