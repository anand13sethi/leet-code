int main() {
    vector<int> lengths = {2, 3, 5};
    int n = lengths.size(), amount = 5;
    
    vector<int> memo((amount+1), 0);
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= amount; j++){
            if(j == lengths[i-1])
                memo[j] = memo[j] == 0 ? 1 : max(memo[j], 1);
            else if(j > lengths[i-1])
                if(memo[lengths[i-1]] != 0 && memo[j-lengths[i-1]] != 0)
                    memo[j] = max(memo[j], (memo[lengths[i-1]] + memo[j-lengths[i-1]]));
            else continue;
        }
    }
    cout << memo[amount];
}