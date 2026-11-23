// 99. Recover Binary Search Tree (Medium)
// https://leetcode.com/problems/recover-binary-search-tree/

void recoverHelper(struct TreeNode* root, struct TreeNode** prev, struct TreeNode** first, struct TreeNode** second) {
    if (!root) return;
    recoverHelper(root->left, prev, first, second);
    if (*prev && (*prev)->val > root->val) {
        if (!*first) {
            *first = *prev;
        }
        *second = root;
    }
    *prev = root;
    recoverHelper(root->right, prev, first, second);
}

void recoverTree(struct TreeNode* root) {
    struct TreeNode* prev = NULL;
    struct TreeNode* first = NULL;
    struct TreeNode* second = NULL;
    recoverHelper(root, &prev, &first, &second);
    if (first && second) {
        int temp = first->val;
        first->val = second->val;
        second->val = temp;
    }
}
