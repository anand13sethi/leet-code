/*
Link - https://leetcode.com/problems/3sum
*/
// Indraneel was here

vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int> > ans;
    vector<int>v;
    set<vector<int> > s;
    sort(nums.begin(), nums.end());
    for(int i = 0; i < nums.size(); i++){
        int x = nums[i];
        int j = i+1, k = nums.size()-1;
        while(j < k){
            if(x + nums[j] + nums[k] == 0){
                v.push_back(x);
                v.push_back(nums[j]);
                v.push_back(nums[k]);
                s.insert(v);
                v.clear();
                j++;
                k--;
            }
            else if(x + nums[j] + nums[k] < 0){
                j++;
            }
            else
                k--;
        }
    }
    for(auto x : s){
        ans.push_back(x);
    }
    return ans;
}