#include <map>
#include <iostream>

using namespace std;

struct Student
{
    int age;
    string name;
    Student(int a,string n):age(a),name(n){}
};

int main()
{
    map<int,Student> ss;
    Student s1 = {10,"hello"};
    ss.insert(pair<int,Student>(1,s1));
    cout <<ss[1].name<<endl;
    
    map<int,string> sts;
    sts.insert(pair<int,string>(233,"world"));
    string st = sts[233];
    cout <<st<<endl;
}
