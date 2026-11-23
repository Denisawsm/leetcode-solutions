// 76. Minimum Window Substring (Hard)
// https://leetcode.com/problems/minimum-window-substring/

char* minWindow(char* s, char* t) {
    int sLen = strlen(s);
    int tLen = strlen(t);
    if (sLen == 0 || tLen == 0 || sLen < tLen) {
        char* empty = malloc(1);
        empty[0] = '\0';
        return empty;
    }

    int need[128] = {0};
    int required = 0;
    for (int i = 0; i < tLen; i++) {
        if (need[(unsigned char)t[i]] == 0) required++;
        need[(unsigned char)t[i]]++;
    }

    int win[128] = {0};
    int formed = 0;
    int left = 0, right = 0;
    int minLen = sLen + 1, startIdx = 0;

    while (right < sLen) {
        unsigned char c = (unsigned char)s[right];
        win[c]++;
        if (need[c] > 0 && win[c] == need[c]) {
            formed++;
        }

        while (left <= right && formed == required) {
            int curLen = right - left + 1;
            if (curLen < minLen) {
                minLen = curLen;
                startIdx = left;
            }
            unsigned char lc = (unsigned char)s[left];
            win[lc]--;
            if (need[lc] > 0 && win[lc] < need[lc]) {
                formed--;
            }
            left++;
        }
        right++;
    }

    if (minLen > sLen) {
        char* empty = malloc(1);
        empty[0] = '\0';
        return empty;
    }

    char* ans = malloc((minLen + 1) * sizeof(char));
    memcpy(ans, s + startIdx, minLen);
    ans[minLen] = '\0';
    return ans;
}
