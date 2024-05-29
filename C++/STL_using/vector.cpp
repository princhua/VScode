#include <iostream>
using namespace std;
#include <vector>
void printvector(vector<int>&p){
    for (vector<int>::iterator it = p.begin(); it != p.end();it++)
    {
        cout << *it << "\t";
    }
    cout<<endl;
}

int main(){
//一111111111111111111111111111111
//vector容器构造
    // vector<int> v1;//默认构造，本质是类模板
    // for (int i = 0; i < 10;i++){
    //     v1.push_back(i);
    // }
    // //printvector(v1);

    // vector<int> v2(v1.begin(),v1.end());//通过区间构造
    // //printvector(v2);

    // vector<int> v3(10, 100); // n个element构造
    // printvector(v3);

    // vector<int> v4(v3);//拷贝构造
    //  printvector(v4);

//222222222222222222222222222222222222222222222222222
//vector赋值
     vector<int> v1;
     for (int i = 0; i < 10;i++){
         v1.push_back(i);
     }

    //=号赋值
     vector <int>v2;
     v2 = v1;
     //assign赋值
     vector<int> v3;
     v3.assign(v1.begin(), v1.end());
    //n个element赋值
     vector<int> v4;
     v4.assign(10, 100);
    printvector(v4);
}