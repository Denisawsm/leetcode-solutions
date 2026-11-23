// 46. Permutations (Medium)
// https://leetcode.com/problems/permutations/

void swapInt(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void backtrackPerm(int* nums, int numsSize, int start, int*** result, int* returnSize, int* capacity, int** returnColumnSizes) {
    if (start == numsSize) {
        if (*returnSize >= *capacity) {
            *capacity *= 2;
            *result = realloc(*result, (*capacity) * sizeof(int*));
            *returnColumnSizes = realloc(*returnColumnSizes, (*capacity) * sizeof(int));
        }
        (*result)[*returnSize] = malloc(numsSize * sizeof(int));
        memcpy((*result)[*returnSize], nums, numsSize * sizeof(int));
        (*returnColumnSizes)[*returnSize] = numsSize;
        (*returnSize)++;
        return;
    }
    for (int i = start; i < numsSize; i++) {
        swapInt(&nums[start], &nums[i]);
        backtrackPerm(nums, numsSize, start + 1, result, returnSize, capacity, returnColumnSizes);
        swapInt(&nums[start], &nums[i]);
    }
}

int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    int capacity = 64;
    *returnSize = 0;
    int** result = malloc(capacity * sizeof(int*));
    *returnColumnSizes = malloc(capacity * sizeof(int));
    backtrackPerm(nums, numsSize, 0, &result, returnSize, &capacity, returnColumnSizes);
    return result;
}
