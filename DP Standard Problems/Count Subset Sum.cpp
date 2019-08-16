int main() {
    
    vector<int> arr = {1, 1, 2, 3};
    int sum = 4, n = arr.size(), diff = 0;
    
    vector<vector<int>> memo(n+1, vector<int>(sum+1, 0));
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= sum; j++){
            if(arr[i-1] == j) memo[i][j] = 1 + memo[i-1][j];
            else if(j > arr[i-1]) memo[i][j] = memo[i-1][j - arr[i-1]] + memo[i-1][j];
            else memo[i][j] = memo[i-1][j];
        }
    }
    cout << memo[n][sum];
}