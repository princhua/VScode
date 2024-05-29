#include <iostream>
using namespace std;
#include <vector>
#include<algorithm>

void myprint(int val){
    cout << val << endl;
}
void test01(){
    vector<int> v;//创建一个vector数组
    //向容器中插入数据
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    v.push_back(50);

    //通过迭代器访问容器中数据
    // vector<int>::iterator itbegin = v.begin(); //v.begin()起始迭代器 指向容器中第一个元素
    // vector<int>::iterator itend = v.end();//v.end() 结束迭代器指向 容器中最后一个元素的下一位置

    // //第一种1..遍历
    // while(itbegin!=itend){
    //     cout << *itbegin << endl;
    //     itbegin++;
    // }

    //第二种遍历方式
    // for (vector<int>::iterator it = v.begin(); it != v.end();it++){
    //     cout << *it << endl;
    // }

    //第三种方式，利用STL
    for_each(v.begin(), v.end(), myprint);
}

//vactor存放自定义类型
class person
{
public:
    person(string name,int age){
        m_name = name;
        m_age = age;
    }

    string m_name;
    int m_age;
};
void test02(){
    vector<person*> v;
    person p1("aob", 1);
    person p2("bob", 11);
    person p3("cob", 18);
    person p4("dob", 19);
    //向容器中添加数据
    v.push_back(&p1);
    v.push_back(&p2);
    v.push_back(&p3);
    v.push_back(&p4);
    //遍历
    // for (vector<person>::iterator it = v.begin(); it != v.end();it++){
    //     //cout << (*it).m_name << "\t" << (*it).m_age << endl;
    //     cout << it->m_name << "\t" <<  it->m_age << endl;
    // }

    for (vector<person *>::iterator it = v.begin(); it != v.end();it++){
        cout << (*it)->m_name << endl;
    }
}
//嵌套容器
void test03(){
    vector<vector<int>> v;
    //创建小容器
    

}


int main(){
    //test01();
    //test02();
}