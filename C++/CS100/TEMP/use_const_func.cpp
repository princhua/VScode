#include <iostream>
using namespace std;

class person
{
public:
person (){

}
    void show_class(){
        cout << "this is person class" << endl;

    }
        void show_age(){
        cout << "this is age" <<m_age <<endl;//此处 m_age=this->m_age

    }
    void showa()const//常函数
    //a=200相当于this->a=200
    //this相当于class *const p,
    //函数（）后加const相当于class const*const p 都不可修改
    {
        a = 200;
    }
    void show_age(){
        cout << "this is age" <<m_age <<endl;//此处 m_age=this->m_age

    }
    int m_age;
    mutable int a;//加上mutable后就可变
};

//常对象
void test02(){
    const person  p;
    //常对象只能调用常函数
    //p.m_age = 10;
    // p.show_age();常对象不能修改值
}



void test(){
    person *p = NULL;
   
    p->show_class();
     p->show_age();
}

int main(){
    test();
}