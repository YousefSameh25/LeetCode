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
        vector < vector < int > > G[100000 + 10];
        unordered_map < int , bool > isNotRoot;
        for (auto it : des)
        {
            isNotRoot[it[1]] = 1;
            G[it[0]].push_back({it[1], it[2]});
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
        
        TreeNode* root = new TreeNode(Root);
        TreeNode* ret = root;
        
        // BFS
        queue < TreeNode* > q;
        q.push(root);
        
        
        while(q.size())
        {
            auto it = q.front();
            q.pop();
            
            for (auto it2 : G[it -> val])
            {
                int child = it2[0], left = it2[1];
                if (left)
                {
                    it -> left = new TreeNode(child);
                    q.push(it -> left);
                }
                else
                {
                    it -> right = new TreeNode(child);
                    q.push(it -> right);
                } 
            }
        }
        
        return ret;
    }
};