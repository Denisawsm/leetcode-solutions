// 67. Add Binary (Easy)
// https://leetcode.com/problems/add-binary/

char* addBinary(char* a, char* b) {
    int i = strlen(a) - 1;
    int j = strlen(b) - 1;
    int maxLen = (i > j ? i : j) + 2;
    char* res = malloc((maxLen + 1) * sizeof(char));
    int k = 0, carry = 0;

    while (i >= 0 || j >= 0 || carry) {
        int sum = carry;
        if (i >= 0) sum += a[i--] - '0';
        if (j >= 0) sum += b[j--] - '0';
        res[k++] = (sum % 2) + '0';
        carry = sum / 2;
    }
    res[k] = '\0';

    for (int l = 0, r = k - 1; l < r; l++, r--) {
        char tmp = res[l];
        res[l] = res[r];
        res[r] = tmp;
    }
    return res;
}
