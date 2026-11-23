// 44. Wildcard Matching (Hard)
// https://leetcode.com/problems/wildcard-matching/

bool isMatch(char* s, char* p) {
    int sLen = strlen(s);
    int pLen = strlen(p);
    bool* dp = calloc(pLen + 1, sizeof(bool));
    dp[0] = true;
    for (int j = 1; j <= pLen; j++) {
        if (p[j - 1] == '*') {
            dp[j] = dp[j - 1];
        }
    }
    for (int i = 1; i <= sLen; i++) {
        bool prevDiag = dp[0];
        dp[0] = false;
        for (int j = 1; j <= pLen; j++) {
            bool temp = dp[j];
            if (p[j - 1] == '*') {
                dp[j] = dp[j - 1] || dp[j];
            } else if (p[j - 1] == '?' || s[i - 1] == p[j - 1]) {
                dp[j] = prevDiag;
            } else {
                dp[j] = false;
            }
            prevDiag = temp;
        }
    }
    bool ans = dp[pLen];
    free(dp);
    return ans;
}
