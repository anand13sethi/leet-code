/*

Given a staircase with ‘n’ steps and an array of ‘n’ numbers representing the fee that 
you have to pay if you take the step. Implement a method to calculate the minimum fee 
required to reach the top of the staircase. At every step, you have an option to take 
either 1 step, 2 steps, or 3 steps. You should assume that you are standing at the first step.

Example 1:
    Number of stairs (n) : 6    Fee: {1,2,5,2,1,2}
    Output: 3
    Explanation: Starting from index '0', we can reach the last index through: 0->3->top
    The total fee we have to pay will be (1+2).

Example 2:
    Number of stairs (n): 4     Fee: {2,3,4,5}
    Output: 5
    Explanation: Starting from index '0', we can reach the last index through: 0->1->top
    The total fee we have to pay will be (2+3).
*/


int main(){
    int n = 4;
    vector<int> fee = {2,3,4,5};
    
    vector<int> memo(n, INT_MAX);
    
    memo[0] = fee[0];
    
    for(int i = 0; i < n; i++){
        if(i == n-1){
            cout<< min(memo[n-3], min(memo[n-2], memo[n-1]));
            exit(0);
        }
        for(int j = 1; j < 4 && i+j < n; j++){
            memo[i+j] = min((memo[i] + fee[i+j]), memo[i+j]);
        }
    }
}