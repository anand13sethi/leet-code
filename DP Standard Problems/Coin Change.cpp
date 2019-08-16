int main() {
    vector<int> denomination = {2, 5, 3, 6};
    int n = denomination.size(), amount = 10;
    
    vector<int> memo((amount+1), 0);
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= amount; j++){
            if(j == denomination[i-1]) memo[j] += 1;
            else if(j > denomination[i-1]) memo[j] += memo[j-denomination[i-1]];
            else continue;
        }
    }
    cout << memo[amount];
}