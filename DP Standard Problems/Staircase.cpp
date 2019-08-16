
/*

Given a stair with ‘n’ steps, implement a method to count how many possible ways are there 
to reach the top of the staircase, given that, at every step you can either take 1 step, 2 steps, or 3 steps.

Example 1:
    Number of stairs (n) : 3
    Number of ways = 4
    Explanation: Following are the four ways we can climb : {1,1,1}, {1,2}, {2,1}, {3} 

Example 2:
    Number of stairs (n) : 4
    Number of ways = 7
    Explanation: Following are the seven ways we can climb : {1,1,1,1}, {1,1,2}, {1,2,1}, {2,1,1}, {2,2}, {1,3}, {3,1}

*/

int main() {
    int stairs = 4;
    
    vector<long int> memo(stairs+1, 0);
    
    for(int i = 1; i <= 3; i++){
        for(int j = 1; j <= stairs; j++){
            if(j == i) memo[j] += 1;
            else if(j > i) memo[j] = max(memo[j], (memo[j] + memo[i]));
            else continue;
        }
    }
    cout << memo[stairs];
}