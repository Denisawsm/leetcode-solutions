// 64. Minimum Path Sum (Medium)
// https://leetcode.com/problems/minimum-path-sum/

int minPathSum(int** grid, int gridSize, int* gridColSize) {
    int m = gridSize;
    int n = gridColSize[0];
    int* dp = malloc(n * sizeof(int));
    dp[0] = grid[0][0];
    for (int j = 1; j < n; j++) {
        dp[j] = dp[j - 1] + grid[0][j];
    }
    for (int i = 1; i < m; i++) {
        dp[0] += grid[i][0];
        for (int j = 1; j < n; j++) {
            int minPrev = dp[j] < dp[j - 1] ? dp[j] : dp[j - 1];
            dp[j] = grid[i][j] + minPrev;
        }
    }
    int ans = dp[n - 1];
    free(dp);
    return ans;
}
