// 62. Unique Paths (Medium)
// https://leetcode.com/problems/unique-paths/

int uniquePaths(int m, int n) {
    int* dp = malloc(n * sizeof(int));
    for (int j = 0; j < n; j++) {
        dp[j] = 1;
    }
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            dp[j] += dp[j - 1];
        }
    }
    int ans = dp[n - 1];
    free(dp);
    return ans;
}
