#include<iostream>
#include<string>
using namespace std;

class student
{
    public:

    string name;
    string number;

    void display()
    {
        cout << name << "' number is: " << number << endl;
    }

    void setname(string s_name)
    {
        name = s_name;
    }

    void setnumber(string s_number)
    {
        number = s_number;
    }
};

int main()
{
    student s1, s2, s3;
    cout << "Please input student name and number: " << endl;
    cin >> s1.name >> s1.number >> s2.name >> s2.number;
    s1.display();
    s2.display();

    s3.setname("De Ma Xi Ya!");
    s3.setnumber("202122011112");
    s3.display();
    return 0;
}