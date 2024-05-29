#include <iostream>
using namespace std;

//全局函数最好做类内实现

//全局函数
template <class t1, class t2>
class person;
template<class t1,class t2>
 void printper2(person<t1, t2> p){
    cout << p.m_name << endl
             << p.m_age << endl;
 }
 
template<class t1,class t2>
class person 
{
    
    //1.全局函数类内实现,加friend后为全局函数
        friend void printper(person<t1,t2> p){
        cout << p.m_name << endl
             << p.m_age << endl;
    }
    //类外实现
    //加空模板参数列表
    //如果全局函数是类外实现，要让编译器知道这个函数的存在
    void friend printper2<>(person<t1, t2> p);
    t1 m_name;
    t2 m_age;

public:
    person(t1 name, t2 age)
    {
        m_name = name;
        m_age = age;
        }
};


int main(){
    person p("cheng",20);
    printper2(p);
}