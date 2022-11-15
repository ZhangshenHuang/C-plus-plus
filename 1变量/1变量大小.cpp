#include<iostream>
#include<string>
using namespace std;
int main()
{
    cout << "The size of int is: " << sizeof(int) << endl;
    cout << "The size of unsigned is: " << sizeof(unsigned) << endl;
    cout << "The size of char is: " << sizeof(char) << endl;
    cout << "The size of string is: " << sizeof(string) << endl;

    char *p;
    cout << sizeof(p) << endl;
    return 0;
}