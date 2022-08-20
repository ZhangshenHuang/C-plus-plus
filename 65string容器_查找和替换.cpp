#include <iostream>
#include <string>
using namespace std;

//查找和替换
void test01()
{
    //查找
    string str1 = "abcdefgde";

    int pos = str1.find("de");

    if (pos == -1) {
        cout << "未找到" << endl;
    } else {
        cout << "pos = " << pos << endl;
    }

    // rfind从右往左查找，但是下标仍然为从左向右标定的
    pos = str1.rfind("de");

    cout << "pos = " << pos << endl;
}

void test02()
{
    //替换  replace(开始位置，替换字符数，替换内容)
    string str1 = "abcdefgde";
    // 将bcd替换为1111
    str1.replace(1, 3, "1111");

    cout << "str1 = " << str1 << endl;
}

int main()
{

    test01();
    // test02();

    // system("pause");

    return 0;
}