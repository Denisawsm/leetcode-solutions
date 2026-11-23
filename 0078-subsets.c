// 78. Subsets (Medium)
// https://leetcode.com/problems/subsets/

void backtrackSubsets(int* nums, int numsSize, int start, int* current, int depth, int*** result, int* returnSize, int* capacity, int** returnColumnSizes) {
    if (*returnSize >= *capacity) {
        *capacity *= 2;
        *result = realloc(*result, (*capacity) * sizeof(int*));
        *returnColumnSizes = realloc(*returnColumnSizes, (*capacity) * sizeof(int));
    }
    (*result)[*returnSize] = malloc(depth * sizeof(int));
    memcpy((*result)[*returnSize], current, depth * sizeof(int));
    (*returnColumnSizes)[*returnSize] = depth;
    (*returnSize)++;

    for (int i = start; i < numsSize; i++) {
        current[depth] = nums[i];
        backtrackSubsets(nums, numsSize, i + 1, current, depth + 1, result, returnSize, capacity, returnColumnSizes);
    }
}

int** subsets(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    int capacity = 64;
    *returnSize = 0;
    int** result = malloc(capacity * sizeof(int*));
    *returnColumnSizes = malloc(capacity * sizeof(int));
    int* current = malloc(numsSize * sizeof(int));
    backtrackSubsets(nums, numsSize, 0, current, 0, &result, returnSize, &capacity, returnColumnSizes);
    free(current);
    return result;
}
