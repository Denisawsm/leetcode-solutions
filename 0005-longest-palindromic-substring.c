// 5. Longest Palindromic Substring (Medium)
// https://leetcode.com/problems/longest-palindromic-substring/

#include <string.h>
#include <stdlib.h>

// Helper function to expand around a center and return the length of the palindrome
int expandAroundCenter(char* s, int left, int right, int* start, int* maxLen) {
    int n = strlen(s);
    while (left >= 0 && right < n && s[left] == s[right]) {
        left--;
        right++;
    }
    
    // The previous valid indices were (left + 1) to (right - 1)
    int currentLen = right - left - 1;
    if (currentLen > *maxLen) {
        *maxLen = currentLen;
        *start = left + 1;
    }
    return currentLen;
}

char* longestPalindrome(char* s) {
    if (s == NULL || strlen(s) < 1) return "";
    
    int start = 0;
    int maxLen = 0;
    int n = strlen(s);
    
    for (int i = 0; i < n; i++) {
        // Odd length palindrome (e.g., "aba")
        expandAroundCenter(s, i, i, &start, &maxLen);
        // Even length palindrome (e.g., "abba")
        expandAroundCenter(s, i, i + 1, &start, &maxLen);
    }
    
    // Allocate memory for the resulting substring (+1 for the null-terminator)
    char* result = (char*)malloc((maxLen + 1) * sizeof(char));
    strncpy(result, s + start, maxLen);
    result[maxLen] = '\0';
    
    return result;
}
