/*
Link - https://leetcode.com/problems/search-in-rotated-sorted-array-ii
*/

bool search(vector<int>& nums, int target) {
    int l = 0, r = nums.size()-1;
    if(nums.size() == 0)
        return false;
    if(nums.size() == 1 && nums[0] == target){
        return true;
    }
    while(l < r){
        if(nums[l] == target || nums[r] == target)
            return true;
        int mid = (l + r) >> 1; // **same as (l + r)/2 but faster.
        if(nums[mid] == target)
            return true;
        else if(nums[r] > target && nums[mid] < target)
            l = mid + 1;
        else if(nums[mid] < target && nums[r] < target)
            r --;
        else
            l++;
    }
    return false;
}