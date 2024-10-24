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
    unordered_map < int , vector < int >> child;
    void dfs(TreeNode* node)
    {
        if (node == nullptr)
            return;

        if (node -> left  != nullptr)
            child[node -> val].push_back(node -> left -> val);

        if (node -> right  != nullptr)
            child[node -> val].push_back(node -> right -> val);

        dfs(node -> left);
        dfs(node -> right);
    }

    bool ok(vector < int > a, vector < int > b)
    {
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        return a == b;
    }

    bool isSame (TreeNode* node)
    {
        if (node == nullptr)
            return 1;

        vector < int > children;
        if (node -> left  != nullptr)
            children.push_back(node -> left -> val);

        if (node -> right  != nullptr)
            children.push_back(node -> right -> val);

        bool ans = ok(children, child[node -> val]);

        if (!ans)
            return 0;

        ans &= isSame(node -> left);
        ans &= isSame(node -> right);
        return ans;
    }



    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        if (root1 == nullptr and root2 != nullptr)
            return 0;
        if (root2 == nullptr and root1 != nullptr)
            return 0;
            
        dfs(root1);
        return isSame(root2);
    }
};