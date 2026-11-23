// 40. Combination Sum II (Medium)
// https://leetcode.com/problems/combination-sum-ii/

int cmpIntAsc(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

void backtrackCombSum2(int* candidates, int candidatesSize, int target, int start, int* current, int currentSize, int*** result, int* returnSize, int* capacity, int** returnColumnSizes) {
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
        if (i > start && candidates[i] == candidates[i - 1]) continue;
        if (candidates[i] > target) break;
        current[currentSize] = candidates[i];
        backtrackCombSum2(candidates, candidatesSize, target - candidates[i], i + 1, current, currentSize + 1, result, returnSize, capacity, returnColumnSizes);
    }
}

int** combinationSum2(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes) {
    qsort(candidates, candidatesSize, sizeof(int), cmpIntAsc);
    int capacity = 64;
    *returnSize = 0;
    int** result = malloc(capacity * sizeof(int*));
    *returnColumnSizes = malloc(capacity * sizeof(int));
    int* current = malloc(candidatesSize * sizeof(int));
    backtrackCombSum2(candidates, candidatesSize, target, 0, current, 0, &result, returnSize, &capacity, returnColumnSizes);
    free(current);
    return result;
}
