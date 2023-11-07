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
    int dfs (TreeNode* node, vector < int > & frq)
    {
        int ans = 0;
        frq[node-> val]++;
        if (node -> left == NULL and node -> right == NULL)
        {
            int odd = 0;
            for ( int i = 1  ; i <= 9 ; i++) {
                odd += (frq[i] & 1 == 1);
            }
            if (odd <= 1)
                ans++;
        }
        if (node-> left != NULL)
            ans += dfs(node-> left, frq);
        
        if (node-> right != NULL)
            ans += dfs(node-> right, frq);
        
        frq[node-> val]--;
        return ans;
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        vector < int > frq  (10, 0);
        return dfs(root, frq);
    }
};