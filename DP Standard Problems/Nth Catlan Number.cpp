int main() {
    int n = 9;
    
    // DP Solution -> O(n^2) Time, O(n) Space.
    
    vector<long int> catlan(n+1, 0);
    
    catlan[0] = catlan[1] = 1;
    
    for(int i = 2; i <= n; i++)
        for(int j = 0; j < i; j++)
            catlan[i] += catlan[j] * catlan[i-j-1];
    
    cout << catlan[n];
    
    // Binomial Coefficient Solution -> O(n) Time, O(1) Space.
    
    int r = n, res = 1, k = n;
    n = 2*n;
    r = r > n-r ? n-r : r;
    for(int i = 0; i < r; i++){
        res *= n-i;
        res /= i+1;
    }
    
    cout << res/(k+1);
    
    return 1;
}