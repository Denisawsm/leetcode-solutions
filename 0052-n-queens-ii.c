// 52. N-Queens II (Hard)
// https://leetcode.com/problems/n-queens-ii/

bool isSafeQueens2(int* cols, int row, int col) {
    for (int prevRow = 0; prevRow < row; prevRow++) {
        int prevCol = cols[prevRow];
        if (prevCol == col || abs(prevCol - col) == abs(prevRow - row)) {
            return false;
        }
    }
    return true;
}

void countNQueens(int n, int row, int* cols, int* count) {
    if (row == n) {
        (*count)++;
        return;
    }
    for (int col = 0; col < n; col++) {
        if (isSafeQueens2(cols, row, col)) {
            cols[row] = col;
            countNQueens(n, row + 1, cols, count);
        }
    }
}

int totalNQueens(int n) {
    int count = 0;
    int* cols = malloc(n * sizeof(int));
    countNQueens(n, 0, cols, &count);
    free(cols);
    return count;
}
