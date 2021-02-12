class Solution {
 public:
    bool isValidBST(TreeNode* root) {
        return IsValidBST(root, nullptr, nullptr);
    }
    
    bool IsValidBST(TreeNode* root, TreeNode* min, TreeNode* max) {
        if (root == nullptr) return true;

        if (min != nullptr && root->val <= min->val) return false;
        if (max != nullptr && root->val >= max->val) return false;

        return IsValidBST(root->left, min, root) && IsValidBST(root->right, root, max);
    }
};
