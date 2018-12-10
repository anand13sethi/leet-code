/*
Link - https://leetcode.com/problems/3sum-closest
*/


int threeSumClosest(vector<int>& nums, int target) {
    int min1 = INT_MAX, min2 = INT_MIN;
    sort(nums.begin(), nums.end());
    for(int i = 0; i < nums.size(); i++){
        int x = nums[i], j = i+1, k = nums.size()-1;
        while(j < k){
            if(x + nums[j] + nums[k] == target){
                return target;
            }
            else if(x + nums[j] + nums[k] < target){
                min2 = max(min2, x+nums[j]+nums[k]);
                j++;
            }
            else{
                min1 = min(min1, x + nums[j] + nums[k]);
                k--;
            }
        }
    }
    if(min2 == INT_MIN){
        return min1;
    }
    if(min1 == INT_MAX)
        return min2;
    if(abs(min2 - target) > abs(min1-target)){
        return min1;
    }
    return min2;
}