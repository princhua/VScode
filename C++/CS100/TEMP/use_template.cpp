#include <iostream>
using namespace std;

//类模板
//vscode有自动推导类型使用方式
//vscod

template<class nametype,class agetype=int >
class person
{
    public:
        nametype m_name;
        agetype m_age;
        person(nametype name,agetype age=100){
            m_name = name;
            m_age = age;
        }
};

template<class T>
bool mycompare(T &a ,T&b){
    if(a==b){
        return true;
    }
    else{
        return false;
    }
}

//利用模板重载
//前面加上 template<> 让编译器确定是模板的重载
// template<> bool mycompare(person &a ,person&b){
//     if(a.m_age==b.m_age&&a.m_name==b.m_name){
//         return true;
//     }
//     else{
//         return false;
//     }
// }




int main(){
    // int a = 10;
    // int b = 20;
    // person p1("tom", 10);
    // person p2("tom", 10);
    // if(mycompare(p1,p2)){
    //     cout << "a=b" << endl;
    // }
    // else{
    //     cout << "a!=b" << endl;
    // }

    person  p1("li");//类模板可以有默认参数
    cout << p1.m_age << endl;
}