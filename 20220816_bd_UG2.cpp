#include<bits/stdc++.h>
using namespace std;

struct Node{
    int val;
    struct Node* next;

};

vector<int> nextLargerNum(vector<int>& nums){
    int n = nums.size();
    vector<int> ans(n);

    stack<int> stk;
    for(int i=n-1; i>=0; --i){
        if(stk.empty()){
            stk.push(nums[i]);
        }
        while(!stk.empty() && nums[i] > stk.top()){
            stk.pop();
        }
        if(!stk.empty()){
            ans[i] = stk.top();
        }
        if(stk.empty()){
            stk.push(nums[i]);
            ans[i] = 0;
        }
    }
    return ans;
}

int cnt = 0;
void solution(vector<int>& nums, int sum, int target){
//    if(sum>target){
//        return;
//    }
    if(sum == target){
        cnt++;
        return;
    }
    for(int i=0; i<nums.size(); ++i){
        int remain = target - sum;
        if(remain >= nums[i]){
            solution(nums, sum+nums[i], target);
        }
    }
}

int targetNum(vector<int>& nums, int target){
    solution(nums, 0, target);
    return cnt;
}



int main(){
    //p1
//    vector<int> nums = {2, 1, 4, 0};
//    vector<int> ans = nextLargerNum(nums);
//    for(int i=0; i<ans.size(); ++i){
//        cout<<ans[i]<<" ";
//    }

    //p2
    vector<int> nums = {1, 2, 5};
    cout<<targetNum(nums, 4);

}