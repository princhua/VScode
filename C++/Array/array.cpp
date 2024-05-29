#include "array.hpp"

void printarr(myarray<int> &arr){
    for (int i = 0; i <arr.get_size();i++){
        cout << arr[i] << endl; // 重载运算符应用
    }
}



//系统数据类型测试
void test01(){
    myarray <int>arr1(5);
    for (int i = 0; i < 5;i++){
        arr1.push_back(i);//尾插法
    }
    printarr(arr1);
    cout << arr1.get_capacity() << arr1.get_size() << endl;

    myarray<int> arr2(arr1);
    printarr(arr2);
    arr2.pop_back();
    cout << "delete later" << endl;
     cout << arr2.get_capacity() << arr2.get_size() << endl;
     cout << arr2[2];
}

class person
{
public:
    person (){}
    person(string name,int age){
        m_age = age;
        m_name = name;
    }
    int m_age;
    string m_name;
};
void printarrper(myarray<person> &arr){
    for (int i = 0; i <arr.get_size();i++){
        cout << arr[i].m_name<<"\t"<<arr[i].m_age << endl; // 重载运算符应用
    }
}

void test(){//测试自定义数据类型
    myarray<person> array_p(10);
    person p1("bob", 22);
    person p2("aob", 22);
    person p3("cob", 22);
    person p4("dob", 22);
    person p5("eob", 22);
    array_p.push_back(p1);
    array_p.push_back(p2);
    array_p.push_back(p3);
    array_p.push_back(p4);
    array_p.push_back(p5);
    array_p.pop_back();
    printarrper(array_p);
    cout << array_p.get_capacity() << array_p.get_size() << endl;
}

int main(){
    //test01();
    test();
}
