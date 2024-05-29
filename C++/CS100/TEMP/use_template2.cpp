#include <iostream>
using namespace std;

template <class t1,class t2>
class person
{
    public:
    person(t1 name,t2 age){
        m_name = name;
        m_age = age;
    }
    t1 m_name;
    t2 m_age;
    void show(){
        cout << m_name<<endl
        <<m_age << endl;
    }
};

// class person2
// {
//     public:
//     void show2(){
//         cout << "person2 show" << endl;
//     }
// };
// //类模板成员函数在调用时才会创建

// template <class T>
// class myclass
// {
//     public:
//         T obj;
//         void func1(){
//             obj.show1();
//         }
//         void func(){
//             obj.show2();
//         }
//         myclass(){

//         };
// };


    //类模板做函数参数
    //1.指定传入类型 (常用)
void printper(person<string,int> &p){
    p.show();
}
    //2.参数模板化
    template <class t1,class t2>
void printper1(person<t1,t2> &p){
    p.show();
    cout << typeid(t2).name()<< endl;
}
    //整个类模板化
        template <class t>
void printper2(t &p){
    p.show();
    cout << typeid(t).name()<< endl;
}


int main(){
    // myclass<person1>m;
    // m.func1();
    // ////m.func();

    // person<string,int> p("cheng", 100);
    // printper(p);

    // person<string,int> p("cheng", 100);
    // printper1(p);

    person<string,int> p("chng", 100);
    printper2(p);
}