/*
Link - https://leetcode.com/problems/zigzag-conversion
*/


string convert(string s, int numRows) {
    string ans;
    if(numRows > s.size() || numRows == 1){
        return s;
    }
    vector<string> v(numRows);
    bool down = false;
    int curr = 0;
    for(auto x : s){
        v[curr] += x;
        if(curr == 0 || curr == numRows - 1){
            down = !down;
        }
        curr += down ? 1 : -1;
    }
    for(auto y : v){
        ans += y;
    }
    return ans;
}