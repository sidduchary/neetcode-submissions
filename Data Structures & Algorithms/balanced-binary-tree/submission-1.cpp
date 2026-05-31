/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
private:
    int length(TreeNode* root) {
        if(!root) return 0;
        int l = length(root->left);
        int r = length(root->right);
        return max(l, r)+1;
    }

    bool dfs(TreeNode* root) {
        if(!root) return 1;
        int l = length(root->left);
        int r = length(root->right);
        if(abs(l-r) > 1) return 0;
        if(!dfs(root->left) || !dfs(root->right))
            return 0;
        return 1;
    }

public:
    bool isBalanced(TreeNode* root) {
        return dfs(root);
    }
};
