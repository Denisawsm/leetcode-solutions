// 5. Longest Palindromic Substring (Medium)
// https://leetcode.com/problems/longest-palindromic-substring/

#include <string.h>
#include <stdlib.h>

int expandAroundCenter(char* s, int left, int right, int* start, int* maxLen) {
    int n = strlen(s);
    while (left >= 0 && right < n && s[left] == s[right]) {
        left--;
        right++;
    }
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
        expandAroundCenter(s, i, i, &start, &maxLen);
        expandAroundCenter(s, i, i + 1, &start, &maxLen);
    }

    char* result = (char*)malloc((maxLen + 1) * sizeof(char));
    strncpy(result, s + start, maxLen);
    result[maxLen] = '\0';
    
    return result;
}
