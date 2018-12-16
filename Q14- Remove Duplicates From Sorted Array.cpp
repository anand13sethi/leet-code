/*
Link - https://leetcode.com/problems/remove-duplicates-from-sorted-array
*/


int removeDuplicates(vector<int>& nums) {
    if(nums.size() == 0 || nums.size() == 1){
        return nums.size();
    }
    int i = 0;
    int size = 1;
    int j = i+1;
    while(j < nums.size()){
        if(nums[i] == nums[j]){
            j++;
        }
        else{
            nums[++i] = nums[j++];
            size++;
        }
    }
    return size;
}