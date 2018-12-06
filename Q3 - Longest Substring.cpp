/*
Link - https://leetcode.com/problems/longest-substring-without-repeating-characters/
*/

//Optimal approach O(n) - Sliding window variant

int lengthOfLongestSubstring(string s) {
    int start = 0, max_so_far = 0;
    map<char, int> m;
    for(int i = 0; i < s.size(); i++){
        if(m.count(s[i]) && m[s[i]] >= start){
            start = m[s[i]] + 1;
        }
        m[s[i]] = i;
        max_so_far = max(max_so_far, i-start + 1);
    }
    return max_so_far;
}