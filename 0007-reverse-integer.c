// 7. Reverse Integer (Medium)
// https://leetcode.com/problems/reverse-integer/

int reverse(int x) {
    long rev = 0; // Use long to catch overflow before casting/returning
    
    while (x != 0) {
        int pop = x % 10; // Get the last digit
        x /= 10;          // Remove the last digit from x
        
        // Check if multiplying by 10 and adding 'pop' will overflow a 32-bit int
        if (rev > INT_MAX / 10 || (rev == INT_MAX / 10 && pop > 7)) return 0;
        if (rev < INT_MIN / 10 || (rev == INT_MIN / 10 && pop < -8)) return 0;
        
        rev = rev * 10 + pop; // Push the digit onto our reversed number
    }
    
    return (int)rev;
}

