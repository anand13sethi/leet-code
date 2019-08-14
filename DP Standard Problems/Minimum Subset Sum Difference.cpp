int main() {
    vector<int> arr = {1, 2, 3, 9};
    int sum = 0, n = arr.size(), diff = 0;
    
    for(auto item: arr)
        sum += item;
    
    vector<vector<bool>> memo(n+1, vector<bool>(sum+1, false));
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= sum; j++){
            if(arr[i-1] == j) memo[i][j] = true;
            else if(j > arr[i-1]) memo[i][j] = memo[i-1][j - arr[i-1]] || memo[i-1][j];
            else memo[i][j] = memo[i-1][j];
        }
    }
    
    for(int j = sum/2; j >= 0; j--)
            if(memo[n][j]){
                diff = sum - (2*j);
                break;
            }
    
    cout << diff;
}