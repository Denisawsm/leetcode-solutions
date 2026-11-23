// 87. Scramble String (Hard)
// https://leetcode.com/problems/scramble-string/

bool isScrambleRec(const char* s1, const char* s2, int len, int i1, int i2, int* memo, int n) {
    int idx = (i1 * n + i2) * (n + 1) + len;
    if (memo[idx] != -1) return memo[idx] == 1;

    if (len == 1) {
        bool eq = (s1[i1] == s2[i2]);
        memo[idx] = eq ? 1 : 0;
        return eq;
    }

    int count[26] = {0};
    for (int k = 0; k < len; k++) {
        count[s1[i1 + k] - 'a']++;
        count[s2[i2 + k] - 'a']--;
    }
    for (int c = 0; c < 26; c++) {
        if (count[c] != 0) {
            memo[idx] = 0;
            return false;
        }
    }

    for (int k = 1; k < len; k++) {
        if (isScrambleRec(s1, s2, k, i1, i2, memo, n) &&
            isScrambleRec(s1, s2, len - k, i1 + k, i2 + k, memo, n)) {
            memo[idx] = 1;
            return true;
        }
        if (isScrambleRec(s1, s2, k, i1, i2 + len - k, memo, n) &&
            isScrambleRec(s1, s2, len - k, i1 + k, i2, memo, n)) {
            memo[idx] = 1;
            return true;
        }
    }

    memo[idx] = 0;
    return false;
}

bool isScramble(char* s1, char* s2) {
    int n = strlen(s1);
    if (n != (int)strlen(s2)) return false;
    if (strcmp(s1, s2) == 0) return true;
    int total = n * n * (n + 1);
    int* memo = malloc(total * sizeof(int));
    for (int i = 0; i < total; i++) memo[i] = -1;
    bool ans = isScrambleRec(s1, s2, n, 0, 0, memo, n);
    free(memo);
    return ans;
}
