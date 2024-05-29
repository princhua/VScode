#include <iostream>
using namespace std;

//如果父类是类模板，子类需要制定出父类中T数据类型
template<class t>
class base
{
    //public:
    t m;
};

// class son:public base<int>//告诉编译器父类类型，以得出所占内存
// {
// public:
// };

//如果要灵活指定父类中T类型，子类也需要变类模板
template<class t2,class t1>
class son2:public base<t2>
{
    public:
    son2(){
        cout << typeid(t2).name()<<endl;
        cout << typeid(t1).name()<<endl;
    }
    t1 a;
};

//函数类外实现
template<class t1,class t2>
class person
{
    public:
        person(t1 name, t2 age);
        void show();
        t1 m_name;
        t2 m_age;
};

//1.类外实现时要加上模板的参数列表
template<class t1,class t2>
person<t1,t2>::person(t1 name, t2 age){
    m_name = name;
    m_age = age;
}

//2.类外实现
template<class t1,class t2>
void person<t1,t2>::show(){
    cout << m_name << endl;
}

int main(){

    //son2<int, char> child1;

    
    //person p1("tom",20);
    person<string,int> p1("tom",20);
    p1.show();
}