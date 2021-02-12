#include <vector>

using std::vector;

class Solution {
 public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        traverse(root, ans);

        return ans;
    }

    void traverse(TreeNode* root, vector<int>& ans) {
        if (root == nullptr) return;

        trav(root->left, ans);
        ans.push_back(root->val);
        trav(root->right, ans);
    }
};
