// 54. Spiral Matrix (Medium)
// https://leetcode.com/problems/spiral-matrix/

int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize) {
    int rows = matrixSize;
    int cols = matrixColSize[0];
    int total = rows * cols;
    int* result = malloc(total * sizeof(int));
    *returnSize = 0;

    int top = 0, bottom = rows - 1, left = 0, right = cols - 1;
    while (top <= bottom && left <= right) {
        for (int j = left; j <= right; j++) {
            result[(*returnSize)++] = matrix[top][j];
        }
        top++;
        for (int i = top; i <= bottom; i++) {
            result[(*returnSize)++] = matrix[i][right];
        }
        right--;
        if (top <= bottom) {
            for (int j = right; j >= left; j--) {
                result[(*returnSize)++] = matrix[bottom][j];
            }
            bottom--;
        }
        if (left <= right) {
            for (int i = bottom; i >= top; i--) {
                result[(*returnSize)++] = matrix[i][left];
            }
            left++;
        }
    }
    return result;
}
