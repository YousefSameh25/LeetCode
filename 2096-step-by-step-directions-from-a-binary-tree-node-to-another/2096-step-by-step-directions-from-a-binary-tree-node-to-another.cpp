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
    string path;
    void dfs (TreeNode* root , int tar , string &p)
    {
        if (root -> val == tar)
        {
            path = p;
            return;
        }
        
        if (root -> left != nullptr)
        {
            p.push_back('L');
            dfs(root -> left, tar, p);
            p.pop_back();
        }
        
        if (root -> right != nullptr)
        {
            p.push_back('R');
            dfs(root -> right, tar, p);
            p.pop_back();
        }  
        
    }
    
    
    
    string getDirections(TreeNode* root, int startValue, int destValue) {
        string p1, p2;
        dfs(root, startValue, p1);
        p1 = path;
        
        dfs(root, destValue, p2);
        p2 = path;
                
        int i = 0;
        while (i < p1.size() and i < p2.size() and p1[i] == p2[i])
            i++;
                
        string ret;
        
        for (int j = i; j < p1.size() ; j++)
            ret.push_back('U');
        
        for (int j = i; j < p2.size() ; j++)
            ret.push_back(p2[j]);
        
        return ret;
    }
};