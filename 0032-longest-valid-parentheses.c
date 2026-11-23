// 32. Longest Valid Parentheses (Hard)
// https://leetcode.com/problems/longest-valid-parentheses/

int longestValidParentheses(char* s) {
    int left = 0, right = 0, max_len = 0;
    int len = strlen(s);

    // Pass 1: Left to Right
    for (int i = 0; i < len; i++) {
        if (s[i] == '(') {
            left++;
        } else {
            right++;
        }
        
        if (left == right) {
            int current_len = 2 * right;
            if (current_len > max_len) max_len = current_len;
        } else if (right > left) {
            left = 0;
            right = 0;
        }
    }

    // Pass 2: Right to Left
    left = 0;
    right = 0;
    for (int i = len - 1; i >= 0; i--) {
        if (s[i] == '(') {
            left++;
        } else {
            right++;
        }
        
        if (left == right) {
            int current_len = 2 * left;
            if (current_len > max_len) max_len = current_len;
        } else if (left > right) {
            left = 0;
            right = 0;
        }
    }

    return max_len;
}
