// string substr(int pos = 0, int n = npos) const; 返回由pos开始的n个字符组成的字符串

#include <iostream>
#include <string>
using namespace std;

void userName()
{
    string email = "WangWu@sina.com";
    int position = email.find("@");
    cout << "position = " << position << endl;

    string name = email.substr(0,position);
    cout << "name is: " << name << endl;
}

int main()
{
    userName();

    return 0;
}