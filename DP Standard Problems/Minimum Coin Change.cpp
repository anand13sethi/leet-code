int main() {
    vector<int> denomination = {9, 6, 5, 1};
    int n = denomination.size(), amount = 11;
    
    vector<int> memo((amount+1), INT_MAX-2);
    memo[0] = 0;
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= amount; j++){
            if(j == denomination[i-1]) memo[j] = 1;
            else if(j > denomination[i-1])
                memo[j] = min((memo[j-denomination[i-1]] + memo[denomination[i-1]]), memo[j]);
            else continue;
        }
    }
    cout << memo[amount];
}