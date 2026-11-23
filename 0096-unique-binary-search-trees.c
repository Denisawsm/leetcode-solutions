// 96. Unique Binary Search Trees (Medium)
// https://leetcode.com/problems/unique-binary-search-trees/

int numTrees(int n) {
    long long* dp = calloc(n + 1, sizeof(long long));
    dp[0] = 1;
    for (int nodes = 1; nodes <= n; nodes++) {
        for (int root = 1; root <= nodes; root++) {
            dp[nodes] += dp[root - 1] * dp[nodes - root];
        }
    }
    int ans = (int)dp[n];
    free(dp);
    return ans;
}
