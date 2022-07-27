#include<iostream>
#include<algorithm>
#include<vector>
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


int main(){
    //Problem1
    vector<int> num = {9, 5, 7, 3, 2};
    bubbleSort(num);
    for(int i=0; i<num.size(); ++i){
        cout<<num[i]<<endl;
    }

    //Problem2
    vector<int> num1 = {9, 5, 7};
    vector<int> num2 = {5, 2, 7, 9, 11, 3, 1};
    vector<int> ans = findIndexInNum2(num1, num2);
    for(int i=0; i<ans.size(); ++i){
        cout<<ans[i]<<endl;
    }

}