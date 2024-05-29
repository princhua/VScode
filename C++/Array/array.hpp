#pragma once
#include <iostream>
using namespace std;
template<class t>
class myarray
{
    public:
    myarray(int capacity)
    {
        this->m_capacity = capacity;
        this->m_size = 0;
        this->paddress = new t[this->m_capacity];
        cout << "construct call" <<endl;
    }
    ~myarray(){
        if(this->paddress!=NULL){
            cout << "destruct call" <<endl;
            delete[] paddress;
            this->paddress = NULL;
        }
    }

    //拷贝构造
    myarray(const myarray &arr)
    {
        this->m_capacity = arr.m_capacity;
        this->m_size = arr.m_size;
        //this->paddress=arr.paddress
        //深拷贝
        this->paddress = new t[arr.m_capacity];
        for (int i = 0; i < arr.m_size;i++){
            this->paddress[i] = arr.paddress[i];
        }
        cout << "dept call" <<endl;
    }

    //赋值运算符重载
    myarray & operator= (const myarray & arr)
    {
        //先判断堆区域是否有数据，如果有先释放
        if(this->paddress!=NULL){
            delete[] this->paddress;
            this->paddress = NULL;
            this->m_capacity = 0;
            this->m_size = 0;
        }
        this->m_capacity = arr.m_capacity;
        this->m_size = arr.m_size;
        //this->paddress=arr.paddress
        //深拷贝
        this->paddress = new t[arr.m_capacity];
        for (int i = 0; i < arr.m_size;i++){
            this->paddress[i] = arr.paddress[i];
        }
        cout << "== call" <<endl;
        return *this;
        
    }
    //尾插法
    void push_back(const t & val){
        //判断容量
        if(this->m_capacity==this->m_size){
            return;
        }
        this->paddress[this->m_size] = val;//重载赋值运算符的应用
        this->m_size++;
    }
    //尾删法
    void pop_back(){
        if(this->m_size==0){
            return;
        }
        this->m_size--;
    }
    //通过下标记访问
    //重载【】运算符
    t& operator[](int index){
        return this->paddress[index];
    }
    //返回容量
    int get_capacity(){
        return this->m_capacity;
    }
    //返回大小
    int get_size(){
        return this->m_size;
    }

    private:
        t *paddress;//指针指向堆区开辟的数组
        int m_capacity;//数组容量
        int m_size;//记录元素个数
};
