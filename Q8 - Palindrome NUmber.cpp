/*
Link - https://leetcode.com/problems/palindrome-number/
*/


bool isPalindrome(int x) {
    if(x < 0){
        return false;
    }
    else{
        int temp, rev = 0, y = x;
        while(y){
            temp = y % 10;
            if(rev > INT_MAX/10 || (rev == INT_MAX/10 && temp > 7))
                return false;
            rev = rev * 10 + temp;
            y = y/10;
        }
        if(rev == x){
            return true;
        }
    }
    return false;
}