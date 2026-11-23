// 90. Subsets II (Medium)
// https://leetcode.com/problems/subsets-ii/

int cmpSubsets2(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

void backtrackSubsets2(int* nums, int numsSize, int start, int* current, int depth, int*** result, int* returnSize, int* capacity, int** returnColumnSizes) {
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
        if (i > start && nums[i] == nums[i - 1]) continue;
        current[depth] = nums[i];
        backtrackSubsets2(nums, numsSize, i + 1, current, depth + 1, result, returnSize, capacity, returnColumnSizes);
    }
}

int** subsetsWithDup(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    qsort(nums, numsSize, sizeof(int), cmpSubsets2);
    int capacity = 64;
    *returnSize = 0;
    int** result = malloc(capacity * sizeof(int*));
    *returnColumnSizes = malloc(capacity * sizeof(int));
    int* current = malloc(numsSize * sizeof(int));
    backtrackSubsets2(nums, numsSize, 0, current, 0, &result, returnSize, &capacity, returnColumnSizes);
    free(current);
    return result;
}
