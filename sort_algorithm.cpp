//
// Created by bebet on 8/14/2022.
//
#include<bits/stdc++.h>
using namespace std;

class SortAlgorithm{
public:
    //--------Bubble_Sort---stable-----
    // TC: Best: O(n)
    //     Worst: O(pow(n,2))
    //     Average: O(pow(n,2))
    // SC: O(1)
    //----------------------------------
    void bubbleSort(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n-1; ++i) {
            for (int j = 0; j < n-i-1; ++j) {
                if (nums[j] > nums[j + 1]) {
                    swap(nums[j], nums[j + 1]);
                }
            }
        }
        return;
    }

    //--------Bubble_Sort---unstable-----
    // TC: Best: O(n*log(n))
    //     Worst: O(pow(n,2))
    //     Average: O(n*log(n))
    // SC: O(log(n)) ~ O(n)
    //------------------------------------
    void quickSort(vector<int>& nums, int low, int high){
        //递归退出条件
        if(low >= high)
            return;

        //循环遍历ij
        int i = low, j = high, pivot = nums[low];
        while(i<j){
            while(i<j && nums[j] >= pivot)
                --j;
            while(i<j && nums[i] <= pivot)
                ++i;
            if(i<j){
                swap(nums[i], nums[j]);
            }
        }

        //以pivot为临时变量，交换nums[low]和nums[i]的值
        nums[low] = nums[i];
        nums[i] = pivot;

        //递归
        quickSort(nums, low, i-1);
        quickSort(nums, i+1, high);
    }

    //--------Direct_Inseration_Sort---stable-----
    // TC: Best: O(n)
    //     Worst: O(pow(n,2))
    //     Average: O(pow(n,2))
    // SC: O(1)
    //----------------------------------------------

    void directInserationSort(vector<int>& nums){
        int n = nums.size();
        int i, j, temp;
        for(i=1; i<n; ++i){
            temp = nums[i];
            for(j=i; j>0 && temp<nums[j-1]; --j){
                nums[j] = nums[j-1];
            }
            nums[j] = temp;
        }
        return;
    }


    //----------Shell_Sort(缩小增量排序)--unstable-------
    // TC: Best: O(pow(n, 1.3))
    //     Worst: O(pow(n,2))
    //     Average: O(n*log(n)) ~ O(pow(n,2))
    // SC: O(1)
    //----------------------------------------------

    void shellSort(vector<int>& nums) {
        int len = nums.size();
        for(int gap=len/2; gap>0; gap/=2){ //调整算法使用的gap大小
            for(int i=gap; i<len; i++){ //第一个数字不用交换
                for(int j=i-gap; j>=0; j-=gap){
//                    cout<<gap<<" "<<i<<" "<<j<<endl;
                    if(nums[j] > nums[j+gap])
                        swap(nums[j+gap],nums[j]);
                    else
                        break;
                }
            }
        }
        return;
    }


    //----------Selection_Sort------stable-----------
    // TC: Best: O(pow(n,2))
    //     Worst: O(pow(n,2))
    //     Average: O(pow(n,2))
    // SC: O(1)
    //----------------------------------------------

    void selectSort(vector<int>& nums){
        int minIdx;
        for (int i = 0; i < nums.size(); i++){
            minIdx = i;
            for (int j = i; j < nums.size(); j++) {
                if (nums[j] < nums[minIdx] )
                    minIdx = j;
            }
            swap(nums[minIdx], nums[i]);
        }
    }


    //----------Heap_Sort------unstable-----------
    // TC: Best: O(n*log(n))
    //     Worst: O(n*log(n))
    //     Average: O(n*log(n))
    // SC: O(1)
    //----------------------------------------------

    //一次交换操作堆排序
    void heapify(vector<int>& nums, int n, int i){
        if(i>=n){
            return;
        }
        int son1 = 2*i+1;
        int son2 = 2*i+2;
        int max_idx = i;
        if(son1 < n && nums[son1] > nums[max_idx]){
            max_idx = son1;
        }
        if(son2 < n && nums[son2] > nums[max_idx]){
            max_idx = son2;
        }
        if(max_idx != i){
            swap(nums[max_idx], nums[i]);
            heapify(nums, n, max_idx);
        }
    }

    //建立大顶堆，所有根节点大于子节点
    void build_heap(vector<int>& nums, int n){
        int last_node = n - 1;
        int parent = (last_node-1)/2;
        for(int i=parent; i>=0; --i){
            heapify(nums, n, i);
        }
    }
    //堆排序
    void heapSort(vector<int>& nums){
        int n = nums.size();
        build_heap(nums, n);
        for(int i = n-1; i>=0; i--){
            swap(nums[i], nums[0]);
            heapify(nums, i, 0);
        }
    }

    //----------Merge_Sort------stable-----------
    // TC: Best: O(n*log(n))
    //     Worst: O(n*log(n))
    //     Average: O(n*log(n))
    // SC: O(n)
    //----------------------------------------------

    void merge(vector<int>& nums, int start, int middle, int end) {
        vector<int> ans;
        ans.resize(end - start + 1);
        int i = start, j = middle + 1, k = 0;
        while (i <= middle && j <= end) {
            ans[k++] = nums[i] > nums[j] ? nums[j++] : nums[i++];
        }
        while (i <= middle) {
            ans[k++] = nums[i++];
        }
        while (j <= end) {
            ans[k++] = nums[j++];
        }
        for (int i = 0, j = start; j <= end ; ++i, ++j) {
            nums[j] = ans[i];
        }
    }

    void mergeSort(vector<int> &nums, int start, int end) {
        if (start < end) {
            int middle = (start + end) / 2;
            mergeSort(nums, start, middle);
            mergeSort(nums, middle + 1, end);
            merge(nums, start, middle, end);
        }
    }

    //----------Bucket_Sort------stable-----------
    // TC: Best: O(n+k)
    //     Worst: O(pow(n,2))
    //     Average: O(n+k)
    // SC: O(n+k)
    //----------------------------------------------

    void bucketSort(vector<int>& nums) {
        int len = nums.size();
        // 确定最大值和最小值
        int max = INT_MIN;
        int min = INT_MAX;
        for (int i = 0; i < len; ++i) {
            if (nums[i] > max)
                max = nums[i];
            if (nums[i] < min)
                min = nums[i];
        }

        // 生成桶数组
        // 设置最小的值为索引0，每个桶间隔为1
        int bucketLen = max - min + 1;

        // 初始化桶
        vector<int> bucket(bucketLen);
        for (int i = 0; i < bucketLen; i++)
            bucket[i] = 0;

        // 放入桶中
        int index = 0;
        for (int i = 0; i < len; i++) {
            index = nums[i] - min;
            bucket[index] += 1;
        }

        // 替换原序列
        int start = 0;
        for (int i = 0; i < bucketLen; i++) {
            for (int j = start; j < start + bucket[i]; j++) {
                nums[j] = min + i;
            }
            start += bucket[i];
        }
        return;
    }


    //----------Counting_Sort------stable-----------
    // TC: Best: O(n+k)
    //     Worst: O(n+k)
    //     Average: O(n+k)
    // SC: O(k)
    //----------------------------------------------


    void countingSort(vector<int> &nums) {
        int len = nums.size();
        int maxVal = *max_element(nums.begin(), nums.end());
        if (len < 1)
            return;
        vector<int> count(maxVal+1, 0);
        vector<int> tmp(nums);
        for (auto x : nums)
            count[x]++;
        for (int i = 1; i <= maxVal; ++i)
            count[i] += count[i - 1];
        for (int i = len - 1; i >= 0; --i) {
            nums[count[tmp[i]] - 1] = tmp[i];
            count[tmp[i]]--;				//注意这里要减1
        }
    }

    //----------Radix_Sort------stable-----------
    // TC: Best: O(k*n)
    //     Worst: O(k*n)
    //     Average: O(k*n)
    // SC: O(n+k)
    //----------------------------------------------

    int maxbit(vector<int>& nums){
        int n = nums.size();
        int maxData = nums[0];              ///< 最大数
        //先求出最大数，再求其位数，这样有原先依次每个数判断其位数，稍微优化点。
        for (int i = 1; i < n; ++i){
            if (maxData < nums[i])
                maxData = nums[i];
        }
        int d = 1;
        int p = 10;
        while (maxData >= p){
            //p *= 10; // Maybe overflow
            maxData /= 10;
            ++d;
        }
        return d;
}
    void radixSort(vector<int>& nums) {
        int n = nums.size();
        int d = maxbit(nums);
        int *tmp = new int[n];
        int *count = new int[10]; //计数器
        int i, j, k;
        int radix = 1;
        for(i = 1; i <= d; i++){
            for(j = 0; j < 10; j++)
                count[j] = 0; //每次分配前清空计数器
            for(j = 0; j < n; j++){
                k = (nums[j] / radix) % 10; //统计每个桶中的记录数
                count[k]++;
            }
            for(j = 1; j < 10; j++)
                count[j] = count[j - 1] + count[j]; //将tmp中的位置依次分配给每个桶
            for(j = n - 1; j >= 0; j--){
                k = (nums[j] / radix) % 10;
                tmp[count[k] - 1] = nums[j];
                count[k]--;
            }
            for(j = 0; j < n; j++) //将临时数组的内容复制到data中
                nums[j] = tmp[j];
            radix = radix * 10;
        }
        delete []tmp;
        delete []count;
    }
};


void coutVector(vector<int>& nums){
    for(int i=0; i<nums.size(); ++i){
        cout<<nums[i]<<" ";
    }
    cout<<endl;
}

int main(){
    //define variables
    SortAlgorithm sort;
    vector<int> nums = {9, 3, 7, 5, 1, 3, 2, 10, 11};
    //sort
//    sort.bubbleSort(nums);
//    sort.quickSort(nums, 0, nums.size()-1);
//    sort.directInserationSort(nums);
//    sort.shellSort(nums);
//    sort.selectSort(nums);
//    sort.heapSort(nums);
//    sort.mergeSort(nums,0, nums.size());
//    sort.bucketSort(nums);
//    sort.countingSort(nums);
    sort.radixSort(nums);


    //cout
    coutVector(nums);

    return 0;
}
