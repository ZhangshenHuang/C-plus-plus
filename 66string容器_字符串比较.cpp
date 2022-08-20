#include <iostream>
#include <string>
using namespace std;

//字符串比较
void test01()
{
    string s1 = "hello";
    string s2 = "aello";

    int ret = s1.compare(s2);

    if (ret == 0) {
        cout << "s1 等于 s2" << endl;
    } else if (ret > 0) {
        cout << "s1 大于 s2" << endl;
    } else {
        cout << "s1 小于 s2" << endl;
    }
}

// 即使需要比较字符串大小，也使用下面这种方式更为简单便捷
void test02()
{
    string s1 = "hello";
    string s2 = "aello";

    if (s1 == s2) {
        cout << "s1 等于 s2" << endl;
    } else if (s1 > s2) {
        cout << "s1 大于 s2" << endl;
    } else {
        cout << "s1 小于 s2" << endl;
    }
}

int main()
{

    // test01();
    test01();
    // system("pause");

    return 0;
}