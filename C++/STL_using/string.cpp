#include<iostream>
using namespace std;
int main(){
    // string s1;
    // const char *str = "hello world";
    // string s2(str);
    // cout << s2 << endl;

    // string s3(s2);
    // cout << s3 << endl;
    // string s4(10,'a');
    // cout << s4 << endl;

    // 字符串类的应用
    // string str;
    // str.assign("hello");
    // cout << str << endl;
    // string str1;
    // str1.assign("hello",2);
    // cout << str1 << endl;

    //拼接字符串
    // string str = "i";
    // str += "want play game";
    // str += ':';
    // //cout << "str=" << str << endl;
    // string str2 = "lol";
    // //str += str2;
    // //cout << "str=" << str << endl;
    // str.append(str2,3);
    // cout << "str=" << str << endl;
    // string str3 = "i";
    // str3.append(" love");
    // cout << "str=" << str3 << endl;

    // string str1 = "i want ";
    // string str2 = "gameabcg";
    // //str1.append("gameabcg", 4);
    // str1.append(str2, 4);
    // cout  << str1 << endl;

    //字符串查找
    //rfind从右往左查
    string str1 = "abcdefgde";
    // int pos = str1.rfind("de");
    // cout << "pos=" << pos;

    //替换
    // str1.replace(1, 3, "1111");
    // cout << "pos=" << str1;

    //访问单个字符1.
    // for (int i = 0; i < str1.size();i++){
    //     cout << str1[i] << "";
    //     cout << endl;
    // }
    //2.
    // for (int i = 0; i < str1.size();i++){
    //     cout << str1.at(i) << " ";
    // }
    //     cout << endl;

    //str1[0] = 'x';
    // str1.at(1) = 'x';
    // cout << str1 << endl;

    // str1.insert(1, "111");
    // cout << str1 << endl;
    // str1.erase(1, 3);
    // cout << str1 << endl;

    //求子串
    // string substr = str1.substr(0, 4);
    // cout << substr << endl;
    //实际应用
    string email = "zhangsan@outlook";
    int pos = email.find("@");
    cout << email.substr(0, pos) << endl;
}