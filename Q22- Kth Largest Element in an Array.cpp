/*
Link - https://leetcode.com/problems/kth-largest-element-in-an-array/
*/

int partition(vector<int> &arr, int p, int q){
    int pivot = arr[p];
    int i = p, j = i+1;
    while(j <= q){
        if(arr[j] > pivot){
            i++;
            // cout<<arr[i]<<" "<<arr[j]<<"\n";
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
        j++;
    }
    int t = arr[i];
    arr[i] = arr[p];
    arr[p] = t;
    return i+1;
}

int findKthLargest(vector<int>& nums, int k) {
    int a = partition(nums, 0, nums.size()-1);
    while(a != k){
        if(a < k)
            a = partition(nums, a, nums.size()-1);
        else if(a > k)
            a = partition(nums, 0, a-1);
    }
    return nums[a-1];
}