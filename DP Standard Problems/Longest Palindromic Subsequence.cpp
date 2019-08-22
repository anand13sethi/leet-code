/*

Given a sequence, find the length of its Longest Palindromic Subsequence (LPS). In a palindromic 
subsequence, elements read the same backward and forward.
A subsequence is a sequence that can be derived from another sequence by deleting some or no elements 
without changing the order of the remaining elements.

Example 1:
    Input: "abdbca"
    Output: 5
    Explanation: LPS is "abdba".

Example 2:
    Input: = "cddpd"
    Output: 3
    Explanation: LPS is "ddd".

Example 3:
    Input: = "pqr"
    Output: 1
    Explanation: LPS could be "p", "q" or "r".
*/

int main(){
    string s = "geeks for geeks";
    int n = s.size();
    
    vector<vector<pair<int, int>>> memo(n, vector<pair<int, int>>(n, make_pair(0, 0)));
    
    for(int i = 0; i < n; i++)
        memo[i][i] = make_pair(1, -1);
    
    for(int k = 2; k <= n; k++){
        for(int i = 0; i < n-k+1; i++){
            int j = i+k-1;
            if(s[i] == s[j] && k == 2) memo[i][j] = make_pair(2, -1);
            else if(s[i] == s[j]) memo[i][j] = make_pair((memo[i+1][j-1].first + 2), 2);
            else{
                if(memo[i+1][j].first > memo[i][j-1].first)
                    memo[i][j] = make_pair(memo[i+1][j].first, 1);
                else memo[i][j] = make_pair(memo[i][j-1].first, 0);
            }
        }
    }
    
    string result = "";
    
    int i = 0, j = n-1;
    while(i != j){
        if(memo[i][j].second == 2){
            result.push_back(s[j]);
            i += 1;
            j -= 1;
        }
        else if(memo[i][j].second == 1) i += 1;
        else if(memo[i][j].second == 0) j -= 1;
    }
    
    result.push_back(s[j]);
    
    i = 0;
    while(i < memo[0][n-1].first/2){
        result.push_back(result[i++]);
    }
    
    reverse((result.begin()+(memo[0][n-1].first/2+1)), result.end());
    
    cout << "Length - " << memo[0][n-1].first << "\nString - " << result;
}