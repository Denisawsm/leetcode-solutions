// 10. Regular Expression Matching (Hard)
// https://leetcode.com/problems/regular-expression-matching/

#include <stdbool.h>
#include <string.h>

bool isMatch(char* s, char* p) {
    int m = strlen(s);
    int n = strlen(p);
    
    // dp[i][j] represents whether s[0..i-1] matches p[0..j-1]
    bool dp[m + 1][n + 1];
    memset(dp, 0, sizeof(dp));
    
    // Base case: empty string and empty pattern match
    dp[0][0] = true;
    
    // Handle patterns like "a*", "a*b*", etc., that can match an empty string
    for (int j = 2; j <= n; j++) {
        if (p[j - 1] == '*') {
            dp[0][j] = dp[0][j - 2];
        }
    }
    
    // Fill the DP table iteratively
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            // Case 1: Current characters match directly or pattern has '.'
            if (p[j - 1] == s[i - 1] || p[j - 1] == '.') {
                dp[i][j] = dp[i - 1][j - 1];
            } 
            // Case 2: Pattern has '*'
            else if (p[j - 1] == '*') {
                // Option A: Zero occurrences (skip the element and its '*')
                dp[i][j] = dp[i][j - 2];
                
                // Option B: One or more occurrences (if preceding element matches s[i-1])
                char prev_char = p[j - 2];
                if (prev_char == s[i - 1] || prev_char == '.') {
                    dp[i][j] = dp[i][j] || dp[i - 1][j];
                }
            }
        }
    }
    
    // Return whether the entire string matches the entire pattern
    return dp[m][n];
}
