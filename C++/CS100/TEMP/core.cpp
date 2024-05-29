#include <iostream>
using namespace std;

//深拷贝：在堆区域开辟一段内存，防止重复释放
//浅拷贝：简单赋值操作
//class属性有开辟在堆区域的就要用深拷贝

class person
{

public:
    person(){

        cout << "construct call" << endl;
    };
    person(int a,int h){
        age = a;
        
        height=new int(h) ;
        cout << "construct call with prameter" << endl;
    };
    ~person(){
        if(height!=NULL){
            delete height;
        }
        cout << "release call" << endl;
    };
    person(const person &a){
        age = a.age;
        // height=a.height; 编译器提供的构造函数
        //深拷贝操作
        int *p1 = new int(*a.height);
        height = p1;
        cout << "definition copy construct call" << endl;
    }

        // 拷贝构造！！！！要加引用
        //  person(const person &p){
        //      age = p.age;
        //      cout << "copy construct call" << endl;
        //  }
        int age;
    int *height;
    student stu;
};

class student
{

public:
    int a;
    int b;
    int c;
    // student (int aa,int bb,int cc){
    //     a = aa;
    //     b=bb;
    //     c = cc;
    // }
    student(int aa,int bb,int cc):a(aa),b(bb),c(cc)
    {

    }
};




//调用
void test(){
    // person p1;
    // person p2(10);
    // person p3(p2);
    // cout << p3.age<<endl;

    //person p1();//默认构造不要加括号，会被看作函数声明

    //2.显示法
    // person p2 = person(10);
    // person p3 = person(p2);
    //person(10);
    //显示法右侧为匿名对象、、当动作结束时自动释放
    //person(p3);
    //不要用拷贝构造创建匿名对象

    //隐式转化法
    // person p4 = 10;//相当于person p4 = person(10)
    // person p5 = p4;
    // cout << "11111111111" << endl;


    // person p1(18,160);
    // cout << "age=" << p1.age <<"p1 height="<<*p1.height<< endl;
    // person p2(p1);
    //  cout << "age=" << p1.age <<"p2 height="<<*p1.height<< endl;

    student p(30,20,10);//调用默认构造不要加（）
    cout << p.a << "    " << p.b << "   " << p.c << endl;
}

//拷贝构造调用时机
//2.给函数传递参数（值传递）

void dowork(person p){

}

//3.值方式返回局部对象
person dowork2(){
    person p1;
    cout << &p1 << endl;
    return p1;
}

void test2(){
    person p = dowork2();
        cout << &p << endl;
}



int main(){
    //test();
    

    //  person p1;
    //  dowork(p1);
    test();

}

