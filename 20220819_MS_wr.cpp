//
// Created by bebet on 8/19/2022.
//
#include <iostream>
#include<bits/stdc++.h>
#include<algorithm>
#include<numeric>
using namespace std;



// problem 1
int solution1(vector<int> &X, vector<int> &Y, int W) {
    // write your code in C++ (C++14 (g++ 6.2.0))
    sort(X.begin(), X.end());
    int start = X[0],  cnt = 1;
    for(int i=0; i<X.size(); ++i){
        if(X[i]>start+W){
            cnt++;
            start = X[i];
        }
    }
    return cnt;
}

// p2
string solution2(string &S) {
    // write your code in C++ (C++14 (g++ 6.2.0))
    int n = S.size();
    map<int,int,greater<int>> hash;
    for(int i=0; i<n; ++i){
        hash[S[i]-'0']++;
    }
    if(hash.size()==1 && hash[0]>0){
        return "0";
    }
    char cen='a';
    string ans="";
    for(auto x: hash){
        if(ans.size()==0 && x.first==0 && x.second>1){
            continue;
        }
        int cnt=x.second/2;
        for(int i=0; i<cnt; ++i){
            ans.push_back((char)x.first+48);
        }
        if(x.second & 1==1 && cen=='a'){
            cen=(char)x.first+48;
        }
    }
    string rev=ans;
    reverse(rev.begin(),rev.end());
    if(cen != 'a')
        ans+=cen;
    ans += rev;
    return ans;
}

// p3
int solution3(vector<int>& A, vector<int>& B){
    
}






int main(){
    // p1
//    vector<int> X = {2, 4, 2, 6, 7, 1};
//    vector<int> Y = {0, 5, 3, 2, 1, 5};
//    int ans = solution(X, Y, 2);
//    cout<< ans<<endl;

    //
    string S("00000");
    cout<<solution2(S);
}