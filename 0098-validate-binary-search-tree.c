// 98. Validate Binary Search Tree (Medium)
// https://leetcode.com/problems/validate-binary-search-tree/

bool validateBST(struct TreeNode* node, long long minVal, long long maxVal) {
    if (!node) return true;
    if ((long long)node->val <= minVal || (long long)node->val >= maxVal) {
        return false;
    }
    return validateBST(node->left, minVal, node->val) &&
           validateBST(node->right, node->val, maxVal);
}

bool isValidBST(struct TreeNode* root) {
    return validateBST(root, LLONG_MIN, LLONG_MAX);
}
