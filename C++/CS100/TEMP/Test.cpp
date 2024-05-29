#include <iostream>
using namespace std;
class person;
void test_(person &per){
    cout << per.a << endl;
}
class person
{
    //加friend关键字后变为全局函数
            // friend void show(person &pe){
            // cout << pe.a << endl;
            // }
    public:
        int a;

        
};

int main(){
    void test_(person & per);
    person p;
    p.a = 10;
    test_(p);
}