// 95. Unique Binary Search Trees II (Medium)
// https://leetcode.com/problems/unique-binary-search-trees-ii/

struct TreeNode** buildTrees(int start, int end, int* count) {
    if (start > end) {
        *count = 1;
        struct TreeNode** list = malloc(sizeof(struct TreeNode*));
        list[0] = NULL;
        return list;
    }

    int cap = 16;
    *count = 0;
    struct TreeNode** result = malloc(cap * sizeof(struct TreeNode*));

    for (int rootVal = start; rootVal <= end; rootVal++) {
        int leftCount = 0, rightCount = 0;
        struct TreeNode** leftTrees = buildTrees(start, rootVal - 1, &leftCount);
        struct TreeNode** rightTrees = buildTrees(rootVal + 1, end, &rightCount);

        for (int i = 0; i < leftCount; i++) {
            for (int j = 0; j < rightCount; j++) {
                struct TreeNode* root = malloc(sizeof(struct TreeNode));
                root->val = rootVal;
                root->left = leftTrees[i];
                root->right = rightTrees[j];

                if (*count >= cap) {
                    cap *= 2;
                    result = realloc(result, cap * sizeof(struct TreeNode*));
                }
                result[(*count)++] = root;
            }
        }
        free(leftTrees);
        free(rightTrees);
    }

    return result;
}

struct TreeNode** generateTrees(int n, int* returnSize) {
    if (n == 0) {
        *returnSize = 0;
        return NULL;
    }
    return buildTrees(1, n, returnSize);
}

