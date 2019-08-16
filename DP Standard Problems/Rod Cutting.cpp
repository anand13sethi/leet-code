int main() {
    vector<int> lengths = {1, 2, 3, 4, 5, 6, 7, 8}, value = {1, 5, 8, 9, 10, 17, 17, 20};
    int max_length = 8, n = weight.size();
    
    vector<int> memo((capacity+1), 0);
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= max_length; j++){
            if(lengths[i-1] == j) memo[j] = max(memo[j], value[i-1]);
            if(j > lengths[i-1]) memo[j] = max(memo[j], value[i-1] + memo[(j-lengths[i-1])]);
            else continue;
        }
    }
    cout << memo[max_length];
}