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
    vector < int > lvlSum;
    void Sum (TreeNode* node, int lvl)
    {
        if(node == nullptr)
            return;

        lvlSum[lvl] += node -> val;
        Sum(node -> left, lvl + 1);
        Sum(node -> right, lvl + 1);
    }

    int Get(TreeNode* node, bool left)
    {
        if (left and node -> left != nullptr)
            return node -> left -> val;
        if (!left and node -> right != nullptr)
            return node -> right -> val;
        return 0;
    }

    void dfs (TreeNode* node, int willremoved, int lvl)
    {
        if(node == nullptr)
            return;

        int tempLeftVal = Get(node, 1);
        node -> val = lvlSum[lvl] - willremoved - node -> val;

        dfs (node -> left, Get(node, 0), lvl + 1);
        dfs (node -> right, tempLeftVal,  lvl + 1);
    }


    TreeNode* replaceValueInTree(TreeNode* root) {
        lvlSum.resize(100000, 0);
        Sum(root, 0);
        dfs(root, 0 , 0);
        return root;
    }
};