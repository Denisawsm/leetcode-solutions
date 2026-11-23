// 68. Text Justification (Hard)
// https://leetcode.com/problems/text-justification/

char** fullJustify(char** words, int wordsSize, int maxWidth, int* returnSize) {
    char** res = malloc(wordsSize * sizeof(char*));
    *returnSize = 0;
    int i = 0;

    while (i < wordsSize) {
        int j = i;
        int lineLen = strlen(words[j]);
        j++;
        while (j < wordsSize && lineLen + 1 + (int)strlen(words[j]) <= maxWidth) {
            lineLen += 1 + strlen(words[j]);
            j++;
        }

        int numWords = j - i;
        int totalChars = 0;
        for (int k = i; k < j; k++) {
            totalChars += strlen(words[k]);
        }
        int totalSpaces = maxWidth - totalChars;

        char* line = malloc((maxWidth + 1) * sizeof(char));
        int pos = 0;

        if (j == wordsSize || numWords == 1) {
            for (int k = i; k < j; k++) {
                int wLen = strlen(words[k]);
                memcpy(line + pos, words[k], wLen);
                pos += wLen;
                if (k < j - 1) {
                    line[pos++] = ' ';
                }
            }
            while (pos < maxWidth) {
                line[pos++] = ' ';
            }
        } else {
            int gaps = numWords - 1;
            int baseSpaces = totalSpaces / gaps;
            int extraSpaces = totalSpaces % gaps;
            for (int k = i; k < j; k++) {
                int wLen = strlen(words[k]);
                memcpy(line + pos, words[k], wLen);
                pos += wLen;
                if (k < j - 1) {
                    int sp = baseSpaces + ((k - i) < extraSpaces ? 1 : 0);
                    for (int s = 0; s < sp; s++) {
                        line[pos++] = ' ';
                    }
                }
            }
        }
        line[maxWidth] = '\0';
        res[(*returnSize)++] = line;
        i = j;
    }
    return res;
}
