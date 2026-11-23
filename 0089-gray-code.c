// 89. Gray Code (Medium)
// https://leetcode.com/problems/gray-code/

int* grayCode(int n, int* returnSize) {
    int size = 1 << n;
    *returnSize = size;
    int* res = malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        res[i] = i ^ (i >> 1);
    }
    return res;
}
