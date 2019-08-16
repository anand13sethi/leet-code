int main() {
    vector<int> weight = {5, 10, 15}, value = {10, 30, 20};
    int capacity = 100, n = weight.size();
    
    vector<int> memo((capacity+1), 0);
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= capacity; j++){
            if(weight[i-1] == j) memo[j] = max(memo[j], value[i-1]);
            if(j > weight[i-1]) memo[j] = max(memo[j], value[i-1] + memo[(j-weight[i-1])]);
            else continue;
        }
    }
    cout << memo[capacity];
}