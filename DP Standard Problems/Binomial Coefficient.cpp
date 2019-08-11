int main() {
    
    // Memory & Space Efficient Solution O(n) Time, O(1) Space.
    
    int n = 9, r = 6, res = 1;
    
    r = r > n-r ? n-r : r;
    
    for(int i = 0; i < r; i++){
        res *= n-i;
        res /= i+1;
    }
    
    cout << res;
    
    // DP Solution O(n*r) Time, O(n*r) Space.
    
    vector<vector<long int>> memo(n+1, vector<long int>(r+1, 0));
    
    memo[0][0] = 1;
    
    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= min(i, r); j++){
            if(j == 0 || j == i) memo[i][j] = 1;
            else memo[i][j] = memo[i-1][j] + memo[i-1][j-1];
        }
    }
    
    cout << memo[n][r];

    // DP Solution O(n*r) Time, O(n) Space.
    
    vector<long int> dp(n+1, 0);
    
    dp[0] = 1;
    
    for(int i = 0; i <= n; i++)
        for(int j = min(i, r); j > 0; j--)
            dp[j] += dp[j-1];
    
    cout << dp[r];
    
}