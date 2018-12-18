/*
Link - https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii
*/


int removeDuplicates(vector<int>& nums) {
    int size = nums.size();
    int temp = -1;
    if(size < 3){
        return size;
    }
    if(size == 3){
        if(nums[0] == nums[1] && nums[1] == nums[2])
            return 2;
    }
    int f = 0, s = 1, t = 2;
    while(t < nums.size()){
        if(nums[f] == nums[s] && nums[s] == nums[t]){
            int x = t;
            while(x < nums.size()-1){
                nums[x] = nums[x+1];
                x++;
            };
            temp--;
            nums[x] = temp;
            size --;
        }
        else{
            f++;
            s++;
            t++;
        }
    }
    return size;
}

//Better Program:

int removeDuplicates(vector<int>& nums) {
    int i = 0;
    for (int n : nums)
        if (i < 2 || n > nums[i-2])
            nums[i++] = n;
    return i;
}