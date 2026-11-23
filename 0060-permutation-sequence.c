// 60. Permutation Sequence (Hard)
// https://leetcode.com/problems/permutation-sequence/

char* getPermutation(int n, int k) {
    int fact = 1;
    int nums[9];
    for (int i = 1; i < n; i++) {
        fact *= i;
        nums[i - 1] = i;
    }
    nums[n - 1] = n;

    k--;
    char* ans = malloc((n + 1) * sizeof(char));
    int size = n;
    for (int i = 0; i < n; i++) {
        int idx = k / fact;
        ans[i] = '0' + nums[idx];
        for (int j = idx; j < size - 1; j++) {
            nums[j] = nums[j + 1];
        }
        size--;
        k %= fact;
        if (size > 0) {
            fact /= size;
        }
    }
    ans[n] = '\0';
    return ans;
}
