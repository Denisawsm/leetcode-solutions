// 47. Permutations II (Medium)
// https://leetcode.com/problems/permutations-ii/

int cmpPerm2(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

void backtrackPerm2(int* nums, int numsSize, int* used, int* current, int depth, int*** result, int* returnSize, int* capacity, int** returnColumnSizes) {
    if (depth == numsSize) {
        if (*returnSize >= *capacity) {
            *capacity *= 2;
            *result = realloc(*result, (*capacity) * sizeof(int*));
            *returnColumnSizes = realloc(*returnColumnSizes, (*capacity) * sizeof(int));
        }
        (*result)[*returnSize] = malloc(numsSize * sizeof(int));
        memcpy((*result)[*returnSize], current, numsSize * sizeof(int));
        (*returnColumnSizes)[*returnSize] = numsSize;
        (*returnSize)++;
        return;
    }
    for (int i = 0; i < numsSize; i++) {
        if (used[i]) continue;
        if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1]) continue;
        used[i] = 1;
        current[depth] = nums[i];
        backtrackPerm2(nums, numsSize, used, current, depth + 1, result, returnSize, capacity, returnColumnSizes);
        used[i] = 0;
    }
}

int** permuteUnique(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    qsort(nums, numsSize, sizeof(int), cmpPerm2);
    int capacity = 64;
    *returnSize = 0;
    int** result = malloc(capacity * sizeof(int*));
    *returnColumnSizes = malloc(capacity * sizeof(int));
    int* used = calloc(numsSize, sizeof(int));
    int* current = malloc(numsSize * sizeof(int));
    backtrackPerm2(nums, numsSize, used, current, 0, &result, returnSize, &capacity, returnColumnSizes);
    free(used);
    free(current);
    return result;
}
