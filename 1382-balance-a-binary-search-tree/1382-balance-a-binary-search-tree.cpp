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
    void dfs (vector < int > & v , TreeNode* node)
    {
        v.push_back(node->val);
        if (node->left != NULL)
            dfs(v,node->left);
        if (node -> right != NULL)
             dfs(v,node->right);
    }
    
    void solve (vector < int > & v , int l , int r , TreeNode* node)
    {
        // Solve every sub problem
        int mid = (l + r) >> 1;
        node -> val = v[mid];
        
        if (r - l == 0)
        {
            return;
        }
        else if (r - l  == 1)
        {
            node -> right = new TreeNode(); 
            solve (v , mid + 1 , r , node -> right);
        }
        else 
        {
             node -> right = new TreeNode(); 
             solve (v , mid + 1 , r , node -> right);
             node -> left = new TreeNode(); 
             solve (v , l , mid - 1 , node -> left);
        }
    }
    
    TreeNode* balanceBST(TreeNode* root) {
        vector < int > v;
        dfs(v , root);
        sort(v.begin() , v.end());
        
        TreeNode* root2 = new TreeNode();
        
        solve(v , 0 , v.size() - 1 , root2);
        
        return root2;
    }
};