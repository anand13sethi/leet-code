/*
Link - https://leetcode.com/problems/reverse-integer
*/


int reverse(int x) {
    int new_number = 0, temp;
    while(x){
        temp = x % 10;
        if(new_number > INT_MAX/10 || (new_number == INT_MAX/10 && temp > 7))
            return 0;
        if(new_number < INT_MIN/10 || (new_number == INT_MIN/10 && temp < -8))
            return 0;
        new_number = new_number * 10 + temp;
        x = x / 10;
    }
    return new_number;
}