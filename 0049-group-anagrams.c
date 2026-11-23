// 49. Group Anagrams (Medium)
// https://leetcode.com/problems/group-anagrams/

int cmpChar(const void* a, const void* b) {
    return (*(char*)a - *(char*)b);
}

char*** groupAnagrams(char** strs, int strsSize, int* returnSize, int** returnColumnSizes) {
    *returnSize = 0;
    if (strsSize == 0) return NULL;
    char*** result = malloc(strsSize * sizeof(char**));
    *returnColumnSizes = calloc(strsSize, sizeof(int));
    char** keys = malloc(strsSize * sizeof(char*));
    for (int i = 0; i < strsSize; i++) {
        int len = strlen(strs[i]);
        char* sorted = malloc((len + 1) * sizeof(char));
        strcpy(sorted, strs[i]);
        qsort(sorted, len, sizeof(char), cmpChar);

        int found = -1;
        for (int g = 0; g < *returnSize; g++) {
            if (strcmp(keys[g], sorted) == 0) {
                found = g;
                break;
            }
        }
        if (found == -1) {
            found = (*returnSize)++;
            keys[found] = sorted;
            result[found] = malloc(strsSize * sizeof(char*));
        } else {
            free(sorted);
        }
        result[found][(*returnColumnSizes)[found]++] = strs[i];
    }
    for (int g = 0; g < *returnSize; g++) {
        free(keys[g]);
    }
    free(keys);
    return result;
}
