int main() {
    vector<int> weight = {10, 20, 30}, profit = {60, 100, 120};
    int capacity = 50, n = 3; 
    vector<vector<int>> memo(n+1, vector<int>(capacity+1, 0));
    
    for(int i = 1; i <= n; i++){
        for(int c = 1; c <= capacity; c++){
            if(c >= weight[i-1]) 
                memo[i][c] = max((profit[i-1] + memo[i-1][c-weight[i-1]]), memo[i-1][c]);
            else memo[i][c] = memo[i-1][c];
        }
    }
    
    cout << memo[n][capacity];
    
}