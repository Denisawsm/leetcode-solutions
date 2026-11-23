// 72. Edit Distance (Medium)
// https://leetcode.com/problems/edit-distance/

int minEditDist(int a, int b, int c) {
    int m = a < b ? a : b;
    return m < c ? m : c;
}

int minDistance(char* word1, char* word2) {
    int m = strlen(word1);
    int n = strlen(word2);
    int* dp = malloc((n + 1) * sizeof(int));
    for (int j = 0; j <= n; j++) {
        dp[j] = j;
    }
    for (int i = 1; i <= m; i++) {
        int prevDiag = dp[0];
        dp[0] = i;
        for (int j = 1; j <= n; j++) {
            int temp = dp[j];
            if (word1[i - 1] == word2[j - 1]) {
                dp[j] = prevDiag;
            } else {
                dp[j] = 1 + minEditDist(prevDiag, dp[j], dp[j - 1]);
            }
            prevDiag = temp;
        }
    }
    int ans = dp[n];
    free(dp);
    return ans;
}
