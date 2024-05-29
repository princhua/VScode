#include <iostream>
using namespace std;

// 重载= ;(涉及深浅拷贝问题)
// 成员函数重载
// 2.全局函数重载+
class person
{
    //friend ostream &operator<<(ostream &bbb, person &p);
    friend void test();

private:

    
public:

    //重载=赋值运算符
    person& operator=(person &p){
        // 编译器提供浅拷贝
        // age=p.age;(地址)
        //判断是否有数据在堆区域，如果有先释放
        if(age!=NULL)
        {
            delete age;
            age = NULL;
        }
        age = new int(*p.age);
        return *this;
    }

int *age;

person(int age){
    this->age = new int (age);
}
~person(){
    delete age;
};

// int m_a;
// int m_b;
//成员函数重载+
// person operator+(person &p){
//     person temp;
//     temp.m_a = this->m_a+p.m_a;
//     temp.m_b = this->m_b+p.m_b;
//     return temp;
// }

//成员函数重载<<

//     void operator<<(cout) // 简化版本：p<< cout;所以一般不用成员函数重载<<
//     {

// }

    
};

//重载递增运算符
class Myint
{
    friend ostream &operator<<(ostream &bbb, Myint &p);

private:
    int m_num;

public:
    //重载前置++
    Myint& operator++()
    {
        m_num++;
        //先自身+1，返回自身
        return *this;
    }

    //重载后置++
    Myint operator++(int)//int表示占位参数，用于区分两个函数，让编译器可以重载
    {
        //返回自身,然后加1
        Myint temp = *this;
        m_num++;
        return temp;
    }



   Myint(){
        m_num = 0;
    }
};


//全局函数重载+
// person operator+(person &p1,person &p2){
//     person temp;
//     temp.m_a = p1.m_a + p2.m_a;
//     temp.m_b = p1.m_b + p2.m_b;
//     return temp;
// }

// person operator+(person &p1,int a){
//     person temp;
//     temp.m_a = p1.m_a + a;
//     temp.m_b = p1.m_b + a;
//     return temp;
// }

//全局函数重载左移<<
ostream& operator<<(ostream &bbb,Myint &p)
//本质 operator<<(cout,p)简化 cout <<p
{
    cout << "m_num=" << p.m_num ;
    return bbb;
}

// void test(){
//     person p1;
//     //person p2;
//     p1.m_a = 10;
//     p1.m_b = 10;
//     // p2.m_a = 10;
//     // p2.m_b = 10;

//     // //等价于 person p3 = p1.operator+(p2);
//     // //全局重载等价于 person p3 = operator+(p1,p2);
//     // person p3 = p1 + p2;

//     // //运算符重载也发生函数重载
//     // person p4 = p1 + 11;
//     // cout << p4.m_a << endl;
//     cout << p1 << endl;
// }

void test02(){
    Myint abfs;
    // cout <<++(++inta)<< endl;
     Myint t = abfs++;
    cout << t << endl;
    cout << abfs << endl;
}

void test03(){
    person p1(18);
    person p2(22);
    person p3(25);
    p3 = p1 = p2;//隐式转换法拷贝构造
    //如果拷贝数据在堆区，会出现浅拷贝问题
    cout << *p1.age<<endl;
    cout << *p2.age<<endl;
    cout << *p3.age<<endl;
}


int main(){
    test03();
}