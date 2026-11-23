// 56. Merge Intervals (Medium)
// https://leetcode.com/problems/merge-intervals/

int cmpInterval(const void* a, const void* b) {
    const int* ia = *(const int* const*)a;
    const int* ib = *(const int* const*)b;
    if (ia[0] != ib[0]) return (ia[0] > ib[0]) - (ia[0] < ib[0]);
    return (ia[1] > ib[1]) - (ia[1] < ib[1]);
}

int** merge(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize, int** returnColumnSizes) {
    *returnSize = 0;
    if (intervalsSize == 0) return NULL;
    qsort(intervals, intervalsSize, sizeof(int*), cmpInterval);

    int** result = malloc(intervalsSize * sizeof(int*));
    *returnColumnSizes = malloc(intervalsSize * sizeof(int));

    result[0] = malloc(2 * sizeof(int));
    result[0][0] = intervals[0][0];
    result[0][1] = intervals[0][1];
    (*returnColumnSizes)[0] = 2;
    *returnSize = 1;

    for (int i = 1; i < intervalsSize; i++) {
        int* last = result[*returnSize - 1];
        if (intervals[i][0] <= last[1]) {
            if (intervals[i][1] > last[1]) {
                last[1] = intervals[i][1];
            }
        } else {
            result[*returnSize] = malloc(2 * sizeof(int));
            result[*returnSize][0] = intervals[i][0];
            result[*returnSize][1] = intervals[i][1];
            (*returnColumnSizes)[*returnSize] = 2;
            (*returnSize)++;
        }
    }
    return result;
}
