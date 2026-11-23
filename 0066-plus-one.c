// 66. Plus One (Easy)
// https://leetcode.com/problems/plus-one/

int* plusOne(int* digits, int digitsSize, int* returnSize) {
    for (int i = digitsSize - 1; i >= 0; i--) {
        if (digits[i] < 9) {
            digits[i]++;
            int* ans = malloc(digitsSize * sizeof(int));
            memcpy(ans, digits, digitsSize * sizeof(int));
            *returnSize = digitsSize;
            return ans;
        }
        digits[i] = 0;
    }
    int* ans = calloc(digitsSize + 1, sizeof(int));
    ans[0] = 1;
    *returnSize = digitsSize + 1;
    return ans;
}
