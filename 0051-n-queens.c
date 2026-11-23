// 51. N-Queens (Hard)
// https://leetcode.com/problems/n-queens/

bool isSafeQueens(char** board, int n, int row, int col) {
    for (int i = 0; i < row; i++) {
        if (board[i][col] == 'Q') return false;
    }
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 'Q') return false;
    }
    for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
        if (board[i][j] == 'Q') return false;
    }
    return true;
}

void backtrackNQueens(int n, int row, char** board, char**** result, int* returnSize, int* capacity, int** returnColumnSizes) {
    if (row == n) {
        if (*returnSize >= *capacity) {
            *capacity *= 2;
            *result = realloc(*result, (*capacity) * sizeof(char**));
            *returnColumnSizes = realloc(*returnColumnSizes, (*capacity) * sizeof(int));
        }
        char** copy = malloc(n * sizeof(char*));
        for (int i = 0; i < n; i++) {
            copy[i] = malloc((n + 1) * sizeof(char));
            strcpy(copy[i], board[i]);
        }
        (*result)[*returnSize] = copy;
        (*returnColumnSizes)[*returnSize] = n;
        (*returnSize)++;
        return;
    }
    for (int col = 0; col < n; col++) {
        if (isSafeQueens(board, n, row, col)) {
            board[row][col] = 'Q';
            backtrackNQueens(n, row + 1, board, result, returnSize, capacity, returnColumnSizes);
            board[row][col] = '.';
        }
    }
}

char*** solveNQueens(int n, int* returnSize, int** returnColumnSizes) {
    int capacity = 32;
    *returnSize = 0;
    char*** result = malloc(capacity * sizeof(char**));
    *returnColumnSizes = malloc(capacity * sizeof(int));
    char** board = malloc(n * sizeof(char*));
    for (int i = 0; i < n; i++) {
        board[i] = malloc((n + 1) * sizeof(char));
        memset(board[i], '.', n);
        board[i][n] = '\0';
    }
    backtrackNQueens(n, 0, board, &result, returnSize, &capacity, returnColumnSizes);
    for (int i = 0; i < n; i++) {
        free(board[i]);
    }
    free(board);
    return result;
}
