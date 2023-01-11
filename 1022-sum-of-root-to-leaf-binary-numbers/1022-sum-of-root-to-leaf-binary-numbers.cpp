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
    int convert (string &s)
    {
        int ans = 0 , bit = 0;
        for (int i = s.size() - 1 ; i >= 0 ; i--)
        {
            ans += (s[i] - '0') * (1 << bit);
            bit++;
        }
        return ans;
    }
    int dfs (TreeNode* node , string s)
    {
        int ans = 0;
        s.push_back(node -> val + '0');
        if (node -> left == NULL and node -> right == NULL)
        {
            ans += convert(s);
        }
        if (node -> left != NULL)
        {
            ans += dfs (node -> left , s);
        }
        if(node -> right != NULL)
        {
            ans += dfs (node -> right , s);
        }
        return ans;
    }
    int sumRootToLeaf(TreeNode* root) {
        return dfs (root , "");
    }
};