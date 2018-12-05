/*
Link - https://leetcode.com/problems/two-sum/
*/


vector<pair<int, int> > m;
vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> ans;
    int a, b, pos;
    for(int i = 0; i < nums.size(); i++){
        m.push_back(pair<int, int> (nums[i], i));
    }
    sort(m.begin(), m.end());
    a = 0;
    b = m.size()-1;
    while(a < b){
        cout<<a<<" "<<b<<"\n";
        if((m[a].first + m[b].first) == target){
            ans.push_back(m[a].second);
            ans.push_back(m[b].second);
            break;
        }
        else if ((m[a].first + m[b].first) < target){
            a++;
        }
        else
            b--;
    }
    return ans;
}