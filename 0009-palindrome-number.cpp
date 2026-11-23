// 9. Palindrome Number (Easy)
// https://leetcode.com/problems/palindrome-number/

class Solution {
public:
    bool isPalindrome(int x) {
          int lDig;
       long long rev=0;
       int temp = x;
       if(temp<0)
       {
        return false;
       }
       while(temp>0)
       {
        lDig=temp%10;
        rev=rev*10+lDig;
        temp/=10;
       }
       return rev==x;
    }
};
