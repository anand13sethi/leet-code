/*
Link - https://leetcode.com/problems/letter-combinations-of-a-phone-number
*/


map<int, vector<char> > m;
void dfs(string s, string &t, int pos, vector<string> &ans){
    if(pos == s.size()){
        ans.push_back(t);
    }
    else{
        for(auto x : m[s[pos]]){
            t += x;
            dfs(s, t, pos+1, ans);
            t.pop_back();
        }
    }
}

vector<string> letterCombinations(string s) {
    vector<string> ans;
    if(s.size() == 0){
        return ans;
    }
    
    m['2'] = {'a', 'b', 'c'};
    m['3'] = {'d', 'e', 'f'};
    m['4'] = {'g', 'h', 'i'};
    m['5'] = {'j', 'k', 'l'};
    m['6'] = {'m', 'n', 'o'};
    m['7'] = {'p', 'q', 'r', 's'};
    m['8'] = {'t', 'u', 'v'};
    m['9'] = {'w', 'x', 'y', 'z'};
    
    string t = "";
    dfs(s, t, 0, ans);
    return ans;
}