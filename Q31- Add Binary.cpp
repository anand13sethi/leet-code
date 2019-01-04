/*
Link - https://leetcode.com/problems/add-binary
*/

class Solution {
public:
    string addBinary(string a, string b) {
        int l1 = a.size(), l2 = b.size(), i = 0, carry = 0;
        int x;
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        string ans;
        while(i < l1 && i < l2){
            x = (a[i] - '0') + (b[i] - '0') + carry;
            carry = 0;
            if(x == 2){
                carry = 1;
                x = 0;
            }
            if(x == 3){
                carry = 1;
                x = 1;
            }
            ans.push_back(x+'0');
            i++;
        }
        while(i < l1){
            x = (a[i] - '0') + carry;
            carry = 0;
            if(x == 2){
                carry = 1;
                x = 0;
            }
            if(x == 3){
                carry = 1;
                x = 1;
            }
            ans.push_back(x+'0');
            i++;
        }
        while(i < l2){
            x = (b[i] - '0') + carry;
            carry = 0;
            if(x == 2){
                carry = 1;
                x = 0;
            }
            if(x == 3){
                carry = 1;
                x = 1;
            }
            ans.push_back(x+'0');
            i++;
        }
        if(carry)
            ans.push_back(carry+'0');
        reverse(ans.begin(), ans.end());
        return ans;
    }
};