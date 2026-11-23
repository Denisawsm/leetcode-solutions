// 77. Combinations (Medium)
// https://leetcode.com/problems/combinations/

void backtrackComb(int n, int k, int start, int* current, int depth, int*** result, int* returnSize, int* capacity, int** returnColumnSizes) {
    if (depth == k) {
        if (*returnSize >= *capacity) {
            *capacity *= 2;
            *result = realloc(*result, (*capacity) * sizeof(int*));
            *returnColumnSizes = realloc(*returnColumnSizes, (*capacity) * sizeof(int));
        }
        (*result)[*returnSize] = malloc(k * sizeof(int));
        memcpy((*result)[*returnSize], current, k * sizeof(int));
        (*returnColumnSizes)[*returnSize] = k;
        (*returnSize)++;
        return;
    }
    for (int i = start; i <= n - (k - depth) + 1; i++) {
        current[depth] = i;
        backtrackComb(n, k, i + 1, current, depth + 1, result, returnSize, capacity, returnColumnSizes);
    }
}

int** combine(int n, int k, int* returnSize, int** returnColumnSizes) {
    int capacity = 64;
    *returnSize = 0;
    int** result = malloc(capacity * sizeof(int*));
    *returnColumnSizes = malloc(capacity * sizeof(int));
    int* current = malloc(k * sizeof(int));
    backtrackComb(n, k, 1, current, 0, &result, returnSize, &capacity, returnColumnSizes);
    free(current);
    return result;
}
