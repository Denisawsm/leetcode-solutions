// 94. Binary Tree Inorder Traversal (Easy)
// https://leetcode.com/problems/binary-tree-inorder-traversal/

void inorderHelper(struct TreeNode* root, int** res, int* returnSize, int* capacity) {
    if (!root) return;
    inorderHelper(root->left, res, returnSize, capacity);
    if (*returnSize >= *capacity) {
        *capacity *= 2;
        *res = realloc(*res, (*capacity) * sizeof(int));
    }
    (*res)[(*returnSize)++] = root->val;
    inorderHelper(root->right, res, returnSize, capacity);
}

int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    int capacity = 64;
    *returnSize = 0;
    int* res = malloc(capacity * sizeof(int));
    inorderHelper(root, &res, returnSize, &capacity);
    return res;
}
