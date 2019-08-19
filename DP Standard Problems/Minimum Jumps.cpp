
/*

Problem Statement
Given an array of positive numbers, where each element represents the max number of jumps that 
can be made forward from that element, write a program to find the minimum number of jumps needed 
to reach the end of the array (starting from the first element). If an element is 0, then we cannot 
move through that element.

Example 1:
    Input = {2,1,1,1,4}
    Output = 3
    Explanation: Starting from index '0', we can reach the last index through: 0->2->3->4

Example 2:
    Input = {1,1,3,6,9,3,0,1,3}
    Output = 4
    Explanation: Starting from index '0', we can reach the last index through: 0->1->2->3->8

*/

int main() {
    vector<int> arr = {1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9};
    int n = arr.size();
    
    //O(n^2) Time (Worst case), O(n) Space.
    
    vector<int> memo(n, 0);
    
    for(int i = n-2; i >= 0; i--){
        if (arr[i] == 0) memo[i] = INT_MAX;
        else if(arr[i] >= n-i-1) memo[i] = 1;
        else{
            int min = INT_MAX;
            for(int j = i+1; j < n && j <= (i+arr[i]); j++){
                min = memo[j] < min ? memo[j] : min;
            }
            if(min != INT_MAX) memo[i] = (1 + min);
            else memo[i] = min;
        }
    }
    
    cout << memo[0];
    
    //O(n) Time, O(1) Space.
    
    int max_reach = arr[0], steps = arr[0], jump = 1;
    
    for(int i = 1; i < n; i++){
        if(i == n-1) {
            cout << jump;
            exit(0);
        }
        
        max_reach = max(max_reach, i+arr[i]);
        steps --;
        
        if(steps == 0){
            jump++;
            
            if(i >= max_reach) {
                cout << '-1';
                exit(0);
            }
            steps = max_reach - i;
        }
    }
    
}