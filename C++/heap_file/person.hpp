#pragma once
#include <iostream>
using namespace std;

template<class t1,class t2>
class person
{
     public:
        person(t1 name, t2 age);
        friend void show();
        t1 m_name;
        t2 m_age;
};

template<class t1,class t2>
person<t1,t2>::person(t1 name, t2 age){
    m_name = name;
    m_age = age;
}

//2.类外实现
template<class t1,class t2>
void show(){
    cout << m_name << endl;
}