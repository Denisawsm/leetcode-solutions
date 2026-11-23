// 39. Combination Sum (Medium)
// https://leetcode.com/problems/combination-sum/

void backtrackCombSum(int* candidates, int candidatesSize, int target, int start, int* current, int currentSize, int*** result, int* returnSize, int* capacity, int** returnColumnSizes, int* colCapacity) {
    if (target == 0) {
        if (*returnSize >= *capacity) {
            *capacity *= 2;
            *result = realloc(*result, (*capacity) * sizeof(int*));
            *returnColumnSizes = realloc(*returnColumnSizes, (*capacity) * sizeof(int));
        }
        (*result)[*returnSize] = malloc(currentSize * sizeof(int));
        memcpy((*result)[*returnSize], current, currentSize * sizeof(int));
        (*returnColumnSizes)[*returnSize] = currentSize;
        (*returnSize)++;
        return;
    }
    for (int i = start; i < candidatesSize; i++) {
        if (candidates[i] <= target) {
            current[currentSize] = candidates[i];
            backtrackCombSum(candidates, candidatesSize, target - candidates[i], i, current, currentSize + 1, result, returnSize, capacity, returnColumnSizes, colCapacity);
        }
    }
}

int** combinationSum(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes) {
    int capacity = 64;
    *returnSize = 0;
    int** result = malloc(capacity * sizeof(int*));
    *returnColumnSizes = malloc(capacity * sizeof(int));
    int* current = malloc(1000 * sizeof(int));
    backtrackCombSum(candidates, candidatesSize, target, 0, current, 0, &result, returnSize, &capacity, returnColumnSizes, &capacity);
    free(current);
    return result;
}
