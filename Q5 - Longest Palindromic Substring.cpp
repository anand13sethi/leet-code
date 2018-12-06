/*
Link - https://leetcode.com/problems/longest-palindromic-substring/
*/


string longestPalindrome(string s) {
    int max_so_far = 1, st, e, flag = 0;
    int len = s.size();
    string ans;
    vector<vector<int> > dp(len, vector<int>(len));
    for(int i = 0; i <len; i++){
        dp[i][i] = max_so_far;
    }
    for(int i = 0; i < len-1; i++){
        if(s[i] == s[i+1]){
            max_so_far = 2;
            dp[i][i+1] = max_so_far;
        }
    }
    
    for(int k = 3; k <= len; k++){
        for(int i = 0; i < len - k + 1; i++){
            int j = i + k - 1;
            if(dp[i+1][j-1] && s[i] == s[j]){
                dp[i][j] = abs(i - j) + 1;
                max_so_far = max(max_so_far, abs(i - j) + 1);
            }
        }
    }
    
    for(int i = 0; i < len; i++){
        if(!flag){
            for(int j = 0; j < len; j++){
                if(dp[i][j] == max_so_far){
                    st = i;
                    e = j;
                    flag = 1;
                }
            }
        }
        else{
            break;
        }
    }

    for(int k = st; k <= e; k++){
        ans.push_back(s[k]);
    }
    return ans;
}