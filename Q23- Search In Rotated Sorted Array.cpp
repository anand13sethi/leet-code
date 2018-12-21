/*
Link - https://leetcode.com/problems/search-in-rotated-sorted-array
*/

int search(vector<int>& nums, int target) {
    int i = 0, j = nums.size()-1;
    if(nums.size() == 1 && nums[0] == target){
        return 0;
    }
    while(i <= j){
        int mid = (i+j) >> 1;
        if(nums[mid] == target)
            return mid;
        if(nums[j] == target)
            return j;
        if(nums[i] == target)
            return i;
        if(nums[mid] > target && nums[j] < target)
            j = mid-1;
        else if(nums[mid] < target)
            j--;
        else
            i++;
    }
    return -1;
}