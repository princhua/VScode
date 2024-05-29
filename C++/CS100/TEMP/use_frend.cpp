#include <iostream>
using namespace std;

class building;//提前声明

class goodgay
{
    public:
        void visit();//让visit函数可以访问building中私有成员
        void visit2();
        building *build;//building类在goodgay之后，会出问题，提前声明
        goodgay();
};
class building
{
    //1.全局函数做友元
    //friend void goodguy(building *p);
    //goodguy函数是building好朋友，可以访问私有成员

    //2.类做友元
    //friend class goodgay;
    //类goodgay是building的好朋友，可以访问私有

    //3.成员函数做友元  goodgay下的visit函数是好朋友
    friend void goodgay::visit();

private:
    string m_bedroom;

public:
    string m_sittingroom;
    building();
};
building::building(){
        m_bedroom = "bedroom";
        m_sittingroom = "sittingroom";
    }
goodgay::goodgay(){
    build = new building;
}
   void goodgay::visit2(){
    cout<<"chao in "<<build->m_sittingroom << endl;
    //cout<<"shu fa in "<<build->m_bedroom << endl;
}
   void goodgay::visit(){
    cout<<"shu fa in "<<build->m_sittingroom << endl;
    cout<<"shu fa in "<<build->m_bedroom << endl;
}


void goodguy(building *p)
{
    cout << "guy in " << p->m_sittingroom << endl;
    //cout << "guy in " << p->m_bedroom << endl;
}

void test(){
    // building bu;
    // goodguy(&bu);
    goodgay cff;
    cff.visit();
    cff.visit2();
}
int main(){
    test();
}