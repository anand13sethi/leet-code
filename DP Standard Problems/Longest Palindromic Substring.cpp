/*

Given a string, find the length of its Longest Palindromic Substring (LPS). In a palindromic 
string, elements read the same backward and forward.

Example 1:
    Input: "abdbca"
    Output: 3
    Explanation: LPS is "bdb".

Example 2:
    Input: = "cddpd"
    Output: 3
    Explanation: LPS is "dpd".

Example 3:
    Input: = "pqr"
    Output: 1
    Explanation: LPS could be "p", "q" or "r".

*/

int main(){
    string s = "cddpd";
    int n = s.size(), max_len = 1, start = 0;
    
    vector<vector<bool>> memo(n, vector<bool>(n, false));
    
    for(int i = 0; i < n; i++) memo[i][i] = true;
    
    for(int i = 0; i < n-1; i++)
        if(s[i] == s[i+1]){
            memo[i][i+1] = true;
            max_len = 2;
            start = i;
        }
    
    for(int k = 3; k <= n; k++){
        for(int i = 0; i < n-k+1; i++){
            int j = i+k-1;
            if(memo[i+1][j-1] && s[i] == s[j]) {
                memo[i][j] = true;
                if(max_len < k){
                    max_len = k;
                    start = i;
                }
            }
        }
    }
    
    for(int i = start; i < start+max_len; i++)
        cout<<s[i];
    
}
