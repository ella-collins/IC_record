#include <iostream>
#include<bits/stdc++.h>
#include<algorithm>
#include<numeric>
using namespace std;



// problem 1
//去掉一个5，使得到的数字最大
int solution1(int N){
    string n_str = to_string(N);
    // Stores the index of X that has to be removed
    int index = -1;
    for (int i = 0; i < n_str.length() - 1; i++) {
        if (N >= 0 && n_str[i] == '5' && n_str[i] - '0' < n_str[i + 1] - '0') {
            // Update index and break
            index = i;
            break;
        }else if(N < 0 && n_str[i] == '5' && n_str[i] - '0' > n_str[i + 1] - '0'){
            index = i;
            break;
        }
    }
    if (index == -1) {
        for (int i = n_str.length() - 1; i >= 0; i--) {
            if (n_str[i] == '5') {
                index = i;
                break;
            }
        }
    }

    n_str.erase(index, 1);
    cout<<n_str<<endl;
    // Construct answer using all characters in string N except index
    int ret = stoi(n_str);
    return ret;
}

// problem 2
//和为0的连续子数组个数，按照题意输入vector<int> nums(100000, 0),应该返回-1，但是这个代码不是
int solution2(vector<int> &A) {
    int MAX= 1e9;
    unordered_map<int, long> mp;
    mp[0] = 0;
    int cnt = 0, pre = 0;
    for(auto& x:A){
        pre += x;
        if(mp.find(pre-0) != mp.end()){
            cnt += mp[pre-0];
        }
        mp[pre]++;
    }
    return cnt<1e9?cnt:-1;
}

int solution22(vector<int>& A) {
    int MAX= 1e9;
    int count = 0;
    for (int start = 0; start < A.size(); ++start) {
        int sum = 0;
        for (int end = start; end >= 0; --end) {
            sum += A[end];
            if (sum == 0) {
                count++;
            }
        }
    }
//    cout<<count<<endl;
//    cout<<MAX<<endl;
    if(count>=MAX)
        return -1;
    eles:
        return count;
}

// p3平稳速度的连续子数组个数
int solution3(vector<int>& A){// wrong!!!
    int ans = 0;
    for(int i=0; i<A.size();) {
        int streak = 0, cd = INT_MAX;
        if (i < A.size() - 1) {
            streak = 2;
            cd = A[i] - A[i + 1];
        }
        i++;
        while (i < A.size() - 1 && A[i] - A[i + 1] == cd) {
            streak++;
            i++;
        }
        if (streak >= 3) {
            ans = ans + (streak * (streak + 1) / 2) - (2 * streak - 1);
        }
        return ans;
    }
}
int particleVelocity(vector<int>& A){
    int cnt = 0;
    if(A.size() <3)  {
        return 0;
    }
    for(int i=0; i<A.size()-2; ++i){
        for(int j=i+1; j<A.size()-1; ++j){
            if(A[j+1]-A[j] == A[i+1]- A[i]){
                cnt++;
            }else{
                break;
            }
        }
    }
    return cnt<1e9?cnt:-1;
}

int main(){
    //p1
    int ret = solution1(-5859);
    cout<<ret<<endl;

    //p2
//    vector<int> A = {2, -2, 3, 0, 4, -7};
//    vector<int> A2(100000, 0);
//    int ret = solution2(A2);
//    cout<<ret<<endl;
//    cout<<solution22(A2)<<endl;

    //p3
//    vector<int> nums = {-1, 1, 3, 3, 3, 2, 3, 2, 1, 0};
//    cout<<solution3(nums)<<endl;
//    cout<<particleVelocity(nums)<<endl;

}