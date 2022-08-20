//
// Created by Jiahua Chen on 2022/8/20.
//
#include<bits/stdc++.h>
using namespace std;

#define PI 3.1415927
//p1
void hanWin(int n){
    int x;
    for(int i=0; i<n; ++i){
        cin>>x;
        float hw = 0.5 *(1.0-cos(2.0*PI*(float(i)/n)));
//        cout<<hw<<endl;
        hw *= x;
        if(hw>=0){
            cout<<int(hw+0.5)<<" ";
        }else{
            cout<<int(hw-0.5)<<" ";
        }
    }
}
void solution1(){
    // p1
    int N;
    cin>>N;
    hanWin(N);
}

//p2
void strFind(string p, string s){
    int findIdx = p.find(s);
    if(findIdx<p.size()){
        cout<<s<<" "<<findIdx<<" "<<findIdx+s.size()<<endl;
    }
}
void solution2(){
    //p2
    string str;
    cin>>str; //！！！cin遇到空格或者回车\r停止
//    cout<<str<<endl;
    string temp;
    vector<string> search_strs;
    while(cin>>temp) {
        int i = 0;
        for (i = 0; i < search_strs.size(); ++i) {
            if (search_strs[i].find(temp)) {
                break;
            }
        }
        if (i == search_strs.size()) {
            strFind(str, temp);
        }
    }
}

// review and summary
//C++输入带空格的字符串
void strInput(){
    //method1
    string a;
    getline(cin, a);  //看到的教程说这个需要两次回车结束，但是我测试一次回车就结束了，
    cout<<a<<endl;

    //method2
    char b[50];
    cin.get(b, 50);
    cout<<b<<endl;
    string bStr(b); //bStr = b;

    cin.get();       //这里需要吸收一下上面输入的回车符号
    //method3
    char c[50];
    cin.getline(c, 50);
    cout<<c<<endl;
}



int main(){
    strInput();
    return 0;
}
