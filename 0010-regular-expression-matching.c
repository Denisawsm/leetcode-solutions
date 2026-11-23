// 10. Regular Expression Matching (Hard)
// https://leetcode.com/problems/regular-expression-matching/

#include <stdbool.h>
#include <string.h>

bool isMatch(char* s, char* p) {
    int m = strlen(s);
    int n = strlen(p);

    bool dp[m + 1][n + 1];
    memset(dp, 0, sizeof(dp));

    dp[0][0] = true;
    
    for (int j = 2; j <= n; j++) {
        if (p[j - 1] == '*') {
            dp[0][j] = dp[0][j - 2];
        }
    }
    
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (p[j - 1] == s[i - 1] || p[j - 1] == '.') {
                dp[i][j] = dp[i - 1][j - 1];
            } 
            else if (p[j - 1] == '*') {
                dp[i][j] = dp[i][j - 2];
                char prev_char = p[j - 2];
                if (prev_char == s[i - 1] || prev_char == '.') {
                    dp[i][j] = dp[i][j] || dp[i - 1][j];
                }
            }
        }
    }
    return dp[m][n];
}
