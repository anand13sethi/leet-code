/*
Link - https://leetcode.com/problems/unique-binary-search-trees
*/

unsigned long int coeff(int n, int k){
    if(k > n-k)
        k = n-k;
    unsigned long int res = 1;
    for(int i = 0; i < k; i++){
        res *= (n-i);
        res /= (i+1);
    }
    return res;
}

int numTrees(int n) {
    unsigned long int x = coeff(2*n, n);
    return x/(n+1);
}