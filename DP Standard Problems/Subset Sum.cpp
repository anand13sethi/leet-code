int main() {
    
    vector<int> arr = {2, 3, 5, 6, 8, 10};
    int sum = 10, n = arr.size(), aux_sum = 0;
    
    // O(N*Sum) Time, O(N*Sum) Space.
    
    for(auto item: arr)
        aux_sum += item;
    if(aux_sum < sum){
        cout << false;
        return 0;
    }
    
    vector<vector<int>> memo(n+1, vector<int>(sum+1, 0));
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= sum; j++){
            if(arr[i-1] == j) memo[i][j] = 1;
            else if(j > arr[i-1]) memo[i][j] = max(memo[i-1][j-arr[i-1]], memo[i-1][j]);
            else memo[i][j] = memo[i-1][j];
        }
    }
    
    cout << memo[n][sum];
    
    // O(N*Sum) Time, O(Sum) Space.
    
    vector<vector<bool>> dp(2, vector<bool>(sum+1, false));
    
    dp[0][0] = dp[1][0] = true;
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= sum; j++){
            if(arr[i-1] == j) dp[i%2][j] = true;
            else if(arr[i-1] < j) 
                dp[i%2][j] = (dp[(i+1)%2][j-arr[i-1]]) || (dp[(i+1)%2][j]);
            else dp[i%2][j] = dp[(i+1)%2][j];
        }
    }
    
    cout << dp[n%2][sum];
    
}