#include<iostream>
#include<string>
using namespace std;

// 这里形参定义为常量非引用
bool judge(const string s)
{
    unsigned Count = 0;
    for(auto c : s)
    {
        if(isupper(c))
        {
            return true;
        }
    }
    return false;
}

// 这里形参定义为常量非引用
unsigned count(const string s)
{
    unsigned Count = 0;
    for(auto c : s)
    {
        if(isupper(c))
        {
            ++Count;
        }
    }
    return Count;
}

// 这里形参定义为非常量引用
unsigned upper(string &s)
{
    for(auto &c : s)
    {
        if(!isupper(c))
        {
            c = toupper(c);
        }
    }
    return 0;
}

int main()
{
    cout << "Please input the goal string: " << endl;
    string s;
    getline(cin, s); //使用getline()函数可以输入带空格的字符串，若使用cin则以空格为分隔
    cout << "Are there any upper alphabet in your enter string? " << judge(s) << endl;
    cout << "The number of upper alphabet in your enter string is: " << count(s) << endl;
    upper(s);
    cout << "After upper option, the string is: " << s << endl;
    return 0;
}