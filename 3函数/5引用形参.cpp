/* // 使用引用完成对两个数字的交换
// 尽量多使用引用类型的形参代替指针
#include<iostream>
using namespace std;

int change(int &a, int &b)
{
    int c;
    c = a;
    a = b;
    b = c;
    return 0;
}

int main() 
{
    int x, y;
    cout << "Please input two number: " << endl;
    cin >> x >> y;
    change(x, y);
    cout << "Change result is: " << x << " " << y << endl;
    return 0;
} */



// 使用引用完成字符串内字符的查找，返回字符首次出现索引以及出现总次数
#include<iostream>
#include<string>
using namespace std;

unsigned search(const string s, const char c, string::size_type &index)
{
    unsigned num = 0;
    index = s.size();
    for(auto i = 0; i != s.size(); ++i)
    {
        if(s[i] == c)
        {
            if(index == s.size())
            {
                index = i;
            }
            ++num;
        }
    }
    return num;
}

// 索引index需要使用string::size_type, num不需要
int main()
{
    string::size_type Index = 0;
    unsigned Num = search("Hello World!", 'z', Index);
    cout << "'z' Num is: " << Num << "  " << "'z' first occur index is: " << Index << endl;
    return 0;
}