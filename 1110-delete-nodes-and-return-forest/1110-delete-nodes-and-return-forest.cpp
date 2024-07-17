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
    
    void dfs (TreeNode* node, TreeNode *parent, bool IsLeft , bool isRoot, set < int > &st, vector < TreeNode* > & ans)
    {
        if (isRoot and !st.count(node -> val))
            ans.push_back(node);
        
        bool MustDeleted = st.count(node -> val);
        
        if (node -> left != nullptr)
            dfs(node -> left, node, 1 , MustDeleted, st, ans);
        
        if (node -> right != nullptr)
            dfs(node -> right, node, 0, MustDeleted, st, ans);
        
        if (MustDeleted)
        {
            if (parent != nullptr)
            {
                if (IsLeft)
                    parent -> left = NULL;
                else
                    parent -> right = NULL;
            }
        }     
    }
    
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        set < int > st;
        for (auto it : to_delete)
            st.insert(it);
        
        vector < TreeNode* > ans;
        dfs(root, nullptr, 0, 1 , st, ans);
        
        return ans;
    }
};