// 93. Restore IP Addresses (Medium)
// https://leetcode.com/problems/restore-ip-addresses/

bool validSegment(const char* s, int start, int len) {
    if (len <= 0 || len > 3) return false;
    if (s[start] == '0' && len > 1) return false;
    int val = 0;
    for (int i = 0; i < len; i++) {
        val = val * 10 + (s[start + i] - '0');
    }
    return val <= 255;
}

void backtrackIP(const char* s, int n, int idx, int seg, char* buf, int pos, char*** res, int* returnSize, int* capacity) {
    if (seg == 4) {
        if (idx == n) {
            if (*returnSize >= *capacity) {
                *capacity *= 2;
                *res = realloc(*res, (*capacity) * sizeof(char*));
            }
            buf[pos - 1] = '\0';
            (*res)[*returnSize] = malloc(pos * sizeof(char));
            strcpy((*res)[*returnSize], buf);
            (*returnSize)++;
        }
        return;
    }

    for (int len = 1; len <= 3 && idx + len <= n; len++) {
        if (validSegment(s, idx, len)) {
            memcpy(buf + pos, s + idx, len);
            buf[pos + len] = '.';
            backtrackIP(s, n, idx + len, seg + 1, buf, pos + len + 1, res, returnSize, capacity);
        }
    }
}

char** restoreIpAddresses(char* s, int* returnSize) {
    int capacity = 32;
    *returnSize = 0;
    char** res = malloc(capacity * sizeof(char*));
    int n = strlen(s);
    if (n < 4 || n > 12) return res;
    char* buf = malloc((n + 5) * sizeof(char));
    backtrackIP(s, n, 0, 0, buf, 0, &res, returnSize, &capacity);
    free(buf);
    return res;
}
