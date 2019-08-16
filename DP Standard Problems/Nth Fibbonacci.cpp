int main() {
    int n = 10;
    
    vector<long int> memo(n+1, 0);
    memo[0] = 0;
    memo[1] = 1;
    
    for(int i = 2; i <= n; i++){
        memo[i] = memo[i-1] + memo[i-2];
    }
    cout << memo[n];
}