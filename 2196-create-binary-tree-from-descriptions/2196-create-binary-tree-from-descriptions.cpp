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
    TreeNode* createBinaryTree(vector<vector<int>>& des) {
        
        // Build an adj. list.
        unordered_map < int , bool > isNotRoot;
        unordered_map < int , TreeNode*> mp;
        for (auto it : des)
        {
            isNotRoot[it[1]] = 1;
            if (!mp.count(it[0]))
                mp[it[0]] = new TreeNode(it[0]);
            if (!mp.count(it[1]))
                mp[it[1]] = new TreeNode(it[1]);
        }
            
        // We want to define the root.
        int Root = -1;
        for (auto it : des)
        {
            if (isNotRoot[it[0]] == 0)
            {
                Root = it[0];
                break;
            } 
        }
        
        for (auto it : des)
        {
            if (it[2])
                mp[it[0]] -> left = mp[it[1]];
            else
                mp[it[0]] -> right = mp[it[1]];
        }
        
        return mp[Root];
    }
};