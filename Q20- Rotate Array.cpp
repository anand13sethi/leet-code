/*
Link - https://leetcode.com/problems/rotate-array/
*/


void rotate(vector<int>& nums, int k) {
    k = k % nums.size();
    reverse(nums.begin(), nums.end());
    reverse(nums.begin(), nums.begin()+k);
    int x = nums.size()-k;
    reverse(nums.rbegin(), nums.rbegin()+x);
}