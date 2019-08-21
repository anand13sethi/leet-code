/*

There are ‘n’ houses built in a line. A thief wants to steal maximum possible money from 
these houses. The only restriction the thief has is that he can’t steal from two consecutive 
houses, as that would alert the security system. How should the thief maximize his stealing?
Given a number array representing the wealth of ‘n’ houses, determine the maximum amount of money 
the thief can steal without alerting the security system.

Example 1:
    Input: {2, 5, 1, 3, 6, 2, 4}
    Output: 15
    Explanation: The thief should steal from houses 5 + 6 + 4

Example 2:
    Input: {2, 10, 14, 8, 1}
    Output: 18
    Explanation: The thief should steal from houses 10 + 8

*/

int main(){
    vector<int> house = {2, 10, 14, 8, 1};
    
    int n = house.size();
    
    vector<int> memo(n);
    
    memo[0] = house[0];
    memo[1] = house[1];
    
    for(int i = 2; i < n; i++){
        memo[i] = max(house[i], max(memo[i-1], house[i] + memo[i-2]));
    }
    
    cout<<memo[n-1];
}