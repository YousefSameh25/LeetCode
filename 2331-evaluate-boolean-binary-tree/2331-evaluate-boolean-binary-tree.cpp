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
public:
    bool dfs (TreeNode* node)
    {
        if (node -> val == 2)
            return dfs(node -> left) | dfs (node -> right);
        else if (node -> val == 3)
            return dfs(node -> left) & dfs (node -> right);
        else
            return node -> val;
    }
    bool evaluateTree(TreeNode* root) {
        return dfs (root);
    }
};