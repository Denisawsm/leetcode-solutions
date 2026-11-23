// 22. Generate Parentheses (Medium)
// https://leetcode.com/problems/generate-parentheses/

void backtrack(char*** result, int* returnSize, char* current, int open, int close, int max, int* capacity) {
    if (strlen(current) == max * 2) {
        if (*returnSize >= *capacity) {
            *capacity *= 2;
            *result = realloc(*result, (*capacity) * sizeof(char*));
        }
        (*result)[*returnSize] = strdup(current);
        (*returnSize)++;
        return;
    }
    if (open < max) {
        int len = strlen(current);
        current[len] = '(';
        current[len + 1] = '\0';
        backtrack(result, returnSize, current, open + 1, close, max, capacity);
        current[len] = '\0';
    }
    if (close < open) {
        int len = strlen(current);
        current[len] = ')';
        current[len + 1] = '\0';
        backtrack(result, returnSize, current, open, close + 1, max, capacity);
        current[len] = '\0';
    }
}

char** generateParenthesis(int n, int* returnSize) {
    int capacity = 100;
    char** result = malloc(capacity * sizeof(char*));
    *returnSize = 0;
    char* current = malloc((2 * n + 1) * sizeof(char));
    current[0] = '\0';
    backtrack(&result, returnSize, current, 0, 0, n, &capacity);
    free(current);
    return result;
}
