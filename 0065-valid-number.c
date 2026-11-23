// 65. Valid Number (Hard)
// https://leetcode.com/problems/valid-number/

bool isNumber(char* s) {
    int i = 0;
    int n = strlen(s);
    if (s[i] == '+' || s[i] == '-') i++;

    bool hasDigit = false;
    bool hasDot = false;
    while (i < n && (isdigit((unsigned char)s[i]) || s[i] == '.')) {
        if (isdigit((unsigned char)s[i])) {
            hasDigit = true;
        } else {
            if (hasDot) return false;
            hasDot = true;
        }
        i++;
    }
    if (!hasDigit) return false;

    if (i < n && (s[i] == 'e' || s[i] == 'E')) {
        i++;
        if (i < n && (s[i] == '+' || s[i] == '-')) i++;
        bool hasExpDigit = false;
        while (i < n && isdigit((unsigned char)s[i])) {
            hasExpDigit = true;
            i++;
        }
        if (!hasExpDigit) return false;
    }

    return i == n;
}
