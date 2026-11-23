// 59. Spiral Matrix II (Medium)
// https://leetcode.com/problems/spiral-matrix-ii/

int** generateMatrix(int n, int* returnSize, int** returnColumnSizes) {
    *returnSize = n;
    *returnColumnSizes = malloc(n * sizeof(int));
    int** matrix = malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        (*returnColumnSizes)[i] = n;
        matrix[i] = malloc(n * sizeof(int));
    }

    int top = 0, bottom = n - 1, left = 0, right = n - 1;
    int num = 1;
    while (top <= bottom && left <= right) {
        for (int j = left; j <= right; j++) {
            matrix[top][j] = num++;
        }
        top++;
        for (int i = top; i <= bottom; i++) {
            matrix[i][right] = num++;
        }
        right--;
        if (top <= bottom) {
            for (int j = right; j >= left; j--) {
                matrix[bottom][j] = num++;
            }
            bottom--;
        }
        if (left <= right) {
            for (int i = bottom; i >= top; i--) {
                matrix[i][left] = num++;
            }
            left++;
        }
    }
    return matrix;
}
