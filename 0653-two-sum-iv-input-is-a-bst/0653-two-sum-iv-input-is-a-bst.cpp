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
    bool findTarget(TreeNode* root, int k) 
    { 
        if (root == NULL)
            return false;
        
        queue < TreeNode* > q;
        q.push (root);
        vector < int > v;
        while(q.size())
        {
            TreeNode* node = q.front();
            q.pop();
            if (node == NULL)
                continue;
            v.push_back(node->val);
            q.push(node->left);
            q.push(node->right);
        }
        
        sort(v.begin() , v.end());
        
        int l = 0 , r = v.size() - 1; 
        while (l <= r)
        {
            if (v[l] + v[r] == k)
                return (l != r);
            
            if (v[l] + v[r] > k)
                r--;
            else
                l++;
        }
        return false;
    }
};