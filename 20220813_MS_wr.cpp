#include <iostream>
#include<bits/stdc++.h>
#include<algorithm>
#include<numeric>
using namespace std;



// problem 1
int solution1(vector<int> &A) {
    // write your code in C++ (C++14 (g++ 6.2.0))
    float targetPolution = accumulate(A.begin(), A.end(), 0)/2;
    float filteredPolution = 0;
    int totalFilters = 0;
    vector<float>  A_f;
    int n = A.size();
    for(int i=0; i<n; ++i){
        A_f.emplace_back(float(A[i]));
    }

    sort(A_f.begin(), A_f.end());
    while(filteredPolution < targetPolution){
        sort(A_f.begin(), A_f.end());
        cout<<A_f[n-1]<<endl;
        filteredPolution += A_f[n-1]/2;
        A_f[n-1] = A_f[n-1]/2;
        ++totalFilters;
        cout<<filteredPolution<<endl;
    }
    return totalFilters;
}

// problem 2
//--find lowest common multiple(LCM)
int findLCM(vector<int>& B) {
    //复制数组
    vector<int> nums(B);
    //设置变量
    int div = 2;
    int lcm = 1;
    int count = 0;
    //循环
    while(true) {
        //把所有数字的每个因子相乘起来
        bool divides = false;
        for(int i=0; i<nums.size(); ++i) {
            if(nums[i] == 0)
                return 0;
            if(nums[i] != 1 && nums[i] % div == 0) {
                divides = true;
                nums[i] /= div;
                if(nums[i] == 1)
                    ++count;
            }
        }

        if(divides) {
            lcm *= div;
        } else {
            ++div;
        }

        if(count == nums.size())
            return lcm;
    }
}
int solution2(vector<int> &X, vector<int> &Y) {
    // write your code in C++ (C++14 (g++ 6.2.0))
    int count = 0;
    int MOD = 1e9+7;
    int lcm = findLCM(Y);
//    cout<<lcm<<endl;
    unordered_map<int, int> mp;
    for(int i=0; i<X.size(); ++i) {
        X[i] *= lcm/Y[i];
        count += mp.find(lcm-X[i]) != mp.end() ? mp[lcm-X[i]] : 0;
        count %= MOD;
        mp[X[i]] = mp[X[i]]+1;
    }
    return count;
}


// problem 3-brust force,肯定有更优的解法
int solution3(vector<int> &A, int X, int Y) {
    // write your code in C++ (C++14 (g++ 6.2.0))
    int minSum = INT_MAX;
    int N = A.size();
    for(int i=0; i<=N-(X-1)*Y-1; ++i){
        int sum = 0;
        for(int j = i; j<N; j=j+Y){
            sum += A[j];
        }
        if(sum<minSum){
            minSum = sum;
        }
    }
    return minSum;
}



int main(){
    //proble1
//    vector<int> a = {5, 19, 8, 1};
//    cout<<solution1(a)<<endl;

    // problem 2
    vector<int> X = {1, 1, 2};
    vector<int> Y = {3, 2, 3};
    cout<<solution2(X, Y)<<endl;

    //problem 3
//    vector<int> A = {10, 3, 4, 7};
//    int X = 2;
//    int Y = 3;
//    cout<<solution3(A, X, Y)<<endl;

}