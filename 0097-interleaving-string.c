// 97. Interleaving String (Medium)
// https://leetcode.com/problems/interleaving-string/

bool isInterleave(char* s1, char* s2, char* s3) {
    int m = strlen(s1);
    int n = strlen(s2);
    int k = strlen(s3);
    if (m + n != k) return false;

    bool* dp = calloc(n + 1, sizeof(bool));
    dp[0] = true;
    for (int j = 1; j <= n; j++) {
        dp[j] = dp[j - 1] && (s2[j - 1] == s3[j - 1]);
    }

    for (int i = 1; i <= m; i++) {
        dp[0] = dp[0] && (s1[i - 1] == s3[i - 1]);
        for (int j = 1; j <= n; j++) {
            bool fromTop = dp[j] && (s1[i - 1] == s3[i + j - 1]);
            bool fromLeft = dp[j - 1] && (s2[j - 1] == s3[i + j - 1]);
            dp[j] = fromTop || fromLeft;
        }
    }

    bool ans = dp[n];
    free(dp);
    return ans;
}
