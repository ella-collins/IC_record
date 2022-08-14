#include<iostream>
#include<algorithm>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

void bubbleSort(vector<int>& nums){
    int n = nums.size();
    for(int i=0; i<n-1; ++i){   //现在才知道++i比i++的效率高
        for(int j=0; j<n-1-i; ++j){
            if(nums[j] > nums[j+1]){
                int temp = nums[j];
                nums[j] = nums[j+1];
                nums[j+1] = temp;
            }
        }
    }
}
//不知道对不对---测试了一下，好像这样是可以的，但是面试官问有没有更简单的方法
vector<int> findIndexInNum2(vector<int>& nums1, vector<int>& nums2){
    vector<int> ans(nums1.size(), -1);
    for(int i=0; i<nums1.size(); i++){
        int n = distance(nums2.begin(), find(nums2.begin(), nums2.end(), nums1[i]));
        for(int j = n+1; j<nums2.size(); j++){
            if(nums2[j] > nums1[i]){
                ans[i] = j;
                break;
            }
        }
    }
    return ans;
}

//20220814更新更优的方法应该是用单调栈,类似LC496,因为LC496上是返回下一个更大的元素值，所以这个题用pair记录索引位置
vector<int> findNextLargerIndexInNums2(vector<int>& nums1, vector<int>& nums2){
    int m = nums1.size(), n = nums2.size();
    unordered_map<int,pair<int,int>> hashmap;
    stack<pair<int,int>> st;
    for (int i = n - 1; i >= 0; --i) {
        int num = nums2[i];
        while (!st.empty() && num >= st.top().first) {
            st.pop();
        }
        hashmap[num] = st.empty() ? make_pair(-1, -1) : st.top();
        st.push(make_pair(num, i));
    }
    vector<int> res(m);
    for (int i = 0; i < m; ++i) {
        res[i] = hashmap[nums1[i]].second;
    }
    return res;
}


int main(){
    //Problem1
//    vector<int> num = {9, 5, 7, 3, 2};
//    bubbleSort(num);
//    for(int i=0; i<num.size(); ++i){
//        cout<<num[i]<<endl;
//    }

    //Problem2
    vector<int> num1 = {9, 5, 7};
    vector<int> num2 = {5, 2, 7, 9, 11, 3, 1};
//    vector<int> ans = findIndexInNum2(num1, num2);
    vector<int> ans = findNextLargerIndexInNums2(num1, num2);
    for(int i=0; i<ans.size(); ++i){
        cout<<ans[i]<<endl;
    }

}