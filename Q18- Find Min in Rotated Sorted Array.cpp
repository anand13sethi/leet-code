/*
Link - https://leetcode.com/problems/find-minimum-in-rotated-sorted-array
*/


int findMin(vector<int>& nums) {
    if(nums[0] < nums[nums.size()-1])
        return nums[0];
    int i = 0, j = nums.size()-1;
    if(j == 0)
        return nums[0];
    while(i <= j){
        int mid = (i + j) >> 1;
    // 1st condition for point of infliction.
        if(nums[mid] > nums[mid+1])
            return nums[mid+1];
    // 2nd condition for point of infliction.
        if(nums[mid] < nums[mid-1])
            return nums[mid];
    // If below is true, point of infliction lies to the right.
        if(nums[mid] > nums[0])
            i = mid+1;
        else
            j = mid-1;
    }
    return -1;
}