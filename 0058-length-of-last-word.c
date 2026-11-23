// 58. Length of Last Word (Easy)
// https://leetcode.com/problems/length-of-last-word/

int lengthOfLastWord(char* s) {
    int len = strlen(s);
    int i = len - 1;
    while (i >= 0 && s[i] == ' ') {
        i--;
    }
    int count = 0;
    while (i >= 0 && s[i] != ' ') {
        count++;
        i--;
    }
    return count;
}
