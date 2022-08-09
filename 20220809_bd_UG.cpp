#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

//想不起来那个函数名，临时起了个helper(),应该是partition
int helper(vector<int>& nums, int left,  int right){
    int povit = nums[left];  //！！！pivot n. 支点，coding差，英语也差
    while(left<right){
        while(left<right && nums[right] >= povit){
            right--;
        }
        nums[left] = nums[right];
        while(left<right && nums[left] <= povit){
            left++;
        }
        nums[right] = nums[left];
    }
    nums[left] = povit;
    return left;
}

void quickSort(vector<int>& nums, int left, int right){
    if(left<right){
        int povitIdx = helper(nums, left, right);
        quickSort(nums, left, povitIdx-1);
        quickSort(nums, povitIdx+1, right);
    }
}


int main(){
    vector<int> nums = { 3, 4, 8, 5, 9, 0};
    int k = 4;
    quickSort(nums, 0, nums.size()-1);
    for(int i=0; i<nums.size(); ++i){
        cout<< nums[i]<<endl;
    }
    cout<<"The Kth larger number is:"<<nums[nums.size()-k];
}