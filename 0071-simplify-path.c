// 71. Simplify Path (Medium)
// https://leetcode.com/problems/simplify-path/

char* simplifyPath(char* path) {
    int n = strlen(path);
    char** stack = malloc((n + 1) * sizeof(char*));
    int top = 0;

    char* copy = malloc((n + 1) * sizeof(char));
    strcpy(copy, path);

    char* token = strtok(copy, "/");
    while (token != NULL) {
        if (strcmp(token, ".") == 0) {
        } else if (strcmp(token, "..") == 0) {
            if (top > 0) top--;
        } else {
            stack[top++] = token;
        }
        token = strtok(NULL, "/");
    }

    char* res = malloc((n + 2) * sizeof(char));
    int pos = 0;
    if (top == 0) {
        res[pos++] = '/';
    } else {
        for (int i = 0; i < top; i++) {
            res[pos++] = '/';
            int len = strlen(stack[i]);
            memcpy(res + pos, stack[i], len);
            pos += len;
        }
    }
    res[pos] = '\0';

    free(stack);
    free(copy);
    return res;
}
