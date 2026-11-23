// 63. Unique Paths II (Medium)
// https://leetcode.com/problems/unique-paths-ii/

int uniquePathsWithObstacles(int** obstacleGrid, int obstacleGridSize, int* obstacleGridColSize) {
    int m = obstacleGridSize;
    int n = obstacleGridColSize[0];
    if (obstacleGrid[0][0] == 1) return 0;

    long long* dp = calloc(n, sizeof(long long));
    dp[0] = 1;
    for (int j = 1; j < n; j++) {
        dp[j] = (obstacleGrid[0][j] == 0) ? dp[j - 1] : 0;
    }
    for (int i = 1; i < m; i++) {
        dp[0] = (obstacleGrid[i][0] == 0) ? dp[0] : 0;
        for (int j = 1; j < n; j++) {
            if (obstacleGrid[i][j] == 1) {
                dp[j] = 0;
            } else {
                dp[j] += dp[j - 1];
            }
        }
    }
    int ans = (int)dp[n - 1];
    free(dp);
    return ans;
}
